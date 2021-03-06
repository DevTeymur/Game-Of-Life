#ifndef __BOARD_H__
#define __BOARD_H__

#define MAX_SIZE 128 // max size of the tables

#include <stdio.h>
#include <stdlib.h>

#include "cell.h"

typedef struct _Board
{
  int cols, rows;
  Cell **oldTable, **newTable;
} Board;

// Initializing the table using dynamic allocation depending on the row column values
// After changing array values to alive and dead cells with random filling
Board boardCreate(int cols, int rows);

// Checking the neighbors of the cell in order to change the state of the cell
bool checkCellState(Board *board, int col, int row);

// Checking if the cell in the edge of the screen or not
bool cellBelong(Board *board, int *coordinate);

// alive - true
// dead - false
bool getCellState(Board *board, int col, int row);

// Function to return the neighbors of the given cell
int getNeighbors(Board *board, int col, int row, Cell *neighbors);

// Counting the alive cells in order to change within the rules
int countAliveNeighbors(Board *board, int col, int row);

// Keeping copy of the "old" table in order to check conditions on it
void duplicateTable(Board *board);

// Function generating new table using old table and rules
void generateNext(Board *board);

// Using to fill the table with random states at the beginning
void randFill(Board *board);

#endif // __BOARD_H__