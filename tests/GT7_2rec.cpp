#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/7_2rec.cpp"

TEST(GT7_2rec, FindMinInRow) {
  const int k = 4;
  const int n = 3;

  int** M = new int*[k];
  for (int i = 0; i < k; i++) {
    M[i] = new int[n];
  }

  int initial[k][n] = {{-5, 5, 10}, {100, 40, -40}, {11, 21, 31}, {1, 2, 4}};

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = initial[i][j];
    }
  }

  EXPECT_EQ(findMinInRow(M, 1, n), -40);
  EXPECT_EQ(findMinInRow(M, 2, n), 11);
  EXPECT_EQ(findMinInRow(M, 3, n), 1);
}

TEST(GT7_2rec, CalcMinSum) {
  const int k = 4;
  const int n = 3;

  int** M = new int*[k];
  for (int i = 0; i < k; i++) {
    M[i] = new int[n];
  }

  int initial[k][n] = {{-5, 5, 10}, {100, 40, -40}, {11, 21, 31}, {1, 2, 4}};

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = initial[i][j];
    }
  }

  EXPECT_EQ(calcMinSum(M, k, n), -33);

  for (int i = 0; i < k; i++) {
    delete[] M[i];
  }
  delete[] M;

  for (int i = 0; i < k; i++) {
    delete[] M[i];
  }
  delete[] M;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}