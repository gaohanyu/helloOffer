//
//  list.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/9.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//获得元素操作
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
Status GetElem(SqList L,int i,ElemType *e){
    if (L.length==0 || i<1 || i>L.length) {
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

//插入操作
Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if (L->length==MAXSIZE) { //顺序线性表已经满了
        return ERROR;
    }
    if (i<1 || i>L->length+1) { //当i不在范围内时
        return ERROR;
    }
    if (i<L->length) { //若插入的数据位置不在表尾
        for (k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}


//删除操作
Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if (L->length == 0) {  //线性表为空
        return ERROR;
    }
    if (i<1 || i>L->length+1) { //删除位置不正确
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length) { //若删除的不是最后位置
        for (k=i;k<L->length;k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}























