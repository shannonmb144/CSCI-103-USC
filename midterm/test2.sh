#/bin/bash
objcopy  --redefine-sym _Z10new_puzzlei=foo solution.o test2.o
clang++ -DTEST -DNP wordsearch.cpp test2.o test_new_puzzle.cpp -o test2
./test2
if [ $? -eq 0 ]
then
  echo "Passed new_puzzle() test."
  exit 0
else
  echo "Failed new_puzzle() test."
  exit 1
fi
