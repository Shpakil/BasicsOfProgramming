//
// Created by Кирилл on 03.03.2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "vectorVoid.h"
vectorVoid createVectorV(size_t n,size_t baseTypeSize) {
    vectorVoid v;
    v.size = 0;
    v.capacity = n ;
    v.baseTypeSize = baseTypeSize;
    v.data = malloc(baseTypeSize * v.capacity);
    if (v.data == NULL) {
        exit(1);
    }
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity >= v->size) {
        void *newData = realloc(v->data, v->baseTypeSize * newCapacity);
        if (newData == NULL) {
            exit(1); // или обработка ошибки
        }
        v->data = newData;
        v->capacity = newCapacity;
    } else {
        v->size = newCapacity;
    }
}

void shrinkToFitV(vectorVoid *v) {
    v->capacity = v->size;
    v->data = realloc(v->data, v->baseTypeSize * v->capacity);
    if (v->data == NULL && v->capacity != 0) {
        exit(1); // или обработка ошибки
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}