//
//  stack.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/11.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

/*栈*/

#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef int SElemType;


//栈的结构定义
typedef struct{
    SElemType data[MAXSIZE];
    int top;   //用于栈顶指针
} SqStack;

//进栈push操作
/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S,SElemType e){
    if (S->top == MAXSIZE-1) {   /*栈满*/
        return ERROR;
    }
    S->top++;   /*栈顶指针增加一*/
    S->data[S->top] = e;    /*将新插入元素赋值给栈顶空间*/
    return OK;
}

//出栈pop操作
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(SqStack *S,SElemType *e){
    if (S->top == -1) {
        return ERROR;
    }
    *e = S->data[S->top];  /*将要删除的栈顶元素赋值给e*/
    S->top--;   /*栈顶指针减一*/
    return OK;
}



























