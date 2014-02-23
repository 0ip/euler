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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint64_t *prime_sieve_n_odds(uint64_t n, uint64_t *ctr);
uint64_t *prime_sieve_n(uint64_t n, uint64_t *ctr); // == SOE
bool is_prime_trial(uint64_t n);
bool is_prime_fast(uint64_t n, uint64_t *sieve, uint64_t found); // req. SOE
uint64_t count_factors(uint64_t n, uint64_t *sieve, uint64_t found); // req. SOE

uint64_t gcd(uint64_t u, uint64_t v);
uint64_t phi(uint64_t n, uint64_t *sieve, uint64_t found); // req. SOE

uint64_t triangle(uint64_t N);

uint64_t max(uint64_t a, uint64_t b);
int max_int(int a, int b);
uint64_t min(uint64_t a, uint64_t b);
int min_int(int a, int b);

uint64_t reverse_digits(uint64_t n);
bool is_palindrome(uint64_t n, int base);

bool is_pandigital(uint64_t n);