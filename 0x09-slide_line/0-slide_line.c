#include "slide_line.h"

/**
 * slide_line - a function that slides and merges an int array
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 * @direction: is either the left or right macro
 * Return: returns 1 for success or 0 if failed
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != 0 && direction != 1)
		return (0);
	if (line == NULL || size < 1)
		return (0);

	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);

	return (1);
}

/**
 * slide_left - slides to the left
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 */
void slide_left(int *line, size_t size)
{
	int i, position = 0, n = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			position++;

		if (line[i] > 0)
			n++;

		if (line[i] > 0 && position > 0)
		{
			line[i - position] = line[i];
			line[i] = 0;
			i = i - position;
			position = 0;
		}
	}
	position = 0;

	for (i = 0; i < n; i++)
	{
		if (i < n - 1 && line[i] == line[i + 1])
		{
			line[position] = line[i] + line[i + 1];
			line[i + 1] = 0;
			if (position != i)
				line[i] = 0;
			position++;
		}
		else if (line[i] > 0 && position > 0)
		{
			line[position] = line[i];
			if (position != i)
				line[i] = 0;
			position++;
		}
		else if (line[i] > 0)
			position++;
	}
}

/**
 * slide_right - slides to the right
 * @line: points to an array of int -max is 32
 * @size: the size of the array
 */
void slide_right(int *line, size_t size)
{
	int i, position = 0, max = size - 1, n = 0;

	for (i = max; i >= 0; i--)
	{
		if (line[i] == 0)
			position++;

		if (line[i] > 0)
			n++;

		if (line[i] > 0 && position > 0)
		{
			line[i + position] = line[i];
			line[i] = 0;
			i = i + position;
			position = 0;
		}
	}
	position = max;

	for (i = max; i > max - n; i--)
	{
		if (i > max - n + 1 && line[i] == line[i - 1])
		{
			line[position] = line[i] + line[i - 1];
			line[i - 1] = 0;
			if (position != i)
				line[i] = 0;
			position--;
		}
		else if (line[i] > 0 && position < max)
		{
			line[position] = line[i];
			if (position != i)
				line[i] = 0;
			position--;
		}
		else if (line[i] > 0)
			position--;
	}
}
