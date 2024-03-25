//
// Created by Кирилл on 15.03.2024.
//

#include "matrix.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}


void freeMemMatrix(matrix *m) {
    for (int i = 0; m->nRows < i; i++) {
        free(m->values[i]);

    }
    free(m->values);
    m->values=NULL;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
        ms->values[i]=NULL;
    }
    free(ms);
    ms->values=NULL;
}


void inputMatrix(matrix *m) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("Enter elements for matrix %d:\n", i + 1);
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    printf("Matrix:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("Matrix %d:\n", i + 1);
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.nCols && j2 >= 0 && j2 < m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *rowValues = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        rowValues[i] = criteria(m.values[i], m.nCols);
    }
    // Сортировка вставками
    for (int i = 1; i < m.nRows; i++) {
        int key = rowValues[i];
        int *tempRow = m.values[i];
        int j = i - 1;
        while (j >= 0 && rowValues[j] > key) {
            rowValues[j + 1] = rowValues[j];
            m.values[j + 1] = m.values[j];
            j = j - 1;
        }
        rowValues[j + 1] = key;
        m.values[j + 1] = tempRow;
    }
    free(rowValues);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *colValues = (int *) malloc(sizeof(int) * m.nCols);
    // Вычисление значения критерия для каждого столбца
    for (int j = 0; j < m.nCols; j++) {
        int *column = (int *) malloc(sizeof(int) * m.nRows);
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][j];
        }
        colValues[j] = criteria(column, m.nRows);
        free(column);
    }
    // Сортировка выбором
    for (int i = 0; i < m.nCols - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (colValues[j] < colValues[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Обмен столбцов
            for (int k = 0; k < m.nRows; k++) {
                int temp = m.values[k][i];
                m.values[k][i] = m.values[k][minIndex];
                m.values[k][minIndex] = temp;
            }
            int tempValue = colValues[i];
            colValues[i] = colValues[minIndex];
            colValues[minIndex] = tempValue;
        }
    }
    free(colValues);
}

// Предикат: является ли матрица квадратной
bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

// Предикат: равны ли две матрицы
bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    // Проверка размеров матриц
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols) {
        return false;
    }

    // Сравнение содержимого матриц с помощью memcmp
    size_t size = sizeof(int *) * m1->nRows;
    for (int i = 0; i < m1->nRows; i++) {
        if (memcmp(m1->values[i], m2->values[i], sizeof(int) * m1->nCols) != 0) {
            return false;
        }
    }

    return true;
}

// Предикат: является ли матрица единичной
bool isEMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {
        return false;
    }
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            if (i == j && m->values[i][j] != 1) {
                return false;
            } else if (i != j && m->values[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Предикат: является ли матрица симметричной
bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {
        return false;
    }
    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            if (m->values[i][j] != m->values[j][i]) {
                return false;
            }
        }
    }
    return true;
}


void transposeSquareMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {

        return;
    }
    for (int i = 0; i < m->nRows; i++) {
        for (int j = i + 1; j < m->nCols; j++) {

            int temp = m->values[i][j];
            m->values[i][j] = m->values[j][i];
            m->values[j][i] = temp;
        }
    }
}

void transposeMatrix(matrix *m) {

    matrix result = getMemMatrix(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {

            result.values[j][i] = m->values[i][j];
        }
    }

    freeMemMatrix(m);

    *m = result;
}

position getMinValuePos(matrix m) {
    position minPos;
    minPos.rowIndex = 0;
    minPos.colIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {

            if (m.values[i][j] < m.values[minPos.rowIndex][minPos.colIndex]) {
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }
        }
    }
    return minPos;
}


position getMaxValuePos(matrix m) {
    position maxPos;
    maxPos.rowIndex = 0;
    maxPos.colIndex = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {

            if (m.values[i][j] > m.values[maxPos.rowIndex][maxPos.colIndex]) {
                maxPos.rowIndex = i;
                maxPos.colIndex = j;
            }
        }
    }
    return maxPos;
}

matrix createMatrixFromArray(const int *a,

                             int nRows, int nCols) {

    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

