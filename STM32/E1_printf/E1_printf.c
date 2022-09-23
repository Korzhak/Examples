#include "main.h"
#include <stdio.h>

int main(void) 
{
    while (1)
    {
        printf("Printing string in Target I/O");
        printf("Example of formating int (%d), float (%f), char (%c)", 1, 3.14, 'y');
    }
}



// THE FOLLOW CODE MUST TO BE IN FILE
// IF YOU USE STM32CubeIDE

/* USER CODE BEGIN 4 */
int _write ( int file, char *ptr, int len )
{
  int i = 0;
  for ( i = 0; i < len; i++ )
    ITM_SendChar ( (*ptr++ ) );
  return len;
}
/* USER CODE END 4 */
