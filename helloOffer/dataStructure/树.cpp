//
//  树.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/18.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

#include <stdio.h>


/*树的双亲表示法 结点结构定义*/
#define MAX_TREE_SIZE 100
typedef int TElemType;  /*树结点的数据类型，目前暂定为整型*/
typedef struct PTNode{  /*结点结构*/
    TElemType data;     /*结点数据*/
    int parent;     /*双亲位置*/
}PTNode;

typedef struct{     /*树结构*/
    PTNode nodes[MAX_TREE_SIZE];    /*结点数组*/
    int r,n;       /*根的位置和结点树*/
} PTree;



/*树的孩子表示法 结构定义*/
typedef struct CTNode{
    int child;
    CTNode *next;
}*ChildPtr;

typedef struct{
    TElemType data;
    ChildPtr firstchild;
} CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;
} CTRee;







