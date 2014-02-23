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

int main(int argc, char const *argv[])
{

  uint64_t sum = 0;

  for (uint64_t i = 1; i < 1000000; ++i) {
    if (is_palindrome(i, 10) && is_palindrome(i, 2)) sum += i;
  }
  
  printf("Sum: %llu\n", sum);

  return 0;
}