#/bin/bash
objcopy  --redefine-sym _Z13random_puzzlePPci=foo solution.o test3.o
clang++ -DTEST -DRP wordsearch.cpp test3.o test_random_puzzle.cpp -o test3
./test3 1234
if [ $? -eq 0 ]
then
  echo "Passed random_puzzle() test."
  exit 0
else
  echo "Failed random_puzzle() test."
  exit 1
fi
