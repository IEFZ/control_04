# Control-04-Paralela
Control N° 4 del ramo computación paralela y distribuda

# Instalación

1. Instalar compilador C++

```$ sudo apt install g++```

2. Instalar OpenMP 

```$ sudo apt install libomp-dev```

3. Clonar proyecto

```$ git clone https://github.com/IEFZ/control_04.git```

Para la implementación en forma secuencial

```$ cd Matriz_inversa```

Para la implementación en forma paralela (openmp)

```$ cd Matriz_inversa_openmp```

4. Ejecución

```$ make```

```$ ./dist/programa -f datos.txt -o salida.txt```

donde datos.txt puede ser cualquier archivo txt con otro nombre que este colocado en la carpeta correspondiente


Nota: Si se desea comprobar si se estan usando los procesadores en forma paralela instale y ejecute lo siguiente en una nueva terminal

```$ sudo apt install htop```

```$ htop```
