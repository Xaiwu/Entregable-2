#include "lectura.h" 

// int main() {
//     std::vector<int32_t> arr = leer_arreglo("50MB.lcp");
//     std::cout << "Cantidad de elementos: " << arr.size() << std::endl;
    // for (int i = 0; i < 30 && i < arr.size(); ++i)
    //     std::cout << arr[i] << " ";
//     std::cout << std::endl;
//     return 0;
// }


int main() {
    std::vector<int32_t> arr = leer_arreglo("1MB.lcp");
    int en_orden = 0;
    int total = arr.size() - 1;

    for (int i = 0; i < total; ++i) {
        if (arr[i] <= arr[i + 1]) en_orden++;
    }
    for (int i = 0; i < 500 && i < arr.size(); ++i)
        std::cout << arr[i] << " ";

    double porcentaje = 100.0 * en_orden / total;
    std::cout << "Porcentaje de pares consecutivos en orden: " << porcentaje << "%" << std::endl;
    return 0;
}