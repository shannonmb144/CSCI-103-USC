#/bin/bash
objcopy  --redefine-sym _Z11search_wordPPciNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEPiS7_S_=foo solution.o test8.o
clang++ -g -DTEST -DSW wordsearch.cpp test8.o test_search_word.cpp -o test8
./test8 1234
if [ $? -eq 0 ]
then
  echo "Passed search_word() test."
  exit 0
else
  echo "Failed search_word() test."
  exit 1
fi