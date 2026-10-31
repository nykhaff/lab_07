// 7_2rec.cpp
// Войтович Богдан
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами
// Варіант 3

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fillMatrix(int** arr, const int rows, const int cols, const int min_n,
                const int max_n, int i = 0, int j = 0) {
  if (i >= rows) {
    return;
  } else if (j >= cols) {
    fillMatrix(arr, rows, cols, min_n, max_n, i + 1);
    return;
  }

  arr[i][j] = min_n + rand() % (max_n - min_n + 1);

  fillMatrix(arr, rows, cols, min_n, max_n, i, j + 1);
}

void printMatrix(int** arr, const int rows, const int cols, int i = 0,
                 int j = 0) {
  if (i >= rows) {
    cout << "\n";
    return;
  } else if (j >= cols) {
    printMatrix(arr, rows, cols, i + 1);
    return;
  }

  if (j == 0) {
    cout << "\n";
  }

  cout << setw(4) << arr[i][j];

  printMatrix(arr, rows, cols, i, j + 1);
}

int findMinInRow(int** arr, const int row, const int cols, int j = 0) {
  if (j == cols - 1) {
    return arr[row][j];
  }
  int rest = findMinInRow(arr, row, cols, j + 1);

  if (arr[row][j] < rest) {
    return arr[row][j];
  } else {
    return rest;
  }
}

int calcMinSum(int** arr, const int rows, const int cols, int i = 0) {
  if (i >= rows) {
    return 0;
  }

  return findMinInRow(arr, i, cols) + calcMinSum(arr, rows, cols, i + 1);
}

#ifndef TEST_MODE
int main() {
  srand((unsigned)time(NULL));

  int k, n;  // k - рядки, n - стовпці

  cout << "k = ";
  cin >> k;
  cout << "n = ";
  cin >> n;

  int** M = new int*[k];
  for (int i = 0; i < k; i++) {
    M[i] = new int[n];
  }

  fillMatrix(M, k, n, -20, 26);
  printMatrix(M, k, n);

  cout << "\nSum of the smalest numbers on each row: " << calcMinSum(M, k, n);

  for (int i = 0; i < k; i++) {
    delete[] M[i];
  }
  delete[] M;

  return 0;
}
#endif