#/bin/bash
objcopy  --redefine-sym _Z10place_wordPPciNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEcii=foo solution.o test5.o
clang++ -g -DTEST -DPW wordsearch.cpp test5.o test_place_word.cpp -o test5
./test5 1234
if [ $? -eq 0 ]
then
  echo "Passed place_word() test."
  exit 0
else
  echo "Failed place_word() test."
  exit 1
fi
