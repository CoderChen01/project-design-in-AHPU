#include <stdio.h>
#define FALSE 0 


int sellFishMain()
{
    int sellFish(int x);
    int x;  /* the number of fish */
    int remaining = 0;  /* the remaining number of fish */
    
    printf("\n\n========================== first problem =====================\n\n");

    for (x = 11; ; x++)
    {   
        remaining = sellFish(x);

        if (remaining == FALSE)
        {
            continue;
        }
		
		if (remaining == 11)
		{
			break;
		}
    }


    printf("the result is %d\n", x);

}


/*************************************************
Function: sellFish
Description: Receive a number then return the last remaining number of fish if success else return false
Called By: main
Input: The total number of fish
Return: the last remaining number of fish
*************************************************/
int sellFish(int x)
{
    int n = 5, i;  /* the number of fish sold and cycle count. */
    int remaining;  /* the remaining number of fish. */

    for (i = 1, remaining = x; i <= n - 1; ++i)
    {
        if ((remaining + 1) % (i + 1))
        {
            return FALSE;
        }

        remaining = remaining - (remaining + 1) / (i + 1);
    }

    return remaining;
}

