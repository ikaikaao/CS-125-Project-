/*
File: turnPlayer.c
Author: Aidan Monsen
Purpose: takes the players turn
Version: 1.0 Mar 31, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>
#include "printEnemyBoard.h"

int turnPlayer(int Cboard[BOARD_SIZE][BOARD_SIZE], int CPboard[BOARD_SIZE][BOARD_SIZE])
{

      int col;
      char row;
      int hit;
    
      printf("\nPLAYER TURN\n\n");    
    
      do
      {
          hit = 0;
      
          printf("Enter the X coordinate (1-6) for your guess: ");
          scanf("%d", &col);
      
          if ((col < 1) || (col > 6))
          {
              printf("Ivalid Column. Try again.\n");
              continue;
          }
      
          printf("Enter the Y coordinate (A-F) for your guess: ");
          scanf(" %c", &row);
          row = toupper(row);

          if ((row < 'A') || (row > 'F'))
          {
              printf("Invalid row. Try again.\n");
              continue;
          }
      
          int rowIndex = row - 'A';
          int colIndex = col - 1;

          if (CPboard[rowIndex][colIndex] == 1 || CPboard[rowIndex][colIndex] == 2)
          {
                printf("You already guessed that spot! Try again.\n");
          }
            
          if (Cboard[rowIndex][colIndex] == 1)
          {
              CPboard[rowIndex][colIndex] = 1;
              printf("\n(%d,%c)\n", col, row);
              printf("Hit, take another turn\n");
              printEnemyBoard(CPboard);

              int hits = 0, r, c;
              
              for (r = 0; r < BOARD_SIZE; r++)
              {
                  for (c = 0; c < BOARD_SIZE; c++)
                  {
                      if (CPboard[r][c] == 1)
                      {
                          hits++;
                      }
                  }
              }
              
              if (hits >= 9)
              {
                  return 2;
              }
  
              hit = 1;
          }
      
          else if (Cboard[rowIndex][colIndex] == 0)
          {
              CPboard[rowIndex][colIndex] = 2;
              printf("\n(%d,%c)\n", col, row);
              printf("Miss, computer's turn\n");
              hit = 0;
          }
          
      } while(hit);
      
      return 1;
}
