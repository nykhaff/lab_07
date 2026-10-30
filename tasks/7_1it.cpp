// 7_1it.cpp
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
                const int max_n) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = min_n + rand() % (max_n - min_n + 1);
    }
  }
}

void printMatrix(int** arr, const int rows, const int cols) {
  cout << "\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << setw(4) << arr[i][j];
    }
    cout << "\n";
  }
}

void rearrange(int** arr, const int row1, const int row2) {
  int* temp = arr[row1];
  arr[row1] = arr[row2];
  arr[row2] = temp;
}

void sortRows(int** arr, const int col1, const int col2, const int col3,
              const int rows) {
  bool is_swapped;
  do {
    is_swapped = false;

    for (int i = 0; i + 1 < rows; i++) {
      if ((arr[i][col1] > arr[i + 1][col1]) ||

          (arr[i][col1] == arr[i + 1][col1] &&
           arr[i][col2] < arr[i + 1][col2]) ||

          (arr[i][col1] == arr[i + 1][col1] &&
           arr[i][col2] == arr[i + 1][col2] &&
           arr[i][col3] > arr[i + 1][col3])) {
        rearrange(arr, i, i + 1);
        is_swapped = true;
      }
    }
  } while (is_swapped);
}

int countElements(int** arr, const int rows, const int cols) {
  int count = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
        count++;
      }
    }
  }

  return count;
}

int calcSum(int** arr, const int rows, const int cols) {
  int s = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
        s += arr[i][j];
      }
    }
  }

  return s;
}

void replaceWithZero(int** arr, const int rows, const int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(arr[i][j] > 0 && arr[i][j] % 5 == 0)) {
        arr[i][j] = 0;
      }
    }
  }
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

  fillMatrix(T, rows, cols, min_n, max_n);
  printMatrix(T, rows, cols);

  sortRows(T, 0, 1, 2, rows);
  printMatrix(T, rows, cols);

  cout << "\nCount = " << countElements(T, rows, cols) << "\n";
  cout << "Sum = " << calcSum(T, rows, cols) << "\n";

  replaceWithZero(T, rows, cols);
  printMatrix(T, rows, cols);

  for (int i = 0; i < rows; i++) {
    delete[] T[i];
  }
  delete[] T;

  return 0;
}
#endif