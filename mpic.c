#include <mpi.h>
#include <stdio.h>

int main(int argc, char ** argv) {
int rank, data=4;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
if(rank == 0) MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
else if(rank == 1) {
	MPI_Recv(
