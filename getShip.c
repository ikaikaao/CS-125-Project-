/*
File: getShip.c
Author: Aidan Monsen
Purpose: Get the players ship orientation and position
Version: 1.4 Apr 7, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>

void getShip(int length, char *orientation, int *x, char *y, int Pboard[BOARD_SIZE][BOARD_SIZE])
{
      int i, overlap;
      
      do
      {
          overlap = 0;      

          // Orientation
          do 
          {
              printf("Enter the orientation of your %d length ship (v/h): ", length);
              scanf(" %c", orientation);
              *orientation = toupper(*orientation);
              
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

          } while (*x <= 0 || *x > BOARD_SIZE || (*orientation == 'H' && *x > BOARD_SIZE - length + 1));
          
          // Y coordinate
          do
          {
              printf("Enter the starting y coordinate of your %d length ship: ", length);
              scanf(" %c", y);
              *y = toupper(*y);

              if (*y < 'A' || *y > 'A' + BOARD_SIZE - 1 || (*orientation == 'V' && *y > 'A' + BOARD_SIZE - length))
              {
                  printf("Invalid Position for ship!\n");
              }

          } while (*y < 'A' || *y > 'A' + BOARD_SIZE - 1 || (*orientation == 'V' && *y > 'A' + BOARD_SIZE - length));

          int row = *y - 'A';
          int col = *x - 1;

          // Check overlap
          if (*orientation == 'H')
          {
              for (i = 0; i < length; i++)
              {
                  if (Pboard[row][col + i] == 1)
                  {
                      overlap = 1;
                  }
              }
          }
          
          else
          {
              for (i = 0; i < length; i++)
              {
                  if (Pboard[row + i][col] == 1)
                  {
                      overlap = 1;
                  }
              }
          }

          if (overlap)
          {
              printf("Ships cannot overlap! Try again.\n");
          }

      } while (overlap);

      // Mark ship on board
      int row = *y - 'A';
      int col = *x - 1;

      if (*orientation == 'H')
      {
          for (i = 0; i < length; i++)
          {
              Pboard[row][col + i] = 1;
          }
      }
      else
      {
          for (i = 0; i < length; i++)
          {
              Pboard[row + i][col] = 1;
          }
      }      
}
