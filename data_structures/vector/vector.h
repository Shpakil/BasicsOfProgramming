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
#endif //BASICSOFPROGRAMMING_VECTOR_H
