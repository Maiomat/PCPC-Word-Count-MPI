echo "Start"
echo "Start test" > logfile.txt
for i in {2..24..1}
do
  echo "Run with $i processors" >> logfile.txt
  mpirun -np $i --allow-run-as-root ./src/word_count.out ./words >> logfile.txt
done
echo "End"