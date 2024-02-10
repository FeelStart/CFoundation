//
//  array.h
//  CFoundation
//
//  Created by Jingfu Li on 2024/2/9.
//

#ifndef array_h
#define array_h

#include <stdio.h>
#include <stdlib.h>

/// 整数类型的数组
struct ArrayInt {
    /// 容量
    int capacity;
    /// 已有的数目
    int count;
    /// 元素列表
    int *values;
};

typedef struct ArrayInt ArrayIntType;
typedef struct ArrayInt* ArrayIntRef;

int initArrayInt(ArrayIntRef ref, int capacity);
int disposeArrayInt(ArrayIntRef ref);
int arrayIntAdd(ArrayIntRef ref, int value);
int arrayIntInsert(ArrayIntRef ref, int index, int value);
int arrayIntDelete(ArrayIntRef ref, int index);
int arrayIntGetValue(ArrayIntRef ref, int index, int *value);
int arrayIntGetCount(ArrayIntRef ref);

void testArrayInt(void);

#endif /* array_h */
