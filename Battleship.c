/*
File: Battleship.c
Authors: Aidan Monsen and Ikaikaokealohilani Ofsthun
Purpose: Recreate Battleship in C
Version: 1.2 Mar 10, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void toProperCase(char *str);

void getShip(int length, char *orientation, int *x, char *y);

int main()
{
      char so1, so2, so3, sy1, sy2, sy3;
      int sx1, sx2, sx3;

      getShip(4, &so1, &sx1, &sy1);
      getShip(3, &so2, &sx2, &sy2);
      getShip(2, &so3, &sx3, &sy3);
      
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

void getShip(int length, char *orientation, int *x, char *y)
{

      // Orientation
      do 
      {
          printf("Enter the orientation of your %d length ship (v/h): ", length);
          scanf(" %c", orientation);
          toProperCase(orientation);

          if ((*orientation != 'V') && (*orientation != 'H'))
          {
              printf("Invalid orientation for ship!\n");
          }

      } while ((*orientation != 'V') && (*orientation != 'H'));

      // X coordinate
      do 
      {
          printf("Enter the starting x coordinate of your %d length ship: ", length);
          scanf("%d", x);

          if (*x <= 0 || *x > BOARD_SIZE || (*orientation == 'H' && *x > BOARD_SIZE - length + 1))
          {
              printf("Invalid Position for ship!\n");
          }

      } while (*x <= 0 || *x > 6 || (*orientation == 'H' && *x > BOARD_SIZE - length + 1));
      
      // Y coordinate
      do
      {
          printf("Enter the starting y coordinate of your %d length ship: ", length);
          scanf(" %c", y);
          toProperCase(y);

          if (*y < 'A' || *y > 'A' + BOARD_SIZE - 1 || (*orientation == 'V' && *y > 'A' + BOARD_SIZE - length))
          {
              printf("Invalid Position for ship!\n");
          }

      } while (*y < 'A' || *y > 'A' + BOARD_SIZE - 1 || (*orientation == 'V' && *y > 'A' + BOARD_SIZE - length));

}
