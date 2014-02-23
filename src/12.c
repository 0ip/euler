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


  Make: gcc helper.c 12.c -o 12 -std=c99 -O3 -Wall
*/

#include "helper.h"

int main(int argc, const char *argv[]) {
  unsigned int limit = 500;
  unsigned int factors = 0;
  uint64_t running = 1;

  if (argc > 1) limit = atoi(argv[1]);
  printf("Limit: %d\n", limit);

  uint64_t found;
  uint64_t *ptr = prime_sieve_n_odds(10000000, &found);
  
  while (factors < limit) {
    factors = count_factors(triangle(running), ptr, found);
    running++;
  };
  running--;

  printf("Found it! Nth: %lld Value: %lld\n", running, triangle(running));

  return 0;
}