# 📝 get_next_line – 42 Barcelona

[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Project: 42](https://img.shields.io/badge/42%20Network-get_next_line-1f425f.svg)](https://42.fr/)
[![Status: Completed](https://img.shields.io/badge/status-completed-brightgreen)](https://github.com/)
[![License: Custom](https://img.shields.io/badge/license-42%20School%20Policy-lightgrey)](https://42.fr/)

---

## 🌐 English Description

**get_next_line** is a C function designed to read a line from a file descriptor, returning the line each time it's called until the end of the file is reached. The function uses a static variable to store the remaining data between successive calls, allowing it to remember the position in the file.

### Key Features:
- **Static Variable:** The function stores leftover data in a static variable, ensuring that each successive call picks up where the last one left off.
- **Buffer Size:** The function reads data in chunks defined by a buffer size (BUFFER_SIZE). This can be adjusted to optimize performance depending on the specific use case.
- **Memory Management:** Each line read is dynamically allocated, and memory is freed once the line is no longer needed, preventing memory leaks.

The function continues reading from the file descriptor until a newline character (`\n`) is found or the end of the file is reached.

> ✅ **Status:** This repository is complete and will not receive further updates.
---

## 🇪🇸 Descripción en Español

**get_next_line** es una función en C diseñada para leer una línea desde un descriptor de archivo, devolviendo la línea cada vez que se llama hasta que se alcance el final del archivo. La función utiliza una variable estática para almacenar los datos restantes entre llamadas sucesivas, lo que le permite recordar la posición en el archivo.

### Características Principales:
- **Variable Estática:** La función almacena los datos restantes en una variable estática, asegurando que cada llamada sucesiva continúe desde donde la anterior dejó.
- **Tamaño del Búfer:** La función lee los datos en bloques definidos por un tamaño de búfer (BUFFER_SIZE), lo que puede ajustarse para optimizar el rendimiento según el caso de uso.
- **Gestión de Memoria:** Cada línea leída se asigna dinámicamente, y la memoria se libera una vez que la línea ya no se necesita, previniendo fugas de memoria.

La función sigue leyendo del descriptor de archivo hasta que se encuentra con un carácter de nueva línea (`\n`) o se alcanza el final del archivo.

> ✅ **Estado:** Este repositorio está finalizado y no recibirá más actualizaciones.

---

```bash
git clone https://github.com/ineiras/get_next_line.git
cd get_next_line
make
