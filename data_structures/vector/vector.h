//
// Created by Кирилл on 28.02.2024.
//
#include <stdio.h>
#include <stdbool.h>
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

//освобождает память, выделенную поднеиспользуемые элементы.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору.
void deleteVector(vector *v);

//возвращает true если вектор пуст(размер вектора ноль), иначе ложь.
bool isEmpty(vector *v);

//возвращает true если вектор полон(размер вектора равен вместимости), иначе ложь.
bool isFull(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает количество выделенной ему памяти в 2 раза, используя reserve.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора
void popBack(vector *v);
#endif //BASICSOFPROGRAMMING_VECTOR_H
