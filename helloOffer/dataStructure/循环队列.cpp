//
//  循环队列.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/12.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef int QElemType;

typedef struct{
    QElemType data[MAXSIZE];
    int front;   /*头指针*/
    int rear;    /*尾指针，若队列不空，指向队列尾元素的下一个位置*/
} SqQueue;

/*初始化一个空队列Q*/
Status InitQueue(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/*返回Q的元素个数，也就是队列的当前长度*/
int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/*若队列未满，则插入元素e为Q新的队尾元素*/
Status EnQueue(SqQueue *Q,QElemType e){
    if ((Q->rear + 1) % MAXSIZE == Q->front) {   /*队列满的判断*/
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;    /*rear指针向后移动一位
                                           若到最后，则转到数组头部*/
    return OK;
    
}

/*若队列不空，则删除Q中队头元素，用e返回其值*/
Status DeQueue(SqQueue *Q,QElemType *e){
    if (Q->rear == Q->front) {      /*队列空的判断*/
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;    /*front指针向后移动一位
                                             若到最后，则转到数组头部*/
    
    return OK;
}








