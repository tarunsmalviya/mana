#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct CartesianTopology {
  int old_comm_size;
  int new_comm_size;
  int old_rank, new_rank;
  int *coordinates;
  int number_of_dimensions;
  int *dimensions;
  int *periods;
  int reorder;
} CartesianTopology;

void load(char *filename, CartesianTopology *ct)
{
  int i;

  int fd = open(filename, O_RDONLY);
  if (fd == -1)
    return;

  read(fd, &ct->old_comm_size, sizeof(int));
  read(fd, &ct->new_comm_size, sizeof(int));
  read(fd, &ct->old_rank, sizeof(int));
  read(fd, &ct->new_rank, sizeof(int));
  read(fd, &ct->reorder, sizeof(int));
  read(fd, &ct->number_of_dimensions, sizeof(int));

  ct->coordinates = (int *) malloc(sizeof(int) * ct->number_of_dimensions);
  for (i = 0; i < ct->number_of_dimensions; i++)
    read(fd, &ct->coordinates[i], sizeof(int));

  ct->dimensions = (int *) malloc(sizeof(int) * ct->number_of_dimensions);
  for (i = 0; i < ct->number_of_dimensions; i++)
    read(fd, &ct->dimensions[i], sizeof(int));

  ct->periods = (int *) malloc(sizeof(int) * ct->number_of_dimensions);
  for (i = 0; i < ct->number_of_dimensions; i++)
    read(fd, &ct->periods[i], sizeof(int));

  close(fd);
}

void print(CartesianTopology *ct)
{
    int i;

    if (ct == NULL)
       	return;

    printf("\n\nCartesian Topology Details\n\n");

    printf("\nOld Comm Size: %d", ct->old_comm_size);
    printf("\nNew Comm Size: %d", ct->new_comm_size);
    printf("\nOld Rank: %d", ct -> old_rank);
    printf("\nNew Rank: %d", ct -> new_rank);
    printf("\nReorder: %d", ct -> reorder);
    printf("\nNumber of Dimensions: %d", ct -> number_of_dimensions);

    printf("\nCoordinates: ");
    for (i = 0; i < ct -> number_of_dimensions; i++)
        printf("%d, ", ct -> coordinates[i]);

    printf("\nDimensions: ");
    for	(i = 0; i < ct -> number_of_dimensions; i++)
        printf("%d, ", ct -> dimensions[i]);

    printf("\nPeriods: ");
    for	(i = 0; i < ct -> number_of_dimensions; i++)
        printf("%d, ", ct -> periods[i]);

    printf("\n\n");
}

int main()
{
    CartesianTopology ct;

    load("/global/homes/m/malviyat/codes/ckpt_rank_1/cartesian.info", &ct);
    print(&ct);

    return 0;
}
