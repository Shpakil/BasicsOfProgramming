#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "data_structures/vector/vector.h"
#include "data_structures/vector/vectorVoid.h"
#include "data_structures/vector/matrix/matrix.h"


// Примеры функций-критериев для сортировок
int sumCriterion(int *row, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += row[i];
    }
    return sum;
}

int maxElementCriterion(int *row, int n) {
    int max = row[0];
    for (int i = 1; i < n; i++) {
        if (row[i] > max) {
            max = row[i];
        }
    }
    return max;
}

// Тесты для функций
void testGetMemMatrix() {

    matrix m = getMemMatrix(2, 3);
    assert(m.nRows == 2 && m.nCols == 3);
    freeMemMatrix(&m);
}

void testGetMemArrayOfMatrices() {

    matrix *ms = getMemArrayOfMatrices(3, 2, 2);
    assert(ms[0].nRows == 2 && ms[0].nCols == 2);
    freeMemMatrices(ms, 3);
}

void testFreeMemMatrix() {
    matrix m = getMemMatrix(2, 2);
    freeMemMatrix(&m);
    assert(m.values == NULL);
}

void testFreeMemMatrices() {
    matrix *ms = getMemArrayOfMatrices(3, 2, 2);
    freeMemMatrices(ms, 3);
    assert(ms[0].values == NULL);
}

void testSwapRows() {

    matrix m = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 3 && m.values[1][0] == 1);
    freeMemMatrix(&m);
}

void testSwapColumns() {

    matrix m = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    swapColumns(m, 0, 1);
    assert(m.values[0][0] == 2 && m.values[0][1] == 1);
    freeMemMatrix(&m);
}

void testInsertionSortRowsMatrixByRowCriteria() {

    matrix m = createMatrixFromArray((const int[]) {3, 1, 4, 2, 5, 6}, 2, 3);
    selectionSortColsMatrixByColCriteria(m, sumCriterion);
    assert(m.values[0][0] == 3 && m.values[0][1] == 1 && m.values[1][0] == 2);
    freeMemMatrix(&m);
}

void testSelectionSortColsMatrixByColCriteria() {

    matrix m = createMatrixFromArray((const int[]) {3, 1, 4, 2, 5, 6}, 2, 3);
    selectionSortColsMatrixByColCriteria(m, sumCriterion);
    assert(m.values[0][0] == 3 && m.values[1][0] == 2 && m.values[0][2] == 4);
    freeMemMatrix(&m);
}

