#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "data_structures/vector/vector.h"
#include "data_structures/vector/vectorVoid.h"

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



int main() {
    test_createVectorV();
    test_reserveV();
    test_shrinkToFitV();
    test_clearV();


    test_reserve();
    test_clear();
    test_shrinkToFit();
    test_deleteVector();
    test_isEmpty();
    test_isFull();
    test_atVector();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_pushBack();

    vectorVoid v1;
    v1.baseTypeSize=sizeof(float);
    v1.size=2;
    v1.capacity=2*v1.size;
    v1.data= malloc(v1.baseTypeSize*v1.capacity);

    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }
        return 0;

}
