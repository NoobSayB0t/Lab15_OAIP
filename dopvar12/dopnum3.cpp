#include <iostream>
#include <chrono>
using namespace std;

int arrLength = 0;

void fillRandomArray(int length, int data[]) {
    for (int i = 0; i != length; ++i) {
        data[i] = rand() % 1000;
    }
}

void insertionSort(int data[], int length) {
    int temp = 0;
    for (int i = 0; i != length; ++i) {
        temp = data[i];
        for (int j = i - 1; j >= 0; --j) {
            if (data[j] > temp) {
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите размер массива: ";
    cin >> arrLength;

    int data[10000];
    fillRandomArray(arrLength, data);

    cout << "Исходный массив:" << endl;
    for (int i = 0; i != arrLength; ++i) {
        cout << data[i] << " ";
    }

    auto startTime = chrono::steady_clock::now();
    insertionSort(data, arrLength);
    auto endTime = chrono::steady_clock::now();
    auto sortTime = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    cout << endl << endl << "Отсортированный массив:" << endl;
    for (int i = 0; i != arrLength; ++i) {
        cout << data[i] << " ";
    }

    cout << endl << endl << "Время выполнения сортировки: "
        << sortTime.count() << " мкс" << endl;
}