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
#include "computerShips.h"
#include "playerShips.h"

void getShip(int length, char *orientation, int *x, char *y, int Pboard[BOARD_SIZE][BOARD_SIZE]);

void printPlayerBoard(int Pboard[BOARD_SIZE][BOARD_SIZE]);

void printEnemyBoard(int Cboard[BOARD_SIZE][BOARD_SIZE]);

int main()
{
      char so1, so2, so3, sy1, sy2, sy3;
      int sx1, sx2, sx3;
      
      int Pboard[BOARD_SIZE][BOARD_SIZE] = {0};
      
      // TEST BOARD UNTIL WE CAN MOVE BOARD OVER FROM COMPUTER INITALIZATION CODE
      int Cboard[BOARD_SIZE][BOARD_SIZE] = {0};

      printPlayerBoard(Pboard);
      getShip(4, &so1, &sx1, &sy1, Pboard);
      printPlayerBoard(Pboard);
      getShip(3, &so2, &sx2, &sy2, Pboard);
      printPlayerBoard(Pboard);
      getShip(2, &so3, &sx3, &sy3, Pboard);
      printPlayerBoard(Pboard);
      
      printEnemyBoard(Cboard);
      
      return 0;
}

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

// Gets the players board
void printPlayerBoard(int Pboard[BOARD_SIZE][BOARD_SIZE])
{

      int p[6][6] = {0};
      int row = 0;
      int col = 0;
      int i, k;

      // 0 = no ship, 1 = ship
      
      for (k = 0; k < 6; k++)
      {
          for (i = 0; i < 6; i++)
          {
              if (Pboard[row + k][col + i] == 1)
              {
                  p[k][i] = 1;
              }
          }
      }

      printf("+---------------------------+\n");                                                                    // Line 1
      printf("|           Player          |\n");                                                                    // Line 2
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 3
      printf("|   | 1 | 2 | 3 | 4 | 5 | 6 |\n");                                                                    // Line 4
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 5
      printf("| A | %d | %d | %d | %d | %d | %d |\n", p[0][0], p[0][1], p[0][2], p[0][3], p[0][4], p[0][5]);        // Line 6: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 7
      printf("| B | %d | %d | %d | %d | %d | %d |\n", p[1][0], p[1][1], p[1][2], p[1][3], p[1][4], p[1][5]);        // Line 8: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 9
      printf("| C | %d | %d | %d | %d | %d | %d |\n", p[2][0], p[2][1], p[2][2], p[2][3], p[2][4], p[2][5]);        // Line 10: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 11
      printf("| D | %d | %d | %d | %d | %d | %d |\n", p[3][0], p[3][1], p[3][2], p[3][3], p[3][4], p[3][5]);        // Line 12: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 13
      printf("| E | %d | %d | %d | %d | %d | %d |\n", p[4][0], p[4][1], p[4][2], p[4][3], p[4][4], p[4][5]);        // Line 14: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 15
      printf("| F | %d | %d | %d | %d | %d | %d |\n", p[5][0], p[5][1], p[5][2], p[5][3], p[5][4], p[5][5]);        // Line 16: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 17
      

}

// Gets the computers board
void printEnemyBoard(int Cboard[BOARD_SIZE][BOARD_SIZE])
{

      int c[6][6];
      int row = 0;
      int col = 0;
      int i, k;
      
      // blank is no interaction yet, O = miss, X = hit
      
      for (k = 0; k < 6; k++)
      {
          for (i = 0; i < 6; i++)
          {
              c[k][i] = ' ';
          }
      }
      
      printf("+---------------------------+\n");                                                                    // Line 1
      printf("|          Computer         |\n");                                                                    // Line 2
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 3
      printf("|   | 1 | 2 | 3 | 4 | 5 | 6 |\n");                                                                    // Line 4
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 5
      printf("| A | %c | %c | %c | %c | %c | %c |\n", c[0][0], c[0][1], c[0][2], c[0][3], c[0][4], c[0][5]);        // Line 6
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 7
      printf("| B | %c | %c | %c | %c | %c | %c |\n", c[1][0], c[1][1], c[1][2], c[1][3], c[1][4], c[1][5]);        // Line 8
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 9
      printf("| C | %c | %c | %c | %c | %c | %c |\n", c[2][0], c[2][1], c[2][2], c[2][3], c[2][4], c[2][5]);        // Line 10
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 11
      printf("| D | %c | %c | %c | %c | %c | %c |\n", c[3][0], c[3][1], c[3][2], c[3][3], c[3][4], c[3][5]);        // Line 12
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 13
      printf("| E | %c | %c | %c | %c | %c | %c |\n", c[4][0], c[4][1], c[4][2], c[4][3], c[4][4], c[4][5]);        // Line 14
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 15
      printf("| F | %c | %c | %c | %c | %c | %c |\n", c[5][0], c[5][1], c[5][2], c[5][3], c[5][4], c[5][5]);        // Line 16
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 17

}
