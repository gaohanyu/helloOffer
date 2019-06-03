//
//  linkAlgorithm.cpp
//  helloOffer
//
//  Created by hanyu gao on 2019/5/24.
//

#include <stdio.h>

/*
 目录
 1.倒序打印一个单向链表
 2.单项链表翻转
 
 */


/*1.倒序打印一个单向链表*/
/*倒叙打印，很明显的后进先出，可以依靠一个栈来存储，遍历完成之后，依次出栈打印即可*/

void printListReversingly (ListNode* pHead) {
    
    std::Stack<ListNode*> stack;
    
    ListNode* pNode = pHead;
    while (pNode) {
        stack.push(pNode);
        pNode = pHead->next;
    }
    
    while (!stack.isEmpty()) {
        pNode = stack.top();
        cout << pNode->data << endl;
        stack.pop();
    }
}

//同时也可以用递归的思路解决

void printListReversingly_Rec (ListNode* pHead) {
    
    if (pHead) {
        
        if (pHead->next) {
            
            printListReversingly_Rec(pHead->next);
            
        }
        
        cout << pHead->data << endl;
    }
    
}
