#include <iostream>
using namespace std;

// Функция для нахождения суммы трех целых чисел
int calculate(int a, int b, int c) { return a + b + c; }

// Функция для нахождения разности двух чисел
double calculate(double a, double b) { return a - b; }

int main() {
  // Вызов функции для трех целых чисел
  int sum = calculate(5, 3, 7);
  cout << "Сумма трех целых чисел: " << sum << endl;

  // Вызов функции для двух вещественных чисел
  double diff = calculate(9.5, 3.2);
  cout << "Разность двух вещественных чисел: " << diff << endl;

  return 0;
}
