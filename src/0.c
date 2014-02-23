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


  Make: gcc src/helper.c src/0.c -o bin/0 -std=c99 -O3 -Wall
*/

#include "helper.h"
#include <time.h>

int main(int argc, char const *argv[])
{

  printf("Starting tests...\n\n");

  clock_t begin, end;
  begin = clock();


  uint64_t found;
  uint64_t *ptr = prime_sieve_n_odds(1000000000, &found);

  printf("Found primes: %llu\n", found);
  if (found == 50847534) printf("Test passed.\n\n");
  else printf("Test failed.\n\n");

  printf("Largest prime: %llu\n", ptr[found-1]);
  if (ptr[found-1] == 999999937) printf("Test passed.\n\n");
  else printf("Test failed.\n\n");

  printf("Phi(12344234) = %llu\n", phi(12344234, ptr, found));
  if (phi(12344234, ptr, found) == 5277552) printf("Test passed.\n\n");
  else printf("Test failed.\n\n");

  printf("Done.\n");


  end = clock();
  printf("Time spent: %.3f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  return 0;
}