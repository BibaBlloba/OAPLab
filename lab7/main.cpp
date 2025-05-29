#include <iomanip>
#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>
using namespace std;

// Генерация матрицы
void inparr(int **matr, int rows, int cols) {
  cout << "Заполненная матрица " << rows << "x" << cols << ":\n";
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matr[i][j] = -10 + rand() % 21; // числа от -10 до 10
      cout << setw(4) << matr[i][j];
    }
    cout << "\n";
  }
}

// Умножение матрицы
void processparr(int **matr, int rows, int cols, int C) {
  cout << "\nМатрица после умножения на " << C << ":\n";
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << setw(4) << matr[i][j] * C;
    }
    cout << "\n";
  }
}

// Отчистка
void freematr(int **matr, int rows) {
  for (int i = 0; i < rows; ++i) {
    delete[] matr[i];
  }
  delete[] matr;
}

// Главная функция
int main() {
  srand(time(NULL));
  setlocale(0, "");
  int rows, cols;

  cout << "Введите строки --> ";
  cin >> rows;
  cout << "Введите столбцы --> ";
  cin >> cols;

  int **matr = new int *[rows];
  for (int i = 0; i < rows; ++i) {
    matr[i] = new int[cols];
  }

  inparr(matr, rows, cols);
  processparr(matr, rows, cols, 5);
  freematr(matr, rows);

  return 0;
}
