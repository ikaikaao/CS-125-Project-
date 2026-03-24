/*
File: computerShips.h
Author: Aidan Monsen
Purpose: Create a structure to track the computers ships health
Version: 1.0 Mar 24, 2026
Resources:
*/

// 4 length ship
typedef struct 
{

      int c[4] = {1, 1, 1, 1};

} C4Ship;

// 3 length ship
typedef struct
{

      int c[3] = {1, 1, 1};

} C3Ship;

//2 length ship
typedef struct
{

      int c[2] = {1, 1};

} C2Ship;
