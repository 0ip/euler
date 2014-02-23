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

#define LINES 100

int findMaxSumTriangle(int tri[LINES][LINES]) {
  for (int i = LINES - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      tri[i][j] += max_int(tri[i+1][j], tri[i+1][j+1]);
    }
  }
  return tri[0][0];
}

void loadTriangleFromFile(char fileName[], int dest[LINES][LINES]) {
  FILE *input = fopen(fileName, "r");
  int i, j;
  for(i = 0; i < LINES; i++) {
    for(j = 0; j <= i; j++) {
      fscanf(input, "%d", &dest[i][j]);
    }
  }
  fclose(input);
}

int main(int argc, const char *argv[]) {
  int triangle[LINES][LINES];

  loadTriangleFromFile("res\\triangle.txt", triangle);
  printf("%d\n", findMaxSumTriangle(triangle));

  return 0;
}
