#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 999999


int main (int argc, char *argv[]){

  int prime_numbers[MAX_SIZE];
  int i, j, k;
  int end_val = atoi(argv[1]);
  int len = sizeof(prime_numbers)/sizeof(int);

  //if number is less than 2, no need to calculate
  if(end_val < 2){
    printf("No prime number\n");
    return 0;
  }

  //Inıtıal prime numbers
  prime_numbers[0]=2;
  prime_numbers[1]=3;
  prime_numbers[2]=5;
  prime_numbers[3]=7;

  //Output file
  FILE *fp = fopen("output.txt", "w+");

  int array_counter = 4;


  #pragma omp parallel for num_threads(5) shared(prime_numbers,array_counter) private(j) schedule(dynamic,4)
  for(i=2; i<end_val; i++){

    int tid = omp_get_thread_num();

    for(j=0; j<len; j++){

      if(prime_numbers[j] == NULL){
          //print out to screen and file
          fprintf(stderr,"Thread ID : %d \t Value : %d\n",tid,i);
          fprintf(fp, "Thread ID : %d \t Value : %d\n",tid,i);
          #pragma omp critical(insert_array)
          {
            //insert prime number to array and increase array counter
            prime_numbers[array_counter] = i;
            array_counter += 1;
          }

      }

      if( i % prime_numbers[j] == 0)//if numbers divides without remaining, number is not prime
        break;

    }

  }

  //printing inital prime numbers
  for (i = 0; i < 3; i++) {
    if(prime_numbers[i] >= end_val)
      break;
    else
      fprintf(fp, "Inıtial prime number : %d\n", prime_numbers[i]);
      printf("Inıtial prime number : %d\n", prime_numbers[i]);
  }

  return 0;
}
