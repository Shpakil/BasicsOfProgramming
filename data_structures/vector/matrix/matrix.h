//
// Created by Кирилл on 15.03.2024.
//

#ifndef BASICSOFPROGRAMMING_MATRIX_H
#define BASICSOFPROGRAMMING_MATRIX_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

//ввод матрицы
void inputMatrix(matrix *m);

//ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m.
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2);

//Функция для сортировки выбором столбцов матрицы по критерию
void  insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

//Функция для сортировки выбором столбцов матрицы по критерию
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int));

//является ли матрица квадратной
bool isSquareMatrix(matrix *m) ;

//равны ли две матрицы
bool areTwoMatricesEqual(matrix *m1, matrix *m2) ;

//является ли матрица единичной
bool isEMatrix(matrix *m);

//является ли матрица симметричной
bool isSymmetricMatrix(matrix *m) ;

// Транспонирование квадратной матрицы
void transposeSquareMatrix(matrix *m);

// Транспонирование матрицы
void transposeMatrix(matrix *m);

// Поиск позиции минимального элемента матрицы
position getMinValuePos(matrix m);

// Поиск позиции максимального элемента матрицы
position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);
#endif //BASICSOFPROGRAMMING_MATRIX_H
