#include "lectura.h"

std::vector<int32_t> leer_arreglo(const std::string& nombre_archivo) {
    std::vector<int32_t> arreglo;
    std::ifstream archivo(nombre_archivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombre_archivo << std::endl;
        return arreglo;
    }
    int32_t numero;
    while (archivo.read(reinterpret_cast<char*>(&numero), sizeof(numero))) {
        arreglo.push_back(numero);
    }
    return arreglo;
}

