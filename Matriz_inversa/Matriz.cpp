#include "Matriz.h"
Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            // Inicializamos con valores que no sean cuadrados mágicos
            this->matriz[i][j] = (i * j);
        }
    }
}

Matriz::Matriz(const std::string& orig) {
    try {
        Matriz();
        std::string linea(orig.c_str());
        if (!linea.empty()) {
            // Quitamos caracters innecesarios
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());

            // Obtenemos un token
            std::replace(linea.begin(), linea.end(), ';', ' ');


            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            for (int i = 0; i < LARGO; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
                }

                for (int j = 0; j < LARGO; j++) {
                    std::string valor = columnas[j];
                    int numero = atoi(valor.c_str());
                    this->matriz[i][j] = numero;
                }
            }
        }
    } catch (...) {
        Matriz();
    }
}

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
}

Matriz::~Matriz() {
}

void Matriz::sacar_inversa() {
    float determinante;
    determinante = (this->matriz[0][0]*this->matriz[1][1]*this->matriz[2][2]) + (this->matriz[0][1]*this->matriz[1][2]*this->matriz[2][0])  + (this->matriz[0][2]*this->matriz[1][0]*this->matriz[2][1]) - (this->matriz[0][2]*this->matriz[1][1]*this->matriz[2][0]) - (this->matriz[0][0]*this->matriz[1][2]*this->matriz[2][1]) - (this->matriz[0][1]*this->matriz[1][0]*this->matriz[2][2]);          
    float matriz_adjunta[3][3];
    matriz_adjunta[0][0] = (this->matriz[1][1] * this->matriz[2][2]) - (this->matriz[2][1] * this->matriz[1][2]);
    matriz_adjunta[0][1] = ((this->matriz[1][0] * this->matriz[2][2]) -(this->matriz[2][0] * this->matriz[1][2]))*-1;
    matriz_adjunta[0][2] = (this->matriz[1][0] * this->matriz[2][1]) - (this->matriz[2][0] * this->matriz[1][1]);
    matriz_adjunta[1][0] = ((this->matriz[0][1] * this->matriz[2][2]) -(this->matriz[2][1] * this->matriz[0][2]))*-1;
    matriz_adjunta[1][1] = (this->matriz[0][0] * this->matriz[2][2]) - (this->matriz[2][0] * this->matriz[0][2]);
    matriz_adjunta[1][2] = ((this->matriz[0][0] * this->matriz[2][1]) -(this->matriz[2][0] * this->matriz[0][1]))*-1;
    matriz_adjunta[2][0] = (this->matriz[0][1] * this->matriz[1][2]) - (this->matriz[1][1] * this->matriz[0][2]);
    matriz_adjunta[2][1] = ((this->matriz[0][0] * this->matriz[1][2]) -(this->matriz[1][0] * this->matriz[0][2]))*-1;
    matriz_adjunta[2][2] = (this->matriz[0][0] * this->matriz[1][1]) - (this->matriz[1][0] * this->matriz[0][1]);
    float matriz_traspuesta[3][3];
    for (int fila=0; fila<3;fila++){
        for (int columna=0; columna<3;columna++){
            matriz_traspuesta[fila][columna]=matriz_adjunta[columna][fila];
        }
    }
    for (int fila=0; fila<3;fila++){
        for (int columna=0; columna<3;columna++){
            matriz_inversa[fila][columna] = (matriz_traspuesta[fila][columna]/determinante);
        }
    }
}

std::string Matriz::toString() {
    std::stringstream ss;
    ss << '[' << this->matriz_inversa[0][0] << ',' << this->matriz_inversa[0][1] << ',' << this->matriz_inversa[0][2] << ';' << this->matriz_inversa[1][0] << ',' << matriz_inversa[1][1] << ',' << this->matriz_inversa[1][2] << ';' << this->matriz_inversa[2][0] << ',' << this->matriz_inversa[2][1] << ',' << this->matriz_inversa[2][2] << ']' << std::endl;
    return ss.str();
}
