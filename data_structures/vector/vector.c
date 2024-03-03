//
// Created by Кирилл on 28.02.2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.data = malloc(sizeof(int) * n);
    v.size = 0;
    v.capacity = n;
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserve(vector *v, size_t newCapacity) {
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

void shrinkToFit(vector *v) {
    v->capacity = v->size;
    v->data = realloc(v->data, sizeof(int) * v->capacity); //в методичке сказаано нужна только одна строка, но для  getVectorValue эта строчка нужна
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if(v->capacity==0){
        reserve(v,1);
    }
    if(v->size==v->capacity){
        reserve(v,2*v->capacity);
    }
    v->data[v->size++]=x;
}

void popBack(vector *v){
    if(v->capacity==0){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index){
    if(index>=v->size){
        fprintf(stderr, "IndexError: a[%zu] is not exists",index);
        exit(1);
    }
    return &v->data[index];
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    return &v->data[0];
}