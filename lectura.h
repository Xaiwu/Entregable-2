#ifndef LECTURA_H
#define LECTURA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>


// Declaración de la función para leer el arreglo desde archivo binario
std::vector<int32_t> leer_arreglo(const std::string& nombre_archivo);

#endif // LECTURA_H