/*
File: printPlayerBoard.c
Author: Aidan Monsen
Purpose: print out the players board state
Version: 1.1 Mar 257 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>

void printPlayerBoard(int Pboard[BOARD_SIZE][BOARD_SIZE])
{

      int p[6][6];
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
                  p[k][i] = 'S';
              }
              
              else if (Pboard[row + k][col + i] == 2)
              {
                  p[k][i] = 'X';
              }
              
              else
              {
                  p[k][i] = ' ';
              }
          }
      }

      printf("\n");
      printf("+---------------------------+\n");                                                                    // Line 1
      printf("|           Player          |\n");                                                                    // Line 2
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 3
      printf("|   | 1 | 2 | 3 | 4 | 5 | 6 |\n");                                                                    // Line 4
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 5
      printf("| A | %c | %c | %c | %c | %c | %c |\n", p[0][0], p[0][1], p[0][2], p[0][3], p[0][4], p[0][5]);        // Line 6: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 7
      printf("| B | %c | %c | %c | %c | %c | %c |\n", p[1][0], p[1][1], p[1][2], p[1][3], p[1][4], p[1][5]);        // Line 8: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 9
      printf("| C | %c | %c | %c | %c | %c | %c |\n", p[2][0], p[2][1], p[2][2], p[2][3], p[2][4], p[2][5]);        // Line 10: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 11
      printf("| D | %c | %c | %c | %c | %c | %c |\n", p[3][0], p[3][1], p[3][2], p[3][3], p[3][4], p[3][5]);        // Line 12: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 13
      printf("| E | %c | %c | %c | %c | %c | %c |\n", p[4][0], p[4][1], p[4][2], p[4][3], p[4][4], p[4][5]);        // Line 14: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 15
      printf("| F | %c | %c | %c | %c | %c | %c |\n", p[5][0], p[5][1], p[5][2], p[5][3], p[5][4], p[5][5]);        // Line 16: Depends on user input
      printf("+---+---+---+---+---+---+---+\n");                                                                    // Line 17
      

}
