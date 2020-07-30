#/bin/bash
rm -rf print.txt
objcopy  --redefine-sym _Z12print_puzzlePPci=foo solution.o test4.o
clang++ -DTEST -DPP wordsearch.cpp test4.o test_print_puzzle.cpp -o test4
./test4 1234 > print.txt
echo "The top (reference) and bottom (your code) should match:"
cat print.txt
TOP=`head -n 5 print.txt`
BOT=`tail -n 5 print.txt`

if [ "$TOP" = "$BOT" ]
then
  echo "Passed print_puzzle() test."
  rm -rf print.txt
  exit 0
else
  echo "Failed print_puzzle() test."
  rm -rf print.txt
  exit 1
fi


