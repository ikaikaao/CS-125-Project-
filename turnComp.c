/*
File: turnComp.c
Author: Ikaikaokealohilani Ofsthun
Purpose: ai for computer
Version: 1.0 Mar 27, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>

void turnComp(int Pboard[BOARD_SIZE][BOARD_SIZE]) {  //Using computers board for testing should be player board

	int strhor, strver, iteration, h, v, condition, i, sign;     //All instances with computer board array replace with player board

	printf("\nComputers Turn\n");

	strhor = rand()%6;
	strver = rand()%6;
	condition = rand()%2;
	sign = rand()%2;

	if (Pboard[strhor][strver] == 1) {   // Hit Case
		Pboard[strhor][strver] = 2;
		iteration = 1;
   printf("Hit, computer takes another turn\n");
	} else {   // Miss Case
		iteration = 0;
   printf("Miss, your turn\n");
	}

    while (iteration == 1) {

		for (i = 1; i < 4; i++) {

			if (sign == 0) {
				h = (condition == 0)? strhor + i : strhor;
				v = (condition == 0)? strver : strver + i;
			} else {
				h = (condition == 0)? strhor - i : strhor;
				v = (condition == 0)? strver : strver - i;
			}
			
			if ((h < 0) || (v < 0)) {
                sign = 0;
                i = 1; 
                continue;
				
			}
			
			if ((h >= BOARD_SIZE) || (v >= BOARD_SIZE)) {
			    sign = 1;
			    i = 1;
			    continue;
			    
			}

			if (Pboard[h][v] == 'S') {
				Pboard[h][v] = ' ';
			} else {
				iteration = 0;
				break;
			}
		}
	}
}
