#include "board.h"

Board boardCreate(int cols, int rows)
{
  Board board;
  board.rows = rows;
  board.cols = cols;

  // Creating 2D tables dynamically
  board.oldTable = (Cell **)calloc(cols, sizeof(Cell *));
  for (int i = 0; i < cols; i++)
  {
    board.oldTable[i] = (Cell *)calloc(rows, sizeof(Cell));
  }

  board.newTable = (Cell **)calloc(cols, sizeof(Cell *));
  for (int i = 0; i < cols; i++)
  {
    board.newTable[i] = (Cell *)calloc(rows, sizeof(Cell));
  }
  randFill(&board);
  return board;
}

bool checkCellState(Board *board, int col, int row)
{
  int numberOfAliveNeighbors = countAliveNeighbors(board, col, row);

  if (board->oldTable[col][row].isAlive)
  {
    if (numberOfAliveNeighbors > 3 || numberOfAliveNeighbors < 2)
      return false;
    else
      return true;
  }
  else
  {
    if (numberOfAliveNeighbors == 3)
      return true;
    else
      return false;
  }
}

bool cellBelong(Board *board, int *coordinate)
{
  return (coordinate[0] >= 0 && coordinate[1] >= 0 && coordinate[0] < board->cols && coordinate[1] < board->rows);
}

bool getCellState(Board *board, int col, int row)
{
  return board->oldTable[col][row].isAlive;
}

int getNeighbors(Board *board, int col, int row, Cell *neighbors)
{
  int size = 0;

  int positions[8][2] = {
      {col + 1, row + 1},
      {col + 1, row - 1},
      {col - 1, row + 1},
      {col - 1, row - 1},
      {col + 1, row},
      {col - 1, row},
      {col, row + 1},
      {col, row - 1},
  };

  for (int i = 0; i < 8; i++)
  {
    if (cellBelong(board, positions[i]))
    {
      neighbors[size] = board->oldTable[positions[i][0]][positions[i][1]];
      size++;
    }
  }
  return size;
}

int countAliveNeighbors(Board *board, int col, int row)
{
  int numberOfAliveCells = 0;
  Cell neighbors[8];
  int size = getNeighbors(board, col, row, neighbors);

  for (int i = 0; i < size; i++)
  {
    if (neighbors[i].isAlive)
      numberOfAliveCells++;
  }
  return numberOfAliveCells;
}

void duplicateTable(Board *board)
{
  for (int i = 0; i < board->cols; i++)
  {
    for (int j = 0; j < board->rows; j++)
    {
      board->oldTable[i][j].isAlive = board->newTable[i][j].isAlive;
    }
  }
}

void generateNext(Board *board)
{
  for (int i = 0; i < board->cols; i++)
  {
    for (int j = 0; j < board->rows; j++)
    {
      board->newTable[i][j].isAlive = checkCellState(board, i, j);
    }
  }
}

void randFill(Board *board)
{
  for (int i = 0; i < board->cols; i++)
  {
    for (int j = 0; j < board->rows; j++)
    {
      board->newTable[i][j] = cellCreate(i, j, false);
      board->oldTable[i][j] = cellCreate(i, j, rand() % 2);
    }
  }
}