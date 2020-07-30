#/bin/bash
objcopy  --redefine-sym _Z9find_wordPPciNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEcii=foo solution.o test7.o
clang++ -g -DTEST -DFW wordsearch.cpp test7.o test_find_word.cpp -o test7
./test7 1234
if [ $? -eq 0 ]
then
  echo "Passed find_word() test."
  exit 0
else
  echo "Failed find_word() test."
  exit 1
fi