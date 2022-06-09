#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <string.h>


int itoa2(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return 0; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	int len = 0;
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		len++;
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return len;
}

int
get_rank_corresponding_to_coordinates(int world_size,
                                      int number_of_dimensions,
                                      int *coords)
{
  int i;
  char tmp[10], filename[40];

  for (int i = 0; i < world_size; i++) {
    // sprintf(filename, "./ckpt_rank_%d/cartesian.info", i);
    // printf("\n%s", filename);

    strcpy(filename, "./ckpt_rank_");
    itoa2(i, tmp, 10);
    strncat(filename, tmp, 9);
    strncat(filename, "/cartesian.info", 20);
    printf("\n%s", filename);
  }

  printf("\n");

  return -1;
}

int main(void) {

#if 0
  char num[10];
  itoa2(12, num, 10);
  printf("\n%s\n", num);
#endif

#if 1
  get_rank_corresponding_to_coordinates(20, 2, NULL);
#endif

#if 0

  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

#endif

  return 0;
}
