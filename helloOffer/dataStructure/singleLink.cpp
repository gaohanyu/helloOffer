//
//  singleLink.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/10.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

/*单链表*/

#include <stdio.h>
#include <mm_malloc.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

//定义单链表结点
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

//读取单链表
Status GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

//插入节点
Status ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    if (!p || j>i) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}


//删除节点
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    if (!p || j>i) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}


/*单链表的整表创建*/
//1.插队的办法创建，始终让新的节点在第一的位置
void CreateListHead(LinkList *L,int n){
    LinkList p;
    int i;
    srand((int)time(0));  //初始化随机数字种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;    //建立一个带头结点的单链表
    for (i = 0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->next = *L;
        p->data = rand()%100+1;  //随机生成100以内的数字
        (*L)->next = p;   //插入到表头
    }
    
}
//2.顺序的方式创建，始终让新的节点在最后
void CreateListTail(LinkList* L,int n){
    LinkList p,r;
    int i;
    srand((int)time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;   //r为指向尾部的节点
    for (i = 0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}


//整表删除
Status ClearList(LinkList*L){
    LinkList p,q;
    p = (*L)->next; //p指向第一个结点
    if (p) {  //没到表尾
        q = p->next;
        free(p);
        p=q;
    }
    (*L)->next = NULL; //头结点指针域为空
    return OK;
}
















