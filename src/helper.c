/*
  Copyright (C) 2014 0ip

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "helper.h"

uint64_t *prime_sieve_n_odds(uint64_t n, uint64_t *ctr) {
  // Sieve of Eratosthenes
  // only save odd numbers
  uint64_t mem = (n-1)/2;
  *ctr = 1;

  uint64_t i, j;

   // calloc initializes to zero, inverse logic below
  bool *array = calloc((mem+1), sizeof(bool));

  for (i = 3; i * i <= n; i += 2)
    if (array[i/2] == false)
      for (j = i * i; j <= n; j += i * 2)
        array[j/2] = true;

  for (i = 1; i <= mem; ++i)
    if (array[i] == false) ++(*ctr);

  uint64_t *primes = malloc((*ctr + 1) * sizeof(uint64_t));
  primes[0] = 2;
  j = 1;
  for (i = 1; i <= mem; ++i)
    if (array[i] == false) primes[j++] = 2*i+1;

  free(array);
  return primes;
}


uint64_t *prime_sieve_n(uint64_t n, uint64_t *ctr) {
  // Sieve of Eratosthenes
  uint64_t i, j, prime, multiple;

  *ctr = n - 1;

   // calloc initializes to zero, inverse logic below
  bool *array = calloc(n + 1, sizeof(bool));

  for (prime = 2; prime * prime <= n; prime++) {
    if (array[prime] == false)
      for (multiple = prime*prime; multiple <= n; multiple += prime)
        if (array[multiple] == false) {
          array[multiple] = true;
          --(*ctr);
        }
  }

  j = 0;
  uint64_t *pr = calloc(*ctr + 1, sizeof(uint64_t));
  for (i = 2; i <= n; ++i) {
    if (array[i] == false) pr[j++] = i;
  }

  free(array);
  return pr;
}

bool is_prime_trial(uint64_t n) {
  if (n < 2) return false;
  uint64_t i;
  for (i = 2; i * i <= n; ++i) if (n % i == 0) return false;
  return true;
}

bool is_prime_fast(uint64_t n, uint64_t *sieve, uint64_t found) {
  uint64_t i;
  for (i = 0; i < found; ++i)
    if (sieve[i] == n) return true;
  return false;
}

uint64_t reverse_digits(uint64_t n) {
  uint64_t tmp = 0;
  while (n > 0) {
    tmp += n % 10;
    if (n > 9) tmp *= 10;
    n /= 10;
  };
  return tmp;
};

bool is_palindrome(uint64_t n, int base) {
  int reversed = 0;
  int k = n;

  while (k > 0) {
      reversed = base * reversed + k % base;
      k /= base;
  }
  return n == reversed;
}

uint64_t count_factors(uint64_t n, uint64_t *sieve, uint64_t found) {
  uint64_t divi      = 0;
  uint64_t factors   = 1;
  uint64_t c_exp = 0;

  while (n > 1) {
    if (n % sieve[divi] == 0) {
      n /= sieve[divi];
      c_exp++;
    } else {
      if (divi++ > found - 1) return 0;
      factors *= (c_exp + 1);
      c_exp = 0;
    }
  }
  factors *= (c_exp + 1);
  
  return factors;
}

uint64_t gcd(uint64_t u, uint64_t v)
{
  int shift;
 
  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
 
  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
     u >>= 1;
     v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  /* From here on, u is always odd. */
  do {
   /* remove all factors of 2 in v -- they are not common */
   /*   note: v is not zero, so while will terminate */
   while ((v & 1) == 0)  /* Loop X */
       v >>= 1;

   /* Now u and v are both odd. Swap if necessary so u <= v,
      then set v = v - u (which is even). For bignums, the
      swapping is just pointer movement, and the subtraction
      can be done in-place. */
   if (u > v) {
    unsigned int t = v; v = u; u = t;}  // Swap u and v.
   v = v - u;                       // Here v >= u.
  } while (v != 0);
 
  /* restore common factors of 2 */
  return u << shift;
}

uint64_t phi(uint64_t n, uint64_t *sieve, uint64_t found) {
  // Base case
  if ( n < 2 )
    return 0;

  // Lehmer's conjecture
  if (is_prime_fast(n, sieve, found)) {
    return n - 1;
  }

  // Even number?
  if ((n & 1) == 0) {
    int m = n >> 1;
    return !(m & 1) ? phi(m, sieve, found)<<1 : 
                      phi(m, sieve, found);
  }

  // For all primes
  for (uint64_t p = 0; p <= n; ++p) {
    if (p > found - 1) return 0;
    uint64_t m = sieve[p];
    if ( n % m  ) continue;

    // phi is multiplicative
    uint64_t o = n/m;
    uint64_t d = gcd(m, o);
    return d==1? phi(m, sieve, found) * phi(o, sieve, found) : 
                 phi(m, sieve, found) * phi(o, sieve, found) * d/phi(d, sieve, found);
  }
  return 0;
}

uint64_t triangle(uint64_t N) {
  return .5*(N*N+N);
}

uint64_t max(uint64_t a, uint64_t b) {
  if (a > b) return a;
  return b;
}

int max_int(int a, int b) {
  if (a > b) return a;
  return b;
}

uint64_t min(uint64_t a, uint64_t b) {
  if (a < b) return a;
  return b;
}

int min_int(int a, int b) {
  if (a > b) return a;
  return b;
}