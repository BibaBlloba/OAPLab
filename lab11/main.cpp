#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <class T> void bubbleSort(T *arrayPtr, int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arrayPtr[j] > arrayPtr[j + 1]) {
                T temp = arrayPtr[j];
                arrayPtr[j] = arrayPtr[j + 1];
                arrayPtr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));

    // целые числа
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

    // дробные числа
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