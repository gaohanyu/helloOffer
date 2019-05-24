//
//  链栈.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/11.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

/*链栈结构*/
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;


//进栈操作
/*插入e为新的栈顶元素*/
Status Push(LinkStack *S,SElemType e){
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top; /*把当前的栈顶元素赋值给新结点的直接后继*/
    S->top = s;
    S->count ++;
    return OK;
}

//出栈操作
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/
Status Pop(LinkStack *S,SElemType *e){
    LinkStackPtr p;
    if (S->top->next == NULL) {  //空栈
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;     /*将栈顶结点赋值给p*/
    S->top = S->top->next;      /*使得栈顶指针下移一位，指向后一结点*/
    free(p);    /*释放结点p*/
    S->count --;
    return OK;
}



/*如果栈的使用过程中元素变化不可预料，有时很小，有时非常大，那么最好是用链栈；
 反之，如果它的变化在可控范围内，使用顺序栈会更好一些。*/








