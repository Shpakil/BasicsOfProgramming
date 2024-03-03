#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "data_structures/vector/vector.h"
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
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
int main() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    return 0;
}
