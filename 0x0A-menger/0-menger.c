#include "menger.h"
#include <math.h>

/**
 * menger - draws a 2d menger sponge
 *
 * @level: is the level of the menger sponge to draw
 */

void menger(int level)
{
	int i, j, size, dh, dw;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			dh = i, dw = j;
			while (1)
			{
				if (dh % 3 == 1 && dw % 3 == 1)
				{
					printf(" ");
					break;
				}
				if (dh == 0 || dw == 0)
				{
					printf("#");
					break;
				}
				dh /= 3;
				dw /= 3;

			}
		}
		printf("\n");
	}
}