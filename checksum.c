/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;
  int quotient;
  int remainder;   
  byte checksum; 
  byte complement;

  byte header[10];

  read(STDIN_FILENO, &header, 10);  

  for (int i = 1; i<= count; i++){
    if(i == 6){
      checksum = header[i-1];
      header[i-1] = 0;
    }
    sum += header[i-1];
  }
  quotient = sum/(max_int + 1);
  remainder = sum%(max_int + 1);
  sum = quotient + remainder;
  complement = max_int - sum;



  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}