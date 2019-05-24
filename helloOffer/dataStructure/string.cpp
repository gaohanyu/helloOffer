//
//  string.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/12.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

/*串*/

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;


/*朴素的模式匹配算法*/
/*返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0*/
/*T非空，1 <= pos <= StrLength(S)*/
int Index(string S,string T,int pos){
    int i = pos;    /*i用于主串S中当前位置下标，若pos不为1
                     则从pos位置开始匹配*/
    int j = 1;      /*j用于子串T中当前位置下标值*/
    while (i <= S[0] && j < T[0]) {     /*若i小于S长度且j小于T的长度时循环*/
        if (S[i] == T[j]) {
            ++i;
            ++j;
        }else{      /*指针后退重新开始匹配*/
            i = i - j + 2;
            j = 1;  /*j退回到子串T的首位*/
        }
    }
    if (j > T[0]) {
        return i - T[0];
    }
    return 0;
}


/*KMP模式匹配算法*/
/*通过计算返回子串T的next数组*/
void get_next(string T, int *next){
    int i,j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0]) {   /*此处T[0]表示串T的长度*/
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];    /*若字符不相同，则j值回溯*/
        }
    }
}
int Index_KMP(string S,string T,int pos){
    int i = pos;    /*i用于主串S中当前位置下标，若pos不为1
                     则从pos位置开始匹配*/
    int j = 1;      /*j用于子串T中当前位置下标值*/
    int next[255];  /*定义一个next数组*/
    get_next(T, next);  /*对串T作分析，得到next数组*/
    
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            ++i;
            ++j;
        }else{
            j = next[j];    /*j退回合适的位置,i值不变*/
        }
    }
    if (j > T[0]) {
        return i - T[0];
    }
    return 0;
}