void testIsSquareMatrix() {

    matrix m1 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((const int[]) {1, 2, 3, 4, 5, 6}, 2, 3);
    assert(isSquareMatrix(&m1) && !isSquareMatrix(&m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void testAreTwoMatricesEqual() {

    matrix m1 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    matrix m3 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    assert(areTwoMatricesEqual(&m1, &m2) && areTwoMatricesEqual(&m1, &m3));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
}

void testIsEMatrix() {
    printf("Running test for isEMatrix...\n");
    matrix m1 = createMatrixFromArray((const int[]) {1, 0, 0, 1}, 2, 2);
    matrix m2 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    assert(isEMatrix(&m1) && !isEMatrix(&m2) && "Failed to detect E matrix");
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void testIsSymmetricMatrix() {

    matrix m1 = createMatrixFromArray((const int[]) {1, 2, 2, 3}, 2, 2);
    matrix m2 = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    assert(isSymmetricMatrix(&m1) && !isSymmetricMatrix(&m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void testTransposeSquareMatrix() {

    matrix m = createMatrixFromArray((const int[]) {1, 2, 3, 4}, 2, 2);
    transposeSquareMatrix(&m);
    assert(m.values[0][1] == 3 && m.values[1][0] == 2);
    freeMemMatrix(&m);
}

void testTransposeMatrix() {

    matrix m = createMatrixFromArray((const int[]) {1, 2, 3, 4, 3, 4}, 2, 3);
    transposeMatrix(&m);
    assert(m.nRows == 3 && m.nCols == 2);
    freeMemMatrix(&m);
}

void testGetMinValuePos() {

    matrix m = createMatrixFromArray((const int[]) {3, 2, 1, 4}, 2, 2);
    position pos = getMinValuePos(m);
    assert(pos.rowIndex == 1 && pos.colIndex == 0);
    freeMemMatrix(&m);
}

void testGetMaxValuePos() {

    matrix m = createMatrixFromArray((const int[]) {3, 2, 1, 4}, 2, 2);
    position pos = getMaxValuePos(m);
    assert(pos.rowIndex == 1 && pos.colIndex == 1);
    freeMemMatrix(&m);
}


// Тест для функции getMemMatrix
void test_getMemMatrix() {
    int nRows = 3;
    int nCols = 3;
    matrix m = getMemMatrix(nRows, nCols);

    // Проверяем, что количество строк и столбцов равно ожидаемому
    assert(m.nRows == nRows);
    assert(m.nCols == nCols);

    // Проверяем, что все значения инициализированы нулем
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            assert(m.values[i][j] == 0);
        }
    }

    // Освобождаем память
    freeMemMatrix(&m);
}

// Тест для функции getMemArrayOfMatrices
void test_getMemArrayOfMatrices() {
    int nMatrices = 2;
    int nRows = 3;
    int nCols = 3;
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    // Проверяем, что массив матриц создан успешно
    assert(ms != NULL);

    // Проверяем каждую матрицу
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].nRows == nRows);
        assert(ms[i].nCols == nCols);
        // Проверяем, что все значения инициализированы нулем
        for (int j = 0; j < nRows; j++) {
            for (int k = 0; k < nCols; k++) {
                assert(ms[i].values[j][k] == 0);
            }
        }
    }

    // Освобождаем память
    freeMemMatrices(ms, nMatrices);
}

// Тест освобождения памяти для одной матрицы
void test_freeMemMatrix() {
    // Создаем тестовую матрицу
    matrix m;
    m.nRows = 2;
    m.nCols = 3;
    m.values = (int **) malloc(m.nRows * sizeof(int *));
    for (int i = 0; i < m.nRows; i++) {
        m.values[i] = (int *) malloc(m.nCols * sizeof(int));
    }

    // Освобождаем память
    freeMemMatrix(&m);

    // Проверяем, что память успешно освобождена
    assert(m.values == NULL);
}

// Тест освобождения памяти для массива матриц
void test_freeMemMatrices() {
    // Создаем тестовый массив матриц
    int nMatrices = 3;
    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
    for (int i = 0; i < nMatrices; i++) {
        ms[i].nRows = 2;
        ms[i].nCols = 3;
        ms[i].values = (int **) malloc(ms[i].nRows * sizeof(int *));
        for (int j = 0; j < ms[i].nRows; j++) {
            ms[i].values[j] = (int *) malloc(ms[i].nCols * sizeof(int));
        }
    }

    // Освобождаем память
    freeMemMatrices(ms, nMatrices);

    // Проверяем, что память успешно освобождена
    for (int i = 0; i < nMatrices; i++) {
        assert(ms[i].values == NULL);
    }
    assert(ms == NULL);
}

// Тест для функции swapRows
void test_swapRows() {
    matrix m = getMemMatrix(3, 3);
    // Начальные значения строк
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m.values[i][j] = i * m.nCols + j + 1;
        }
    }
    // Обмен первой и последней строки
    swapRows(m, 0, m.nRows - 1);
    assert(m.values[0][0] == 7 && m.values[0][1] == 8 && m.values[0][2] == 9);
    assert(m.values[m.nRows - 1][0] == 1 && m.values[m.nRows - 1][1] == 2 && m.values[m.nRows - 1][2] == 3);
    // Обмен второй и третьей строки
    swapRows(m, 1, 2);
    assert(m.values[1][0] == 4 && m.values[1][1] == 5 && m.values[1][2] == 6);
    assert(m.values[2][0] == 1 && m.values[2][1] == 2 && m.values[2][2] == 3);
    freeMemMatrix(&m);
}

// Тест для функции swapColumns
void test_swapColumns() {
    matrix m = getMemMatrix(3, 3);
    // Начальные значения столбцов
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m.values[i][j] = i * m.nCols + j + 1;
        }
    }
    // Обмен первого и последнего столбца
    swapColumns(m, 0, m.nCols - 1);
    assert(m.values[0][0] == 3 && m.values[1][0] == 6 && m.values[2][0] == 9);
    assert(m.values[0][m.nCols - 1] == 1 && m.values[1][m.nCols - 1] == 4 && m.values[2][m.nCols - 1] == 7);
    // Обмен второго и третьего столбца
    swapColumns(m, 1, 2);
    assert(m.values[0][1] == 9 && m.values[1][1] == 6 && m.values[2][1] == 3);
    assert(m.values[0][2] == 7 && m.values[1][2] == 4 && m.values[2][2] == 1);
    freeMemMatrix(&m);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0); // Создаем пустой вектор
    pushBack(&v, 42); // Добавляем элемент в пустой вектор
    assert(v.size == 1); // Проверяем, что размер стал равен 1
    assert(v.data[0] == 42); // Проверяем, что добавлен правильный элемент
    deleteVector(&v); // Освобождаем память, выделенную для вектора
}

