#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
 
int main(int argc, char* argv[])
{

    volatile int dummy = 1;

    MPI_Init(&argc, &argv);
 
    // Check that the application is run with 1 processes.
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 1)
    {
        printf("Please run this application with 6 MPI processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
 
    //while (dummy) {};

    // Get my rank in the global communicator
    int my_rank_global;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank_global);
 
    // Get the group or processes of the default communicator
    MPI_Group world_group;
    MPI_Comm_group(MPI_COMM_WORLD, &world_group);
 
    // Create the new communicator from that group of processes.
    MPI_Comm local_communicator;
 
    // Only MPI process 0 remains, without a group
    MPI_Comm_create(MPI_COMM_WORLD, MPI_GROUP_EMPTY, &local_communicator);
 
    MPI_Finalize();
 
    return EXIT_SUCCESS;
}


