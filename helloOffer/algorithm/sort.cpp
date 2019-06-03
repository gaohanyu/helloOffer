//
//  sort
//  helloOffer
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
    
    return 0;
}

//冒泡排序，从左到右，两两比较，若符合条件，就交换值，一次遍历之后，最大或者最小值就到了最右侧，然后再遍历剩余的数。
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
    if (low  >= high) {
        return;
    }
    int i = low;
    int j = high;
    int key = a[low];
    //在两个指针相遇之前，一直进入循环
    while (i < j) {
        while (i < j && a[j] >= key) {
            j--;
            if (j == low) {
                break;
            }
        }
        while (i < j && a[i] <= key) {
            i++;
            if (i == high) {
                break;
            }
        }
        if (i > = j) {
            break;
        }
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
    }
    /*中枢值与j对应值交换*/
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    Qsort(arr, low, j - 1);
    Qsort(arr, j + 1, high);
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








