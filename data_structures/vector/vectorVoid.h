//
// Created by Кирилл on 03.03.2024.
//

#ifndef BASICSOFPROGRAMMING_VECTORVOID_H
#define BASICSOFPROGRAMMING_VECTORVOID_H

#include <limits.h>
typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

#endif //BASICSOFPROGRAMMING_VECTORVOID_H
