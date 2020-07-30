#/bin/bash
objcopy  --redefine-sym _Z10load_wordsPPciPKc=foo solution.o test6.o
clang++ -DTEST -DLW wordsearch.cpp test6.o test_load_words.cpp -o test6
./test6 1234
if [ $? -eq 0 ]
then
  echo "Passed load_words() test."
  exit 0
else
  echo "Failed load_words() test."
  exit 1
fi
