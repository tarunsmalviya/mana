#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <mpi.h>

int main(int argc, char* argv[])
{

#if 0
    volatile int dummy = 1;
    while(dummy) {};
#endif

    MPI_Init(&argc, &argv);

    int i = 0; 
    int b_world_size = -1, a_world_size = -1;
    int b_world_rank = -1, a_world_rank = -1;
    int b_cart_rank = -1, a_cart_rank = -1;
    int b_coords[2] = {-1, -1}, a_coords[2] = {-1, -1};

    // *************** BEFORE ***************
    // Size of the default communicator
    MPI_Comm_size(MPI_COMM_WORLD, &b_world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &b_world_rank);

    // Ask MPI to decompose our processes in a 2D cartesian grid for us
    int dims[2] = {1, 2};
    //MPI_Dims_create(size, 2, dims);

    // Make both dimensions periodic
    int periods[2] = {true, true};

    // Let MPI assign arbitrary ranks if it deems it necessary
    int reorder = true;

    // Create a communicator given the 2D torus topology.
    MPI_Comm new_communicator;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, reorder, &new_communicator);

    // My rank in the new communicator
    MPI_Comm_rank(new_communicator, &b_cart_rank);

    // Get my coordinates in the new communicator
    MPI_Cart_coords(new_communicator, b_cart_rank, 2, b_coords);

    printf("\nBEFORE [%d] -> World Size: %d | World Rank: %d | Cart Rank: %d | Coordinates: (%d, %d)\n", getppid(), b_world_size, b_world_rank, b_cart_rank, b_coords[0], b_coords[1]);
    printf("Sleeping for 50 seconds; Checkpoint now!\n");
    fflush(stdout);

    sleep(500);

    printf("Done with the sleep; resuming now!\n");
    fflush(stdout);
    // *************** AFTER ***************
    // Size of the default communicator
    MPI_Comm_size(MPI_COMM_WORLD, &a_world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &a_world_rank);

    // My rank in the new communicator
    MPI_Comm_rank(new_communicator, &a_cart_rank);

    // Get my coordinates in the new communicator
    MPI_Cart_coords(new_communicator, a_cart_rank, 2, a_coords);

    printf("\nBEFORE [%d] -> World Size: %d | World Rank: %d | Cart Rank: %d | Coordinates: (%d, %d)\n", getppid(), b_world_size, b_world_rank, b_cart_rank, b_coords[0], b_coords[1]);
    printf("\nAFTER [%d] -> World Size: %d | World Rank: %d | Cart Rank: %d | Coordinates: (%d, %d)\n", getppid(), a_world_size, a_world_rank, a_cart_rank, a_coords[0], a_coords[1]);
    fflush(stdout);

    MPI_Finalize();

    return EXIT_SUCCESS;

}
