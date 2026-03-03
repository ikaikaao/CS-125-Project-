/*
File: Battleship.c
Authors: Aidan Monsen and Ikaikaokealohilani Ofsthun
Purpose: Recreate Battleship in C
Version: 1.0 Feb 24, 2026
Resources:
*/

#define BOARD_SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void toProperCase(char *str);


int main()
{
      char so1, so2, so3, sy1, sy2, sy3;
      int sx1, sx2, sx3;

      // Ship 1
      // Orientation
      do 
      {
            printf("Enter the orientation of your 4 length ship (v/h): ");
            scanf(" %c", &so1);
            toProperCase(&so1);

            if ((so1 != 'V') && (so1 != 'H'))
                  printf("Invalid orientation for ship!\n");

      } while ((so1 != 'V') && (so1 != 'H'));
      
      // X coordinate
       do 
       {
            printf("Enter the starting x coordinate of your 4 length ship: ");
            scanf("%d", &sx1);

            if ((so1 == 'H') && (sx1 >= 4))
                  printf("Invalid Position for ship!\n");

      } while ((so1 == 'H') && (sx1 >= 4));
      
      // Y coordinate
      do 
      {
            printf("Enter the starting y coordinate of your 4 length ship: ");
            scanf(" %c", &sy1);
            toProperCase(&sy1);

            if ((so1 == 'V') && (sy1 >= 'C'))
                  printf("Invalid Position for ship!\n");

      } while ((so1 == 'V') && (sy1 >= 'C'));
      
      // Ship 2
      // Orientation
      do 
      {
            printf("Enter the orientation of your 3 length ship (v/h): ");
            scanf(" %c", &so2);
            toProperCase(&so2);

            if ((so2 != 'V') && (so2 != 'H'))
                  printf("Invalid orientation for ship!\n");

      } while ((so2 != 'V') && (so2 != 'H'));
      
      // X coordinate
      do 
      {
            printf("Enter the starting x coordinate of your 3 length ship: ");
            scanf("%d", &sx2);

            if ((so2 == 'H') && (sx2 >= 5))
                  printf("Invalid Position for ship!\n");

      } while ((so2 == 'H') && (sx2 >= 5));
      
      // Y coordinate
      do 
      {
            printf("Enter the starting y coordinate of your 3 length ship: ");
            scanf(" %c", &sy2);
            toProperCase(&sy2);

            if ((so2 == 'V') && (sy2 >= 'D'))
                  printf("Invalid Position for ship!\n");

      } while ((so2 == 'V') && (sy2 >= 'D'));
}

void toProperCase(char *str)
{
      int i;
      for (i = 0; str[i]; i++)
      {
          str[i] = tolower(str[i]);
      }
      str[0] = toupper(str[0]);
}
