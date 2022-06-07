#include "cell.h"

Cell cellCreate(int col, int row, bool isAlive)
{
  Cell cell;
  cell.col = col;
  cell.row = row;
  cell.isAlive = isAlive;
  return cell;
}