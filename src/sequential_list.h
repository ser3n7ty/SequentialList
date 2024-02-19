#include <stdio.h>
#include <stdlib.h>

// * 使用 typedef 简化复杂类型声明
typedef struct {
    int* elements;
    size_t size;
    size_t capacity;
} SequentialList;

void SequentialListInit(SequentialList *list, size_t capacity) {
    list->elements = (int *)malloc(sizeof(int) * capacity);
    list->capacity = capacity;
    list->size = 0;
}

void SequentialListDestroy(SequentialList *list) {
    if(list->elements != NULL) {
        free(list->elements);
        list->elements = NULL;
    }
}

int SequentialListSize(SequentialList *list) {
    return list->size;
}

void SequentialListInsert(SequentialList *list, int index, int num) {
    if(index < 0 || index > list->size) {
        fprintf(stderr, "Invalid index.\n");
        return;
    }

    if(list->capacity == list->size) {
        int *newElements = (int *)realloc(list->elements, sizeof(int) * list->capacity * 2);
        if(newElements == NULL) {
            fprintf(stderr, "Failed to alloc new space for new element.\n");
            return;
        }
        list->elements = newElements;
        list->capacity *= 2;
    }

    ++list->size;
    for(int i=index+1; i<list->size; ++i) {
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = num;
}

int SequentialListFetch(SequentialList *list, int index) {
    if(index <0 || index >= list->size) {
        fprintf(stderr, "Invalid index.\n");
        return 1;
    }
    return list->elements[index]; 
}

void SequentialListAlter(SequentialList *list, int index, int num) {
    if(index < 0 || index >= list->size) {
        fprintf(stderr, "Invalid index.\n");
        return;
    }
    list->elements[index] = num;
}

void SequentialListDelete(SequentialList *list, int index) {
    if(index < 0 || index >= list->size) {
        fprintf(stderr, "Invalid index.\n");
        return;
    }
    for(int i=index; i < (list->size-1); ++i) {
        list->elements[i] = list->elements[i+1];
    }
    --list->size;
}

int SequentialListFetchIndex(SequentialList *list, int num) {
    for(int i=1; i<list->size; ++i) {
        if(num == list->elements[i]) {
            return i;
        }
    }
    return 0;
}

void SequentialListTraversal(SequentialList *list) {
    for(int i=0; i<list->size; ++i) {
        printf("%d ", list->elements[i]);
    }
    printf("\n");
}