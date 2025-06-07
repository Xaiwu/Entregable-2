#include <iostream>
#include <fstream>
#include <cstdint>
#include <random>

//areglos desordenados
// int main(int argc, char* argv[]) {
//     // Uso: generar_desordenado.cpp nombre_archivo cantidad
//     std::string nombre = "desordenado.lcp";
//     int cantidad = 10000;
//     if (argc >= 2) nombre = argv[1];
//     if (argc >= 3) cantidad = std::stoi(argv[2]);

//     std::ofstream archivo(nombre, std::ios::binary);
//     if (!archivo) {
//         std::cerr << "No se pudo crear el archivo." << std::endl;
//         return 1;
//     }

//     std::random_device rd;
//     std::mt19937 rng(rd());
//     std::uniform_int_distribution<int32_t> dist(-1000000, 1000000);

//     for (int i = 0; i < cantidad; ++i) {
//         int32_t num = dist(rng);
//         archivo.write(reinterpret_cast<char*>(&num), sizeof(num));
//     }

//     archivo.close();
//     std::cout << "Archivo " << nombre << " generado con " << cantidad << " enteros desordenados." << std::endl;
//     return 0;
// }

// // Arreglos ordenados ascendentemente
// int main(int argc, char* argv[]) {
//     // Uso: generar_ascendente.exe nombre_archivo cantidad
//     std::string nombre = "ascendente.lcp";
//     int cantidad = 26214400; // Por defecto, 26,214,400
//     if (argc >= 2) nombre = argv[1];
//     if (argc >= 3) cantidad = std::stoi(argv[2]);

//     std::ofstream archivo(nombre, std::ios::binary);
//     if (!archivo) {
//         std::cerr << "No se pudo crear el archivo." << std::endl;
//         return 1;
//     }

//     int32_t min = -26214400;
//     int32_t max = 0;
//     if (cantidad == 1) {
//         archivo.write(reinterpret_cast<char*>(&min), sizeof(min));
//     } else {
//         int64_t rango = int64_t(max) - int64_t(min);
//         int64_t paso = rango / (cantidad - 1);
//         int64_t valor = min;
//         for (int i = 0; i < cantidad; ++i) {
//             int32_t v = static_cast<int32_t>(valor);
//             archivo.write(reinterpret_cast<char*>(&v), sizeof(v));
//             valor += paso;
//         }
//     }

//     archivo.close();
//     std::cout << "Archivo " << nombre << " generado con " << cantidad << " enteros ascendentes." << std::endl;
//     return 0;
// }

// // Parcialmente
// int main(int argc, char* argv[]) {
//     // Uso: generar_parcialmente_ordenado.exe nombre_archivo cantidad porcentaje_desorden
//     std::string nombre = "parcialmente_ordenado.lcp";
//     int cantidad = 26214400; // Por defecto, 26,214,400
//     double porcentaje_desorden = 0.30; // 5% desordenado por defecto

//     if (argc >= 2) nombre = argv[1];
//     if (argc >= 3) cantidad = std::stoi(argv[2]);
//     if (argc >= 4) porcentaje_desorden = std::stod(argv[3]);

//     std::vector<int32_t> arr(cantidad);
//     int32_t min = -26214400;
//     int32_t max = 0;
//     int64_t rango = int64_t(max) - int64_t(min);
//     int64_t paso = rango / (cantidad - 1);
//     int64_t valor = min;
//     for (int i = 0; i < cantidad; ++i) {
//         arr[i] = static_cast<int32_t>(valor);
//         valor += paso;
//     }

//     // Desordenar un porcentaje de elementos
//     std::random_device rd;
//     std::mt19937 rng(rd());
//     int swaps = static_cast<int>(cantidad * porcentaje_desorden);

//     for (int i = 0; i < swaps; ++i) {
//         int idx1 = rng() % cantidad;
//         int idx2 = rng() % cantidad;
//         std::swap(arr[idx1], arr[idx2]);
//     }

//     std::ofstream archivo(nombre, std::ios::binary);
//     if (!archivo) {
//         std::cerr << "No se pudo crear el archivo." << std::endl;
//         return 1;
//     }
//     archivo.write(reinterpret_cast<char*>(arr.data()), cantidad * sizeof(int32_t));
//     archivo.close();

//     std::cout << "Archivo " << nombre << " generado con " << cantidad << " enteros parcialmente ordenados (" << (porcentaje_desorden * 100) << "% desordenados)." << std::endl;
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

int main(int argc, char* argv[]) {
    // Uso: generar_descendente.exe nombre_archivo cantidad
    std::string nombre = "descendente.lcp";
    int cantidad = 26214400; // Por defecto, 26,214,400
    if (argc >= 2) nombre = argv[1];
    if (argc >= 3) cantidad = std::stoi(argv[2]);

    std::vector<int32_t> arr(cantidad);
    int32_t min = -26214400;
    int32_t max = 0;
    int64_t rango = int64_t(max) - int64_t(min);
    int64_t paso = rango / (cantidad - 1);
    int64_t valor = max;
    for (int i = 0; i < cantidad; ++i) {
        arr[i] = static_cast<int32_t>(valor);
        valor -= paso;
    }

    std::ofstream archivo(nombre, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return 1;
    }
    archivo.write(reinterpret_cast<char*>(arr.data()), cantidad * sizeof(int32_t));
    archivo.close();

    std::cout << "Archivo " << nombre << " generado con " << cantidad << " enteros descendentes." << std::endl;
    return 0;
}