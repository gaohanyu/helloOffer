//
//  queue.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/12.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

/*队列*/

#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>
#include <math.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int QElemType;

/*结点结构*/
typedef struct QNode{
    QElemType data;
    QNode *next;
}QNode,*QueuePtr;

/*队列的链表结构*/
typedef struct{
    QueuePtr front,rear;
} LinkQueue;


/*插入元素e为Q的新的队尾元素*/
Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s) {
        exit(OVERFLOW); /*存储分配失败*/
    }
    
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

/*若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR*/
Status DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if (Q->front == Q->rear) {
        return ERROR;
    }
    
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}














