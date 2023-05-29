mpirun -np 2 --allow-run-as-root ./src/word_count.out ./words 

cp words_counted.txt twoprocess.txt

for i in {5..100..5}
do
  echo "Checking with $i processors"

   mpirun -np $i --allow-run-as-root ./src/word_count.out ./words 

  if [[ $(diff <(sort twoprocess.txt) <(sort words_counted.txt)) ]]; then
        echo "Differences found."
    else
        echo "No differences found."
    fi

done




