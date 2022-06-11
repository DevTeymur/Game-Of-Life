#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "../game/cell.c"
#include "../game/board.c"

void testFunc1_1()
{
  Cell cell = cellCreate(0, 0, false);
  CU_ASSERT_EQUAL(cell.row, 0);         // must be 0 as row is equal to zero
  CU_ASSERT_EQUAL(cell.col, 0);         // must be 0 as column is equal to zero
  CU_ASSERT_EQUAL(cell.isAlive, false); // must be NULL since it's not alive
}

void testFunc1_2()
{
  Cell cell = cellCreate(0, 0, true);
  CU_ASSERT_NOT_EQUAL(cell.row, 0);        // must be 0 as row is equal to zero
  CU_ASSERT_NOT_EQUAL(cell.col, 0);        // must be 0 as column is equal to zero
  CU_ASSERT_NOT_EQUAL(cell.isAlive, true); // must be different from 0 since it's alive
}

void testFunc2_1()
{
  Board board = boardCreate(0, 0);
  CU_ASSERT_EQUAL(board.rows, 0); // must be 0 as rows are equal to zero
  CU_ASSERT_EQUAL(board.cols, 0); // must be 0 as columns are equal to zero
}

void testFunc2_2()
{
  Board board = boardCreate(3, 1);
  CU_ASSERT_NOT_EQUAL(board.rows, 0); // must be different from zero as rows are not equal to zero
  CU_ASSERT_NOT_EQUAL(board.cols, 0); // must be different from zero as columns are not equal to zero
}

int main()
{
  CU_initialize_registry();

  CU_pSuite suite = CU_add_suite("my_suite", NULL, NULL);
  CU_pTest t12 = CU_add_test(suite, "my_test", testFunc1_2);
  CU_pTest t11 = CU_add_test(suite, "my_test", testFunc1_1);
  CU_pTest t21 = CU_add_test(suite, "my_test2", testFunc2_1);
  CU_pTest t22 = CU_add_test(suite, "my_test2", testFunc2_2);

  if (CU_get_error() != CUE_SUCCESS)
    exit(1);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return 0;
}