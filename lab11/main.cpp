#include <iostream>
using namespace std;

template <class T> void bubbleSort(T arr[], int size) {
  bool swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        T temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int main() {
  // Пример с целыми числами
  int intArr[] = {5, 1, 4, 2, 8};
  int intSize = sizeof(intArr) / sizeof(intArr[0]);

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

  // Пример с дробными числами
  double doubleArr[] = {3.3, 1.1, 4.4, 2.2, 5.5};
  int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

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

  return 0;
}
