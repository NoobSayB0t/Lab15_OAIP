#include <iostream>
#include <chrono>
using namespace std;

int arraySize = 0;

void generateRandomArray(int size, int numbers[]) {
    for (int i = 0; i != size; ++i) {
        numbers[i] = rand() % 1000;
    }
}

void selectionSort(int numbers[], int size) {
    int minPos = 0;
    int temp = 0;
    for (int i = 0; i != size; ++i) {
        minPos = i;
        for (int j = i; j < size; ++j) {
            if (numbers[j] < numbers[minPos]) {
                minPos = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[minPos];
        numbers[minPos] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите размер массива: ";
    cin >> arraySize;

    int numbers[10000];
    generateRandomArray(arraySize, numbers);

    cout << "Исходный массив:" << endl;
    for (int i = 0; i != arraySize; ++i) {
        cout << numbers[i] << " ";
    }

    auto startTime = chrono::steady_clock::now();
    selectionSort(numbers, arraySize);
    auto endTime = chrono::steady_clock::now();
    auto sortTime = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    cout << endl << endl << "Отсортированный массив:" << endl;
    for (int i = 0; i != arraySize; ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl << endl << "Время выполнения сортировки: "
        << sortTime.count() << " мкс" << endl;
}