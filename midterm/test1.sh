#/bin/bash
objcopy --redefine-sym _Z13random_letterv=foo solution.o test1.o
clang++ -DTEST -DRL wordsearch.cpp test1.o test_random_letter.cpp -o test1
./test1 1234
if [ $? -eq 0 ]
then
  echo "Passed random_letter() test."
  exit 0
else
  echo "Failed random_letter() test."
  exit 1
fi
