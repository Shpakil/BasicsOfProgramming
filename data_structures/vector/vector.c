//
// Created by Кирилл on 28.02.2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
vector createVector(size_t n){
    vector v;
    v.data= malloc(sizeof (int)*n);
    v.size=0;
    v.capacity=n;
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}
void reserve(vector *v, size_t newCapacity){
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity >= v->size) {
        int *newData = realloc(v->data, sizeof(int) * newCapacity);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    } else {
        v->size = newCapacity;
    }
}
void clear(vector *v) {
    v->size = 0;
}
//освобождает память, выделенную поднеиспользуемые элементы.
void shrinkToFit(vector *v) {
    v->capacity = v->size;
    //v->data = realloc(v->data, sizeof(int) * v->capacity); в методичке сказаано нужна только одна строка
}
//освобождает память, выделенную вектору.
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
