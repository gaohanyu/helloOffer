//
//  binaryTree.cpp
//  helloOffer
//
//  Created by hanyu gao on 2019/5/24.
//

/*二叉树*/

/*每个结点最多有两棵子树，左子树和右子树，次序不可以颠倒。*/

#include <stdio.h>

/*定义一个节点*/
typedef char datatype;

typedef struct BinNode {
    datatype data;
    struct BinNode* leftChild;
    struct BinNode* rightChild;
}BinNode;

typedef BinNode* bintree; //bintree本身是个指向结点的指针


/*二叉树的遍历，分为前序遍历、中序遍历、后序遍历、层次遍历
    前序： 根节点 -> 左子树 -> 右子树
    中序： 左子树 -> 根节点 -> 右子树
    后序： 左子树 -> 右子树 -> 根节点
    层次： 每一层从左到右输出
    前三种属于深度优先遍历（DFS），层次遍历是广度优先遍历(BFS)*/

/*实现这三种遍历最简单的方式就是递归，以前序遍历为例，访问根节点，若有值，则先打印，然后递归遍历左子树和右子树即可*/

/*前序遍历*/
void preOrder (bintree t) {
    if (t) {
        cout << t->data << endl;
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

/*中序遍历*/
void inOrder (bintree t) {
    if (t) {
        inOrder(t->leftChild);
        cout << t->data << endl;
        inOrder(t->rightChild);
    }
}

/*后序遍历*/
void postOrder (bintree t) {
    if (t) {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        cout << t->data << endl;
    }
}

/*递归的方式虽然简洁，但是如果树比较大，调用层级非常深，有可能引起栈溢出。
  另一种遍历的方式是依靠循环，因为遍历过程中涉及到回溯，所以还要依赖一个栈 */

/*非递归前序遍历：
  从根节点开始校验，如果他有左子树，那么打印它的值，并压栈以供回溯右子树的时候使用。
  这也说明了循环的条件，1.当前节点部位空 2.栈不为空。 只要满足这两个条件之一，就说明遍历还没结束。*/

void preOrderTraversal (bintree t) {
    if (!t) {
        cout << "empty tree !" << endl;
        return;
    }
    Stack treeNodeStack;  // 创建一个栈来存储节点
    BinNode node = t;  //记录根节点
    //开始循环
    while (node || !treeNodeStack.isEmpty()) {
        //若当前节点非空，则输出它的值，然后继续查看它的左子树
        while (node) {
            cout << node->data << endl;
            treeNodeStack.push(node);
            node = node->leftChild;
        }
        
        //左子树打印完了，开始考虑右子树。如果栈已经空了，就说明已经结束了
        if(!treeNodeStack.isEmpty()) {
            node = treeNodeStach.pop();
            node = node->rightChild;
        }
    }
}

/*非递归中序遍历：
  和前序遍历相似*/

void indOrderTraversal (bintree t) {
    if (!t) {
        cout << "empty tree !" << endl;
        return;
    }
    Stack treeNodeStack;  // 创建一个栈来存储节点
    BinNode node = t;  //记录根节点
    //开始循环
    while (node || !treeNodeStack.isEmpty()) {
        while (node) {
            treeNodeStack.push(node);
            node = node->leftChild;
        }
        //找到了最左端的节点，然后开始出栈
        if (!treeNodeStack.isEmpty()) {
            node = treeNodeStack.pop();
            cout << node->data << endl;
            node = node.right;
        }
    }
}

/*非递归后续遍历
  后续遍历比较麻烦，因为在决定是否可以打印当前节点的时候，需要考虑是否左右子树都已经遍历完成了。
  设置一个lastVisit的游标
    若lastVisit等于当前节点的右子树，则表示左右都已经遍历完成了，再打印当前节点，并把lastVisit设置成当前节点，把node设置成空。
    否则遍历右子树，node = node.right;
 */

void postOOderTraversal (bintree t) {
    if (!t) {
        cout << "empty tree !" << endl;
        return;
    }
    Stack treeNodeStack;  // 创建一个栈来存储节点
    BinNode node = t;  //记录根节点
    BinNode lastVisit = t; //游标
    //开始循环
    while (node || !treeNodeStack.isEmpty()) {
        while (node) {
            treeNodeStack.push(node);
            node = node.left;
        }
        //左子树到头了，查看当前栈顶的元素
        node = treeNodeStack.top();
        //如果右子树也是空或者已经被访问了，就可以直接输出当前节点
        if (!node.right || node == lastVisit) {
            cout << node->data << endl;
            treeNodeStack.pop();
            lastVisit = node;
            node = NULL;
        }else {
            //否则，继续遍历右子树
            node = node.right;
        }
    }
}

/*层次遍历
  每一层从左到右打印，把元素存储在一个队列中*/
