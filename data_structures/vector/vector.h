//
// Created by Кирилл on 28.02.2024.
//
#include <stdio.h>
#ifndef BASICSOFPROGRAMMING_VECTOR_H
#define BASICSOFPROGRAMMING_VECTOR_H
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;
//создает вектор размера n
vector createVector(size_t n);
//изменяет размер ветора v на новое занчение newCapacity
void reserve(vector *v, size_t newCapacity);
//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);
//
void shrinkToFit(vector *v);
//
void deleteVector(vector *v);
#endif //BASICSOFPROGRAMMING_VECTOR_H
