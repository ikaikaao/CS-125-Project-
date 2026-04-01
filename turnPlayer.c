/*
File: turnPlayer.c
Author: Aidan Monsen
Purpose: takes the players turn
Version: 1.0 Mar 31, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>

void turnPlayer(int Cboard[BOARD_SIZE][BOARD_SIZE], int CPboard[BOARD_SIZE][BOARD_SIZE])
{

      int col;
      char row;
    
      printf("PLAYER TURN\n\n");    
    
      printf("Enter the X coordinate (1-6) for your guess: ");
      scanf("%d", &col);
      
      if ((col < 1) || (col > 6))
      {
          printf("Good Job\n");
      }
      
      printf("Enter the Y coordinate (A-F) for your guess: ");
      scanf(" %c", &row);

      if ((row < 'A') || (row > 'F'))
      {
          printf("Learn English\n");
      }
      
      int rowIndex = row - 'A';
      int colIndex = col - 1;
      
      if (Cboard[rowIndex][colIndex] == 1)
      {
          CPboard[rowIndex][colIndex] = 1;
          printf("(%d,%c)\n", col, row);
          printf("\nHit, take another turn\n");
      }
      
      else if (Cboard[rowIndex][colIndex] == 0)
      {
          CPboard[rowIndex][colIndex] = 2;
          printf("(%d,%c)\n", col, row);
          printf("\nMiss, computer's turn\n"); 
      }
}
