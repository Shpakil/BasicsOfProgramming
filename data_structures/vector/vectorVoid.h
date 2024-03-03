//
// Created by Кирилл on 03.03.2024.
//

#ifndef BASICSOFPROGRAMMING_VECTORVOID_H
#define BASICSOFPROGRAMMING_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

//создает вектор размера n
vectorVoid createVectorV(size_t n,size_t baseTypeSize);

//изменяет размер ветора v на новое занчение newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clearV(vectorVoid *v);

//освобождает память, выделенную поднеиспользуемые элементы.
void shrinkToFitV(vectorVoid *v);

//освобождает память, выделенную вектору.
void deleteVectorV(vectorVoid *v);

//проверяет пуст ли массив
bool isEmptyV(vectorVoid *v);

//проверяет полон ли массив
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v. Вычисление адреса местоположения элемента и его копирование:
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу source;
void setVectorValueV(vectorVoid *v, size_t index, void *source);

//удаляет последний элемент
void popBackV(vectorVoid *v);

//добавляет элемент в конец вектора, если вектор полон расширяет его в два раза
void pushBackV(vectorVoid *v, void *source);
#endif //BASICSOFPROGRAMMING_VECTORVOID_H
