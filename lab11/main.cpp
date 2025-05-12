#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <class T> void bubbleSort(T *arrayPtr, int arrSize) {
  T temp = 0;
  bool exit = false;

  while (!exit) {
    exit = true;
    for (int counter = 0; counter < (arrSize - 1); counter++) {
      if (arrayPtr[counter] > arrayPtr[counter + 1]) {
        temp = arrayPtr[counter];
        arrayPtr[counter] = arrayPtr[counter + 1];
        arrayPtr[counter + 1] = temp;
        exit = false;
      }
    }
  }
}

int main() {
  srand(time(0));

  // Пример с целыми числами
  int intSize = 5;
  int *intArr = new int[intSize];
  for (int i = 0; i < intSize; i++) {
    intArr[i] = rand() % 20;
  }

  cout << "До (int): ";
  for (int i = 0; i < intSize; i++) {
    cout << intArr[i] << " ";
  }
  cout << endl;

  bubbleSort(intArr, intSize);

  cout << "После (int): ";
  for (int i = 0; i < intSize; i++) {
    cout << intArr[i] << " ";
  }
  cout << endl << endl;

  delete[] intArr;

  // Пример с дробными числами
  int doubleSize = 5;
  double *doubleArr = new double[doubleSize];
  for (int i = 0; i < doubleSize; i++) {
    doubleArr[i] = (rand() % 10000) / 100.0;
  }

  cout << "До (double): ";
  for (int i = 0; i < doubleSize; i++) {
    cout << doubleArr[i] << " ";
  }
  cout << endl;

  bubbleSort(doubleArr, doubleSize);

  cout << "После (double): ";
  for (int i = 0; i < doubleSize; i++) {
    cout << doubleArr[i] << " ";
  }
  cout << endl;

  delete[] doubleArr;

  return 0;
}
