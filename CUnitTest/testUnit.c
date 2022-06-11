#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "../game/board.h"

void testFunc1_1()
{
  Cell *cell = cellCreate(0, 0, false);
  CU_ASSERT_EQUAL(cell, NULL); // must be NULL since it's not alive
}

void testFunc1_2()
{
  Cell *cell = cellCreate(0, 0, true);
  CU_ASSERT_NOT_EQUAL(cell, NULL); // must be different from 0 since it's alive
}

void testFunc2_1()
{
  Board *board = boardCreate(0, 0);
  CU_ASSERT_EQUAL(board, NULL); // must be NULL
}

void testFunc2_2()
{
  Board *board = boardCreate(3, 1);
  CU_ASSERT_NOT_EQUAL(board, NULL); // must be different from 0
}

void testFunc3_1()
{
  int col1, row1;
  col1 = 33;
  row1 = 33;
  Board *board = boardCreate(col1, row1);
  Board *neighbors[13];
  int size;
  size = getNeighbors(board, col1 - 18, row1 - 18, neighbors); // random coordinate on board
  CU_ASSERT_NOT_EQUAL(size, 0);                                // size must be different from 0
}

void testFunc3_2()
{
  int col1, row1;
  col1 = 0;
  row1 = 0;
  Board *board = boardCreate(col1, row1);
  Board neighbors[10];
  int size;
  size = getNeighbors(board, col1, row1, neighbors); // random coordinate on board
  CU_ASSERT_EQUAL(size, 0);                          // size must be 0
}
void startTest()
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("my_suite", NULL, NULL);
  CU_pTest t11 = CU_add_test(suite, "my_test", testFunc1_1);
  CU_pTest t12 = CU_add_test(suite, "my_test", testFunc1_2);
  CU_pTest t21 = CU_add_test(suite, "my_test2", testFunc2_1);
  CU_pTest t22 = CU_add_test(suite, "my_test2", testFunc2_2);
  CU_pTest t31 = CU_add_test(suite, "my_test3", testFunc3_1);
  CU_pTest t32 = CU_add_test(suite, "my_test3", testFunc3_2);

  if (CU_get_error() != CUE_SUCCESS)
    exit(1);
  CU_basic_run_tests();

  CU_cleanup_registry();
}