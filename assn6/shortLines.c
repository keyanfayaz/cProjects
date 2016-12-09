#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/*
 * Keyan Fayaz - 14kf34
 * Student #: 10188190
 *
 * CISC220: Assignment 6
 * Fall 2016, M. Lamb
 */

int main(int argc, char *argv[]) {
  
  int size = atoi(argv[3]);
  printf("3rd arg is: %d\n", size);
  
  FILE *f1 = fopen(argv[1], "r"); // Read from first file
  FILE *f2 = fopen(argv[2], "w"); // Write to second file
  
  if (f1 == NULL || f2 == NULL) {
    perror("\nThere was an error in processing the files.\n");
    exit(1);
  }
  
  char line[size];

  int done = 0;
  while (!done) {
    char *content = fgets(line, size+1, f1);
    if (content == NULL) {
      if (errno == 0) {
	done = 1; // If end of file reached
      } else {
	perror("Error while reading the input file\n");
	exit(1);
      }
    }

    if (!done) {
    printf("input line: \"%s\"\n", line);
    fputs(line, f2);
    }
  }


  fclose(f1);
  fclose(f2);
  return 0;
}
