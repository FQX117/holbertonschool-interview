#ifndef SLIDE_H
#define SLIDE_H

/* libraries */
#include <stdio.h>
#include <stdlib.h>

/* macros */
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

/* prototype */
int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide_right(int *line, size_t size);

#endif /* SLIDE_H */
