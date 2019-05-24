//
//  basics.cpp
//  helloworld
//
//  Created by 高翰宇 on 16/10/8.
//  Copyright © 2016年 高翰宇. All rights reserved.
//

#include <iostream>
using namespace std;

/*该文件包括最最基本、最最常见的算法考察： 冒泡排序、快速排序、二分查找*/


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, Offer!\n";
    
    float a = 1.1;
    double b = 1.1;
    if (a == b) {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
    return 0;
}

//冒泡排序
void bubble_sort(int a[],int n){  //n是数组的长度
    int i,j,temp;
    for (j = 0; j < n-1; j++) {
        for (i = 0; i < n-1-j; i++) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

//快速排序
void Qsort(int a[],int low,int high){
    if (low  > high) {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];
    while (first < last) {
        while (first < last && a[last] >= key) {
            last--;
        }
        a[first] = a[last];
        while (first < last && a[first] <= key) {
            first++;
        }
        a[last] = a[first];
    }
    
    a[first] = key;
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

//二分查找 要求待查表为有序表
int found(int a[], int x,int y,int k)
{
    int m=x+(y-x)/2;
    if(x>y)//查找完毕没有找到答案，返回-1
        return -1;
    else
    {
        if(a[m]==k)
            return m;//找到!返回位置.
        else if(a[m]>k)
            return found(a,x,m-1,k);//找左边
        else
            return found(a,m+1,y,k);//找右边
    }
}








