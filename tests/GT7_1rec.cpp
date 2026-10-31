#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/7_1rec.cpp"

TEST(GT7_1rec, SortMatrix) {
  const int rows = 4, cols = 3;

  int** matrix = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  int initial[rows][cols] = {{2, 1, 1}, {1, 4, 4}, {1, 2, 3}, {1, 2, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = initial[i][j];
    }
  }
  sortRows(matrix, 0, 1, 2, rows, cols, 0);

  int expected[rows][cols] = {{1, 4, 4}, {1, 2, 3}, {1, 2, 4}, {2, 1, 1}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_EQ(matrix[i][j], expected[i][j]);
    }
  }

  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

TEST(GT7_1rec, Replace) {
  const int rows = 4, cols = 3;

  int** matrix = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  int initial[rows][cols] = {
    {-5, 5, 10}, {100, 40, -40}, {11, 21, 31}, {1, 2, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = initial[i][j];
    }
  }
  replaceWithZero(matrix, rows, cols, 0, 0);

  int expected[rows][cols] = {{0, 5, 10}, {100, 40, 0}, {0, 0, 0}, {0, 0, 0}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_EQ(matrix[i][j], expected[i][j]);
    }
  }

  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}