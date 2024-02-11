//
//  list.h
//  CFoundation
//
//  Created by Jingfu Li on 2024/2/11.
//

#ifndef list_h
#define list_h

#include <stdio.h>

struct list_node {
};

typedef struct list_node* list_node_ref;

struct list {
    int count;
    list_node_ref firstNode;
};

#endif /* list_h */
