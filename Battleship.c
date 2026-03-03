/*
File: Battleship.c
Authors: Aidan Monsen and Ikaikaokealohilani Ofsthun
Purpose: Recreat Battleship in C
Version: 1.0 Feb 24, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
      char so1, so2, so3, sy1, sy2, sy3;
      int sx1, sx2, sx3;

      printf("Enter the orientation of your 4 ship (v/h): ");
      scanf(" %c", &so1);

      printf("Enter the starting x coordinate of your 4 ship: ");
      scanf("%d", &sx1);
      // check to see if ship is horizontal and unable to fit on board
      
}

void toProperCase(char *str)
{
      int i;
      for (i = 0; str[i]; i++)
      {
          str[i] = tolower(str[i]);
      }
      str[0] = toupper(str[0]);
}
