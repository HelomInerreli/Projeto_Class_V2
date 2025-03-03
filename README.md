# Project_v2

This is a store management project that allows you to add customers, store products, and perform random draws.

## Project Structure

```plaintext
Project_v2/
├── include/
│   ├── Auxiliares.h
│   ├── Cliente.h
│   ├── Loja.h
│   ├── Produto.h
│   └── Relatorio.h
├── src/
│   ├── Auxiliares.cpp
│   ├── Cliente.cpp
│   ├── Loja.cpp
│   ├── Produto.cpp
│   └── Relatorio.cpp
├── main.cpp
├── .vscode/
│   ├── launch.json
│   ├── settings.json
│   └── tasks.json
├── .ignore
└── README.md
```

## Compilation and Execution

To compile and run the project, use the following commands:

```bash
g++ -o main src/Loja.cpp src/Cliente.cpp src/Relatorio.cpp src/Produto.cpp src/Auxiliares.cpp main.cpp -I include
./main
```

## Features

### Customers

- Add customer
- Show customers

### Products

- Store product
- Search product
- Print stock
- Remove product

### Draw

- Perform random draw

## Classes

### Store

Implemented in `Loja.h` and `Loja.cpp`.

### Customer

Implemented in `Cliente.h` and `Cliente.cpp`.

### Product

Implemented in `Produto.h` and `Produto.cpp`.

### Report

Implemented in `Relatorio.h` and `Relatorio.cpp`.

### Helpers

Implemented in `Auxiliares.h` and `Auxiliares.cpp`.

## Authors

Helom Valentim and Ivo Teixeira

<img alt="GitHub" src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&amp;logo=github&amp;logoColor=white">
<img alt="C++" src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&amp;logo=cplusplus&amp;logoColor=white">
<img alt="VS Code" src="https://img.shields.io/badge/VS Code-007ACC?style=for-the-badge&amp;logo=visual-studio-code&amp;logoColor=white">
