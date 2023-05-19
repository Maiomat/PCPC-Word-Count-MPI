#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

int main( int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    double start, end;
    start = MPI_Wtime();
    printf("Rank: %d/%d\n", rank, size);
    
    MPI_Finalize();
    end = MPI_Wtime();
    
    if(rank == 0)
         printf("Time in ms = %f\n", end-start);
    
    return 0;
}