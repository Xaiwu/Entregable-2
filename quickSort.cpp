#include "quickSort.h"

// Realiza la partición del arreglo usando un pivote, colocando los menores a la izquierda y 
// los mayores a la derecha
int partition(std::vector<int32_t>& arr, int low, int high) {
    int32_t pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Ordena el vector usando QuickSort de manera iterativa, usa una pila para simular las llamadas recursivas.
void quickSort(std::vector<int32_t>& arr) {
    if (arr.empty()) return;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, static_cast<int>(arr.size()) - 1});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        if (low < high) {
            int pi = partition(arr, low, high);
            if (pi + 1 < high)
                stack.push({pi + 1, high});
            if (low < pi - 1)
                stack.push({low, pi - 1});
        }
    }
}