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


  Make: gcc helper.c 41.c -o 41 -std=c99 -O3 -Wall
*/

#include "helper.h"

int main()
{
  uint64_t found;
  uint64_t *arr = prime_sieve_n_odds(987654321, &found);

  printf("Done sieving. Largest: %llu\n", arr[found-1]);

  uint64_t j = 0;
  for (uint64_t i = found - 1; i >= 0; i--)
  {
    if (is_pandigital(arr[i])) {
      printf("Found it! %llu\n", arr[i]);
      break;
    }
  }

  return 0;
}
