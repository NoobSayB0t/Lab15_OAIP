void shellSort(int data[], int length) {
    // Начинаем с большого промежутка, затем уменьшаем его
    for (int gap = length/2; gap > 0; gap /= 2) {
        // Делаем сортировку вставками для этого промежутка
        for (int i = gap; i < length; i++) {
            int temp = data[i]; // Запоминаем текущий элемент
            int j;
            // Сдвигаем элементы, пока не найдем место для вставки
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            // Вставляем сохраненный элемент в правильное место
            data[j] = temp;
        }
    }
}
