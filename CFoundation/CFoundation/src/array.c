//
//  array.c
//  CFoundation
//
//  Created by Jingfu Li on 2024/2/9.
//

#include "array.h"

int initArrayInt(ArrayIntRef ref, int capacity) {
    if (capacity <= 0) {
        return -1;
    }

    ref->values = malloc(sizeof(int) * capacity);
    if (!ref->values) {
        return -1;
    }

    ref->count = 0;
    ref->capacity = capacity;

    return 0;
}

int disposeArrayInt(ArrayIntRef ref) {
    free(ref->values);
    return 0;
}

int arrayIntAdd(ArrayIntRef ref, int value) {
    int count = ref->count;
    if (ref->capacity <= count) {
        return -1;
    }

    ref->values[count] = value;
    ++ref->count;

    return 0;
}

int arrayIntInsert(ArrayIntRef ref, int index, int value) {
    if (index < 0) {
        return -1;
    }

    int count = ref->count;
    if (ref->capacity <= count) {
        return -1;
    }

    if (index >= count) {
        return -1;
    }

    if (count == 0) {
        ref->values[0] = value;
        ++ref->count;
        return 0;
    }

    // move back
    int _index = count;
    while (_index != index) {
        ref->values[_index] = ref->values[_index - 1];
        --_index;
    }

    ref->values[index] = value;
    ++ref->count;

    return 0;
}

int arrayIntDelete(ArrayIntRef ref, int index) {
    if (index < 0) {
        return -1;
    }

    int count = ref->count;
    if (index >= count) {
        return -1;
    }

    int _index = index;
    while (_index != count - 1) {
        ref->values[_index] = ref->values[_index + 1];
        ++_index;
    }

    --ref->count;

    return 0;
}

int arrayIntGetValue(ArrayIntRef ref, int index, int *value) {
    if (index >= ref->count) {
        return -1;
    }

    *value = ref->values[index];

    return 0;
}

int arrayIntGetCount(ArrayIntRef ref) {
    return ref->count;
}

void testArrayInt(void) {
    ArrayIntType array;
    initArrayInt(&array, 10);
    ArrayIntRef arrayRef = &array;

    arrayIntAdd(arrayRef, 10);

    int result = 0;
    arrayIntGetValue(arrayRef, 0, &result);

    arrayIntInsert(arrayRef, 0, 5);
    arrayIntInsert(arrayRef, 0, 9);
    arrayIntDelete(arrayRef, 1);
}
