//
//  staticLink.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/10.
//  Copyright © 2016年 高翰宇. All rights reserved.
//


/*用数组描述的链表叫静态链表。总的来说，静态链表是为了给没有指针的高级语言设计的一种实现单链表能力的方法。*/
#include <stdio.h>
#include <mm_malloc.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

#define MAXSIZE 1000 //假设链表的最大长度是1000
typedef struct{
    ElemType data;
    int cur;  //游标(cursor)，为0时表示无指向
} Componet,StaticLinkList[MAXSIZE];

//创建、初始化静态链表
Status InitList(StaticLinkList space){
    int i;
    for (i=0; i<MAXSIZE-1; i++) {
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;  //目前静态链表为空，最后一个元素的cur为0
    return OK;
}

//实现一个获取链表长度的方法
int ListLength(StaticLinkList L){
    int len = 0;
    int i = L[MAXSIZE-1].cur;
    while (i) {
        i = L[i].cur;
        len++;
    }
    
    return len;
}

/*若备用空间链表非空，则返回分配的结点下标，否则返回0*/
int Malloc_SLL(StaticLinkList space){
    int i = space[0].cur;
    
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

//插入结点
Status ListInsert(StaticLinkList L,int i,ElemType e){
    int j,k,l;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }
    j = Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (l = 1; l < i -1; l++) {  //找到第i个元素之前的位置
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

/*将下标为k的空闲结点回收到备用链表*/
void Free_SLL(StaticLinkList space, int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//删除L中第i个数据元素结点
Status ListDelete(StaticLinkList L,int i){
    int j,k;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L)) {
        return ERROR;
    }
    for (j = 1; j < i - 1; j++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SLL(L, j);
    return OK;
}





