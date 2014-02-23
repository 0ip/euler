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


  Make: gcc helper.c 69.c -o 69 -std=c99 -O3 -Wall
*/

#include "helper.h"

int main(int argc, char const *argv[])
{
  uint64_t found;
  uint64_t *ptr = prime_sieve_n_odds(1000000, &found);
  printf("Sieving done.\n");

  uint64_t i = 0;
  uint64_t result = 1;

  while (result * ptr[i] < 1000000) {
    result *= ptr[i];
    i++;
  }

  printf("Found it! %llu\n", result);
  
  return 0;
}