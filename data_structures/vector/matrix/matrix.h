//
// Created by Кирилл on 15.03.2024.
//

#ifndef BASICSOFPROGRAMMING_MATRIX_H
#define BASICSOFPROGRAMMING_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//функция для размещения в динамической памяти матриц
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под хранение матрицы m. Процесс освобождения изображен на рисунке .
void freeMemMatrix(matrix *m);

// освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);
#endif //BASICSOFPROGRAMMING_MATRIX_H
