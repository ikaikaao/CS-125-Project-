/*
File: getCompShip.c
Author: Ikaikaokealohilani Ofsthun
Purpose: gets the position and orientation of the computers ships
Version: 1.1 Apr 7, 2026
Resources:
*/

#define BOARD_SIZE 6

void getCompShip(int Cboard[BOARD_SIZE][BOARD_SIZE]) 
{

      int i, j, strhor, strver, condition, overlap, h, v, iteration=1;

	    while (iteration == 1) 
      {

		  // reset board
		  for (i = 0; i < BOARD_SIZE; i++) 
      {
			    for (j = 0; j < BOARD_SIZE; j++) 
          {
				      Cboard[i][j] = 0;
          }
      }

		  overlap = 0;

		  // ---------- 4 BOAT ----------
		  strhor = rand() % 3;
		  strver = rand() % 3;
		  condition = rand() % 2;

		  for (i = 0; i < 4; i++) 
      {
			    h = (condition == 0) ? strhor + i : strhor;
          v = (condition == 0) ? strver : strver + i;
			    Cboard[h][v] = 1;
		  }

		  // ---------- 3 BOAT ----------
		  strhor = rand() % 4;
		  strver = rand() % 4;
		  condition = rand() % 2;

		  for (i = 0; i < 3; i++) 
      {
			    h = (condition == 0) ? strhor + i : strhor;
          v = (condition == 0) ? strver : strver + i;

          if (Cboard[h][v] == 1) 
          {
				      overlap = 1;
			    }
		  }

		  if (overlap==1) 
      {
			    continue;
		  }

		  for (i = 0; i < 3; i++) 
      {
			    h = (condition == 0) ? strhor + i : strhor;
			    v = (condition == 0) ? strver : strver + i;
			    Cboard[h][v] = 1;
		  }

		  // ---------- 2 BOAT ----------
		  strhor = rand() % 5;
		  strver = rand() % 5;
		  condition = rand() % 2;

		  for (i = 0; i < 2; i++) 
      {
			    h = (condition == 0) ? strhor + i : strhor;
			    v = (condition == 0) ? strver : strver + i;

			    if (Cboard[h][v] == 1) 
          {
				      overlap = 1;
			    }
		  }

		  if (overlap==1) 
      {
			    continue;
		  }

		  for (i = 0; i < 2; i++) 
      {
			    h = (condition == 0) ? strhor + i : strhor;
			    v = (condition == 0) ? strver : strver + i;
			    Cboard[h][v] = 1;
		  }
		  iteration = 0;
	    }
}