void test_pushBack_fullVector() {
    vector v = createVector(1); // Создаем вектор с одним элементом
    pushBack(&v, 1); // Добавляем первый элемент
    pushBack(&v, 2); // Добавляем второй элемент
    assert(v.size == 2); // Проверяем, что размер стал равен 2
    assert(v.data[0] == 1); // Проверяем, что первый элемент сохранился
    assert(v.data[1] == 2); // Проверяем, что добавлен правильный второй элемент
    deleteVector(&v); // Освобождаем память, выделенную для вектора
}

void test_pushBack() {
    test_pushBack_fullVector();
    test_pushBack_emptyVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 30);
    int *element = atVector(&v, 1);
    assert(*element == 20);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 30);
    int *element = atVector(&v, 2);
    assert(*element == 30);

    // Проверка на доступ к последнему элементу, который должен быть равен последнему добавленному
    element = atVector(&v, v.size - 1);
    assert(*element == v.data[v.size - 1]);
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    int *last_element = back(&v);
    assert(*last_element == 10);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    int *first_element = front(&v);
    assert(*first_element == 10);
}

void test_reserve_zeroCapacity() {
    vector v = createVector(0);
    reserve(&v, 0);
    assert(v.data == NULL);
    assert(v.capacity == 0);
    deleteVector(&v);
}

void test_reserve_increaseCapacity() {
    vector v = createVector(0);
    reserve(&v, 5);
    assert(v.data != NULL);
    assert(v.capacity == 5);
    deleteVector(&v);
}

void test_reserve_decreaseCapacity() {
    vector v = createVector(5);
    reserve(&v, 3);
    assert(v.capacity == 3);
    deleteVector(&v);
}

void test_reserve() {
    test_reserve_decreaseCapacity();
    test_reserve_increaseCapacity();
    test_reserve_zeroCapacity();
}

void test_clear() {
    vector v = createVector(5);
    clear(&v);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_shrinkToFit() {
    vector v = createVector(5);
    v.size = 3;
    shrinkToFit(&v);
    assert(v.capacity == 3);
    deleteVector(&v);
}

void test_deleteVector() {
    vector v = createVector(5);
    deleteVector(&v);
    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
}

void test_isEmpty_emptyVector() {
    vector v = createVector(0);
    assert(isEmpty(&v));
    deleteVector(&v);
}

void test_isEmpty_nonEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);
    assert(!isEmpty(&v));
    deleteVector(&v);
}

void test_isEmpty() {
    test_isEmpty_emptyVector();
    test_isEmpty_nonEmptyVector();
}

void test_isFull_fullVector() {
    vector v = createVector(3);
    v.size = 3;
    assert(isFull(&v));
    deleteVector(&v);
}

void test_isFull_notFullVector() {
    vector v = createVector(5);
    v.size = 3;
    assert(!isFull(&v));
    deleteVector(&v);
}

void test_isFull() {
    test_isFull_fullVector();
    test_isFull_notFullVector();
}


void test_createVectorV() {
    size_t n = 5;
    size_t baseTypeSize = sizeof(int);
    vectorVoid v = createVectorV(n, baseTypeSize);
    assert(v.size == 0);
    assert(v.capacity == n);
    assert(v.baseTypeSize == sizeof(int));
    assert(v.data != NULL);
    free(v.data);
}

void test_reserveV() {
    size_t n = 5;
    size_t baseTypeSize = sizeof(int);
    vectorVoid v = createVectorV(n, baseTypeSize);
    reserveV(&v, 10);
    assert(v.capacity == 10);
    reserveV(&v, 3);
    assert(v.capacity == 3);
    free(v.data);
}

void test_shrinkToFitV() {
    size_t n = 5;
    size_t baseTypeSize = sizeof(int);
    vectorVoid v = createVectorV(n, baseTypeSize);
    v.size = 3;
    shrinkToFitV(&v);
    assert(v.capacity == 3);
    free(v.data);
}

void test_clearV() {
    size_t n = 5;
    size_t baseTypeSize = sizeof(int);
    vectorVoid v = createVectorV(n, baseTypeSize);
    clearV(&v);
    assert(v.size == 0);
    free(v.data);
}

void runAllTests() {
    testGetMemMatrix();
    testGetMemArrayOfMatrices();
    testFreeMemMatrix();
    testFreeMemMatrices();
    testSwapRows();
    testSwapColumns();
    testInsertionSortRowsMatrixByRowCriteria();
    testSelectionSortColsMatrixByColCriteria();
    testIsSquareMatrix();
    testAreTwoMatricesEqual();
    testIsEMatrix();
    testIsSymmetricMatrix();
    testTransposeSquareMatrix();
    testTransposeMatrix();
    testGetMinValuePos();
    testGetMaxValuePos();

    printf("All tests passed successfully!\n");
}

int main() {
    runAllTests();


    return 0;

}
