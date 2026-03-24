/*
File: playerShips.h
Author: Aidan Monsen
Purpose: Create a structure to track the players ships health
Version: 1.0 Mar 24, 2026
Resources:
*/

// 4 length ship
typedef struct 
{

      int p[4] = {1, 1, 1, 1};

} P4Ship;

// 3 length ship
typedef struct
{

      int p[3] = {1, 1, 1};

} P3Ship;

//2 length ship
typedef struct
{

      int p[2] = {1, 1};

} P2Ship;
