#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * @brief Check whether the given number is prime.
 * @param num A positive integer.
 * @return num itself if prime, the first encountered divisor otherwise.
*/
long prime(long num) {
  long ret = num;
  if (num > 2) {
    for (long i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        ret = i;
        break;
      }
    }
  }
  return ret;
}

/**
 * @brief Flags up all the prime numbers from 0 to num.
 * @param num A positive integer.
 * @return An array where each element is 0 if the
 *         corresponding index is not prime, else 1.
 */
unsigned short* flag_primes(long num) {
    unsigned short* primes = (unsigned short*) malloc((num+1) * sizeof(unsigned short));
    memset(primes, 0, (num+1) * sizeof(unsigned short));

    for (long i = 0; i < num + 1; i++) {
        if (prime(i) == i) {
            primes[i] = 1;
        }
    }
    return primes;
}


int main() {
  long guess;
  long divisor;

  printf("Please insert a positive number: ");

  if (scanf("%ld", &guess) != 1 || guess <= 0) {
    fprintf(stderr, "Invalid number provided!\n");
    return 1;
  }

  if ((divisor = prime(guess)) == guess)
    printf("The provided number is prime!\n");
  else
    printf("The provided number can be divided by %ld!\n", divisor);

  printf("Prime numbers between 1 and %d:", guess);
  const unsigned short* primes = flag_primes(guess);
  for(int i = 1 ; i <= guess; i++) {
      if (primes[i] == 1) {
          printf(" %d", i);
      }
  }
  putchar('\n');
  free((unsigned short*) primes);
  return 0;
}
