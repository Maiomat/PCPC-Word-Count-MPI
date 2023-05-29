mpirun -np 2 --allow-run-as-root ./src/word_count.out ./words 

cp words_counted.txt twoprocess.txt

sort -o twoprocess.txt twoprocess.txt
sort -o words_counted.txt words_counted.txt

for i in {5..100..5}
do
  echo "Checking with $i processors"

   mpirun -np $i --allow-run-as-root ./src/word_count.out ./words 

   sort -o words_counted.txt words_counted.txt

  if ! cmp -s twoprocess.txt words_counted.txt; then
        echo "Differences found."
    else
        echo "No differences found."
    fi

done