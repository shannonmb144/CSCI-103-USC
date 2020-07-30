#!/usr/bin/env python

'''
Usage: ./gen_web.py 1000 3 graph_1000_3_random.txt
'''

'''
Examples:
./gen_web.py -N 4 -s 1 -o mygraph.txt -g
./gen_web.py -N 20 -s 1 -o graph_20_1_random.txt -g
./gen_web.py -N 4 -s 1 -o mygraph_r.txt -g -r

'''

import sys
import random
import string
import math
import argparse
from subprocess import PIPE,Popen
D = ['com','edu','mil','gov','net']
def random_url():
  #Generate 
  N = int(random.gauss(5,2))
  domain = ''.join(random.choice(string.ascii_lowercase + string.digits) for _ in range(N)) + "." + random.sample(D,1)[0]
  return domain

def zipf_out(N,s,goutput,visualize):
  sum = 0.0
  pages = {}
  #Create the pages
  for r in range(1,N+1):
    pages[r-1] = random_url()
    sum += (1/r**s)

  if visualize: 
    if goutput.find(".txt") == -1:
      output = goutput + ".png"
    else: output = goutput[:goutput.find(".txt")] + ".png"      
    dotP = Popen(["dot","-Tpng","-o",output],stdin=PIPE)
    print >> dotP.stdin,"digraph G{"

  with open(goutput,"w") as f:
    print >> f,N
    for r,p in enumerate(pages,start=1):
      freq = (1/r**s) / sum
      print >>f,p #ID
      print >>f,"\t{}".format(pages[p] ) #url
      print >>f,"\t0.0"
      n= int(math.ceil(freq*N)) 
      #print >>f, "\t" + ' '.join([str(x) for x in random.sample(pages.keys(),n)] )
      keys = pages.keys()
      keys.remove(p)
      links = [str(x) for x in random.sample(keys,n)]
      print >>f, "\t" + ' '.join(links )
      if visualize:
        for n in links: print >> dotP.stdin, "\"id:{}\n{}\" -> \"id:{}\n{}\"; ".format(p,pages[p],int(n),pages[int(n)])
      #print freq*N
  if visualize:    
    print >> dotP.stdin, "}"

def zipf_in(N,s,goutput,visualize):
  sum = 0.0
  pages = {}
  #Create the pages
  for r in range(1,N+1):
    pages[r-1] = [random_url(),[]]
    sum += (1/r**s)
  for r,p in enumerate(pages,start=1):
      freq = (1/r**s) / sum
      n= int(math.ceil(freq*N)) 
      keys = pages.keys()
      keys.remove(p)
      for x in random.sample(keys ,n ):
        pages[x][1].append(p)
 
  if visualize: 
    if goutput.find(".txt") == -1:
      output = goutput + ".png"
    else: output = goutput[:goutput.find(".txt")] + ".png"      
    dotP = Popen(["dot","-Tpng","-o",output],stdin=PIPE)
    print >> dotP.stdin,"digraph G{"

  #Fix pages that doesn't have out links
  for p in sorted(pages,key=lambda x: len(pages[x][1]) ):
    if len(pages[p][1]) >0 :
      break
    k = pages.keys()
    k.remove(p)
    pages[p][1].extend( random.sample(k,1) )      
    #print "{} -> {}".format(p,pages[p])
  with open(goutput,"w") as f:
    print >> f,N
    for r,p in enumerate(pages,start=1):
      freq = (1/r**s) / sum
      print >>f,p #ID
      print >>f,"\t{}".format(pages[p][0] ) #url
      print >>f,"\t0.0"
      n= int(math.ceil(freq*N)) 
      #print >>f, "\t" + ' '.join([str(x) for x in random.sample(pages.keys(),n)] )
      links = [str(x) for x in pages[p][1]]
      print >>f, "\t" + ' '.join(links )
      if visualize:
        for l in pages[p][1]:
          print >> dotP.stdin, "\"id:{}\n{}\" -> \"id:{}\n{}\"; ".format(p,pages[p][0],l,pages[l][0])

  if visualize:    
    print >> dotP.stdin, "}"



def main():

  parser = argparse.ArgumentParser()
  parser.add_argument("-N",help="Number of pages",required=True)
  parser.add_argument("-s",help="Exponent for zipf formula. Data spreadness",
    required=True)
  parser.add_argument("-o",help="Graph outputfile",required=True)
  parser.add_argument("-g",help="Generate a visual graph",action="store_true")
  parser.add_argument("-r",help="Apply zipf to the backlinks",action="store_true")

  args = parser.parse_args()
  N = int(args.N) 
  s = float(args.s) #s be the value of the exponent characterizing 
                    #the distribution. How spread is the data
  goutput = args.o
  visualize = False

  if args.g:
    visualize = True  

  if args.r:
    zipf_in(N,s,goutput,visualize)
  else:
    zipf_out(N,s,goutput,visualize)
if __name__ == "__main__":
  main()
