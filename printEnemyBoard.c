/*
File: printEnemyBoard.c
Author: Aidan Monsen
Purpose: print out the enemys board state
Version: 1.1 Apr 7, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>

void printEnemyBoard(int CPboard[BOARD_SIZE][BOARD_SIZE])
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
              
              if (CPboard[k][i] == 1)
              {
                  c[k][i] = 'X';
              }
              
              else if (CPboard[k][i] == 2)
              {
                  c[k][i] = 'O';
              }
          }
      }
      

      printf("\n");
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
      printf("+---+---+---+---+---+---+---+\n\n");                                                                    // Line 17

}
