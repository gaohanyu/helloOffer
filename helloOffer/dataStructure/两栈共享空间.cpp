//
//  两栈共享空间.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/11.
//  Copyright © 2016年 高翰宇. All rights reserved.
//


/*数组有两个端点，两个栈有两个栈底，让一个栈的栈底为数组的始端，即下标为0处，另一个栈为数组的末端，即下标为数组长度n-1处。
 这样，两个栈如果增加元素，就是两端点向中间延伸。*/

#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef int SElemType;

/*两栈共享空间结构*/
typedef struct{
    SElemType data[MAXSIZE];
    int top1; /*栈1栈顶指针*/
    int top2; /*栈2栈顶指针*/
} SqDoubleStack;


//push
/*插入元素e为新的栈顶元素*/
Status Push(SqDoubleStack *S,SElemType e,int stackNumber){
    if (S->top1 + 1 == S->top2) {   /*栈已满，不能再push新元素了*/
        return ERROR;
    }
    if (stackNumber == 1) {     /*栈1有新元素进栈*/
        S->data[++S->top1] = e;     /*若栈1则先top1+1后给数组元素赋值*/
    }else if (stackNumber == 2){    /*栈2有新元素进栈*/
        S->data[--S->top2] = e;     /*若栈2则先top2-1后给数组元素赋值*/
    }
    return OK;
}


//pop
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber){
    if (stackNumber == 1) {
        if (S->top1 == -1) {    /*说明栈1已经是空栈，溢出*/
            return ERROR;
        }
        *e = S->data[S->top1--];    /*将栈1的栈顶元素出栈*/
    }else if (stackNumber == 2){
        if (S->top2 == MAXSIZE - 1) {   /*说明栈2已经是空栈，溢出*/
            return ERROR;
        }
        *e = S->data[S->top2++];    /*将栈2的栈顶元素出栈*/
    }
    return OK;
}









