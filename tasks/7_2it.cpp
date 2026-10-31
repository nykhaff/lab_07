// 7_2it.cpp
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

int calcMinSum(int** arr, const int rows, const int cols) {
  int result = 0;  // для обчислення суми
  int min_number;  // для знаходження мінімального значення в ряду

  for (int i = 0; i < rows; i++) {
    min_number = arr[i][0];

    for (int j = 1; j < cols; j++) {
      if (arr[i][j] < min_number) {
        min_number = arr[i][j];
      }
    }

    result += min_number;
  }

  return result;
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

  fillMatrix(M, k, n, -20, 20);
  printMatrix(M, k, n);

  cout << "\nSum of the smalest numbers on each row: " << calcMinSum(M, k, n);

  for (int i = 0; i < k; i++) {
    delete[] M[i];
  }
  delete[] M;

  return 0;
}
#endif