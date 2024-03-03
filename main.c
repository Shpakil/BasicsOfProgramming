#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "data_structures/vector/vector.h"
#include "data_structures/vector/vectorVoid.h"
#include <assert.h>

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

int main() {
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

    vectorVoid v;
    v.baseTypeSize=sizeof(float);
    v.size=2;
    v.capacity=2*v.size;
    v.data= malloc(v.baseTypeSize*v.capacity);
    return 0;
}
