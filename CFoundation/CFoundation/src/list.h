//
//  list.h
//  CFoundation
//
//  Created by Jingfu Li on 2024/2/11.
//

#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct list_node* list_node_ref;
typedef struct list* list_ref;

struct list_node {
    int value;
    list_node_ref nextNode;
};

struct list {
    int count;
    list_node_ref firstNode;
    list_node_ref lastNode;
};

int listAddValue(list_ref list, int value);
int listInsertValueAtIndex(list_ref list, int value, int index);
int listGetCount(list_ref list);
int listRemoveAtIndex(list_ref list, int index);
int listRemoveFirst(list_ref list);
int listRemoveLast(list_ref list);

#endif /* list_h */
