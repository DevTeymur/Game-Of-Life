#ifndef __CELL_H__
#define __CELL_H__

#include <stdbool.h>

typedef struct _Cell
{
  int col, row;
  bool isAlive;
} Cell;

// Initializing cells row, column number and the state
Cell cellCreate(int col, int row, bool isAlive);

#endif // __CELL_H__