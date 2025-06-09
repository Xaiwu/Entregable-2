#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

// Función para generar datos aleatorios
void generar_desordenado(const std::string& nombre, int cantidad) {
    std::ofstream archivo(nombre, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int32_t> dist(-1000000, 1000000);

    for (int i = 0; i < cantidad; ++i) {
        int32_t num = dist(rng);
        archivo.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    archivo.close();
}

// Función para generar datos ordenados ascendentemente
void generar_ascendente(const std::string& nombre, int cantidad) {
    std::ofstream archivo(nombre, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    int32_t min = -cantidad;
    int32_t max = 0;

    if (cantidad == 1) {
        archivo.write(reinterpret_cast<char*>(&min), sizeof(min));
    } else {
        int64_t rango = int64_t(max) - int64_t(min);
        int64_t paso = rango / (cantidad - 1);
        int64_t valor = min;
        for (int i = 0; i < cantidad; ++i) {
            int32_t v = static_cast<int32_t>(valor);
            archivo.write(reinterpret_cast<char*>(&v), sizeof(v));
            valor += paso;
        }
    }

    archivo.close();
}

// Función para generar datos ordenados descendentemente
void generar_descendente(const std::string& nombre, int cantidad) {
    std::vector<int32_t> arr(cantidad);
    int32_t min = -cantidad;
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
        return;
    }

    archivo.write(reinterpret_cast<char*>(arr.data()), cantidad * sizeof(int32_t));
    archivo.close();
}

// Función para generar parcialmente ordenado
void generar_parcialmente_ordenado(const std::string& nombre, int cantidad, double porcentaje) {
    std::vector<int32_t> arr(cantidad);
    int32_t min = -cantidad;
    int32_t max = 0;
    int64_t rango = int64_t(max) - int64_t(min);
    int64_t paso = rango / (cantidad - 1);
    int64_t valor = min;
    for (int i = 0; i < cantidad; ++i) {
        arr[i] = static_cast<int32_t>(valor);
        valor += paso;
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    int swaps = static_cast<int>(cantidad * porcentaje);

    for (int i = 0; i < swaps; ++i) {
        int idx1 = rng() % cantidad;
        int idx2 = rng() % cantidad;
        std::swap(arr[idx1], arr[idx2]);
    }

    std::ofstream archivo(nombre, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    archivo.write(reinterpret_cast<char*>(arr.data()), cantidad * sizeof(int32_t));
    archivo.close();
}



int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " tipo nombre_archivo cantidad [porcentaje]\n";
        std::cerr << "Tipos: asc | desc | desordenado | parcial \n";
        return 1;
    }

    std::string tipo = argv[1];
    std::string nombre = argv[2];
    int cantidad = std::stoi(argv[3]);
    double porcentaje = (argc >= 5) ? std::stod(argv[4]) : 0.0;

    if (tipo == "asc") {
        generar_ascendente(nombre, cantidad);
    } else if (tipo == "desc") {
        generar_descendente(nombre, cantidad);
    } else if (tipo == "desordenado") {
        generar_desordenado(nombre, cantidad);
    } else if (tipo == "parcial") {
        if (porcentaje <= 0.0 || porcentaje > 1.0) porcentaje = 0.01;
        generar_parcialmente_ordenado(nombre, cantidad, porcentaje);
    } else {
        std::cerr << "Tipo desconocido: " << tipo << "\n";
        return 1;
    }

    std::cout << "Archivo " << nombre << " generado correctamente con tipo " << tipo << ".\n";
    return 0;
}
