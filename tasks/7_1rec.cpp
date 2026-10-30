// 7_1rec.cpp
// Войтович Богдан
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці
// Варіант 3

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fillMatrix(int** arr, const int rows, const int cols, const int min_n,
                const int max_n, int i, int j) {
  if (i >= rows) {
    return;
  } else if (j >= cols) {
    fillMatrix(arr, rows, cols, min_n, max_n, i + 1, 0);
    return;
  }

  arr[i][j] = min_n + rand() % (max_n - min_n + 1);

  fillMatrix(arr, rows, cols, min_n, max_n, i, j + 1);
}

void printMatrix(int** arr, const int rows, const int cols, int i, int j) {
  if (i >= rows) {
    cout << "\n";
    return;
  } else if (j >= cols) {
    printMatrix(arr, rows, cols, i + 1, 0);
    return;
  }

  if (j == 0) {
    cout << "\n";
  }
  cout << setw(4) << arr[i][j];

  printMatrix(arr, rows, cols, i, j + 1);
}

void rearrange(int** arr, const int row1, const int row2, const int cols,
               int j) {
  if (j >= cols) {
    return;
  }

  int temp = arr[row1][j];
  arr[row1][j] = arr[row2][j];
  arr[row2][j] = temp;

  rearrange(arr, row1, row2, cols, j + 1);
}

void sortRows(int** arr, const int col1, const int col2, const int col3,
              const int rows, const int cols, int i, bool is_swapped = false) {
  if (i + 1 >= rows) {
    if (is_swapped) {
      sortRows(arr, col1, col2, col3, rows, cols, 0, false);
      return;
    } else {
      return;
    }
  }

  if ((arr[i][col1] > arr[i + 1][col1]) ||

      (arr[i][col1] == arr[i + 1][col1] && arr[i][col2] < arr[i + 1][col2]) ||

      (arr[i][col1] == arr[i + 1][col1] && arr[i][col2] == arr[i + 1][col2] &&
       arr[i][col3] > arr[i + 1][col3])) {
    rearrange(arr, i, i + 1, cols, 0);
    is_swapped = true;
  }

  sortRows(arr, col1, col2, col3, rows, cols, i + 1, is_swapped);
}

int countElements(int** arr, const int rows, const int cols, int i, int j) {
  int count = 0;

  if (i >= rows) {
    return 0;
  } else if (j >= cols) {
    return count + countElements(arr, rows, cols, i + 1, 0);
  }

  if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
    count = 1;
  }

  return count + countElements(arr, rows, cols, i, j + 1);
}

int calcSum(int** arr, const int rows, const int cols, int i, int j) {
  int s = 0;

  if (i >= rows) {
    return 0;
  } else if (j >= cols) {
    return s + calcSum(arr, rows, cols, i + 1, 0);
  }

  if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
    s = arr[i][j];
  }

  return s + calcSum(arr, rows, cols, i, j + 1);
}

void replaceWithZero(int** arr, int rows, int cols, int i, int j) {
  if (i >= rows) {
    return;
  } else if (j >= cols) {
    replaceWithZero(arr, rows, cols, i + 1, 0);
    return;
  }

  if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
    arr[i][j] = 0;
  }

  replaceWithZero(arr, rows, cols, i, j + 1);
}

#ifndef TEST_MODE
int main() {
  srand((unsigned)time(NULL));

  const int rows = 7;     // кількість рядків матриці
  const int cols = 6;     // кількість стовпчиків матриці
  const int min_n = -42;  // нижня межа діапазону значень елементів
  const int max_n = 51;   // верхня межа діапазону значень елементів

  int** T = new int*[rows];  // матриця: масив вказівників на рядки
  for (int i = 0; i < rows; i++) {
    T[i] = new int[cols];
  }

  fillMatrix(T, rows, cols, min_n, max_n, 0, 0);
  printMatrix(T, rows, cols, 0, 0);

  sortRows(T, 0, 1, 2, rows, cols, 0);
  printMatrix(T, rows, cols, 0, 0);

  cout << "\nCount = " << countElements(T, rows, cols, 0, 0) << "\n";
  cout << "Sum = " << calcSum(T, rows, cols, 0, 0) << "\n";

  replaceWithZero(T, rows, cols, 0, 0);
  printMatrix(T, rows, cols, 0, 0);

  for (int i = 0; i < rows; i++) {
    delete[] T[i];
  }
  delete[] T;

  return 0;
}
#endif