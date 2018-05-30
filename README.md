# Prime-Number-Finder
Implementation of Prime Numbers Using OpenMP

A program that takes a number “n” as input and calculates all the prime numbers less than n.

# Programming Details

We are using an array to store found prime numbers. So we are initially adding first 4 prime
numbers (2, 3, 5, and 7) into this array.<br/>
And we take an input from user by command line argument. Ex:<br/>
>>“./prime_number.o 100”<br/>
After taking input, we are allocating values to threads with chunk size 4.<br/>
Now threads are starting to check number is prime or not.<br/>
To do that, thread is starting to divide from first prime number to last prime number in
array. If one of these numbers is dividing without residual, number is not prime.<br/>
If the array is finished and there is no number which is divided without a residue, so number
is prime. We are inserting the prime number into array in critical section. And found prime
numbers will be updated.<br/>
All threads doing same operation for its resources.<br/>
Meanwhile if a thread find a prime number, it prints the prime number onto console and an
output file.<br/>
  
You can compile prime_number.c like:<br/>
gcc prime_number.c -o prime_number.o -fopenmp -lm<br/>