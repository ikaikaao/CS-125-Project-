/*
File: Battleship.c
Authors: Aidan Monsen and Ikaikaokealohilani Ofsthun
Purpose: Recreate Battleship in C
Version: 1.5 Mar 27, 2026
Resources: 
*/

#define BOARD_SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "computerShips.h"
#include "playerShips.h"
#include "getShip.h"
#include "printPlayerBoard.h"
#include "printEnemyBoard.h"
#include "getCompShip.h"
#include "turnComp.h"
#include "turnPlayer.h"

void printFile(const char *filename)
{
      FILE *f = fopen(filename, "r");
      if (!f)
      {
            printf("Could not open %s\n", filename);
            return;
      }
      char line[256];
      while (fgets(line, sizeof(line), f))
      {
            printf("%s", line);
      }
      fclose(f);
}

int main()
{
      // Seeding the rand function
      srand(time(NULL));
      
      // Initializiing position and orientation variables for player ships
      char so1, so2, so3, sy1, sy2, sy3;
      int sx1, sx2, sx3;
      
      // Setting health of player and computer ships to 1
      P4Ship p4Ship = {1, 1, 1, 1};
      P3Ship p3Ship = {1, 1, 1};
      P2Ship p2Ship = {1, 1};
      
      C4Ship c4Ship = {1, 1, 1, 1};
      C3Ship c3Ship = {1, 1, 1};
      C2Ship c2Ship = {1, 1};
      
      // Initalizing the player board state
      int Pboard[BOARD_SIZE][BOARD_SIZE] = {0};

      printPlayerBoard(Pboard);
      getShip(4, &so1, &sx1, &sy1, Pboard);
      printPlayerBoard(Pboard);
      getShip(3, &so2, &sx2, &sy2, Pboard);
      printPlayerBoard(Pboard);
      getShip(2, &so3, &sx3, &sy3, Pboard);
      printPlayerBoard(Pboard);
      
      // Initalizing the computer board state
      int Cboard[BOARD_SIZE][BOARD_SIZE], i, j, x;
      int CPboard[BOARD_SIZE][BOARD_SIZE] = {0};
      
      getCompShip(Cboard);
      
      int Ccheck, Pcheck;
      
      do
      {
          // Start computers turn
          Ccheck = turnComp(Pboard);  
          if (Ccheck == 2)
          {
                printFile("youlose.txt");
                break;
          }
            
          // Start players turn
          Pcheck = turnPlayer(Cboard, CPboard);
          printEnemyBoard(CPboard);
          if (Pcheck == 2
          {
                printFile("youwin.txt");
                break;
          }
          
      } while ((Ccheck <= 1) || (Pcheck <= 1));
      

      
      return 0;
}
