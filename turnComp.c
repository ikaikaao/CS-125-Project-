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

	strhor = rand() % 6;
	strver = rand() % 6;
	condition = rand() % 2;
	sign = rand() % 2;

	if (Pboard[strhor][strver] == 1) {   // Hit Case
		Pboard[strhor][strver] = 2;
		iteration = 1;
	} else {   // Miss Case
		iteration = 0;
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

			if ((h < 0) || (h >= BOARD_SIZE) || (v < 0) || (v >= BOARD_SIZE)) {
				iteration = 0;
				break;
			}

			if (Pboard[h][v] == 1) {
				Pboard[h][v] = 2;
			} else {
				iteration = 0;
				break;
			}
		}
	}
}
