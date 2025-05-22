#include <iostream>
#include <time.h>
#include <random>
using namespace std;

int calculate(int a, int b, int c) { return a + b + c; }

double calculate(double a, double b) { return a - b; }

int main() {
  srand(time(NULL));

  double d1 = 0.0 + (double)rand() / RAND_MAX * (100.0 - 0.0);
  double d2 = 0.0 + (double)rand() / RAND_MAX * (100.0 - 0.0);

  int sum = calculate(rand() % 100, random() % 100, rand() % 100);
  cout << "Сумма целых чисел: " << sum << endl;

  double diff = calculate(d1, d2);
  cout << "Разность double чисел: " << diff << endl;

  return 0;
}