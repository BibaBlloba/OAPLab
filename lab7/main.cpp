#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <random>
using namespace std;

const int C = 5;

/// Генерация матрицы
void inparr(int M[4][5]) {
	cout << "Задан массив: \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			M[i][j] = -10 + rand() % 21;
			cout << setw(4) << M[i][j];
		}	
		cout << "\n";
	}
	
}

/// Умножение матрицы
void processparr(int M[4][5]) {
	cout << "\n\n";
	int D[4][5];
	cout << "Массив, умноженный на константу (" << C << "): \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			D[i][j] = M[i][j] * C;
			cout << setw(4) << D[i][j];
		}
		cout << "\n";
	}
	cout << "\n\n";
}

/// Главная функция
int main() {
    srand(time(NULL));
	setlocale(0, "");
	int D[4][5];
	inparr(D);
	processparr(D);
}