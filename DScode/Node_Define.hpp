//
//  Node_Define.hpp
//  Database_struct
//
//  Created by Emilio-v on 2023/10/10.
//

#ifndef Node_Define_h
#define Node_Define_h
#define QueueMaxSize 10   //循环队列元素个数

//定义链表节点结构
typedef struct SLlist_Node {
    char data;
    struct SLlist_Node* next;
}SLlist_Node,*SLlist;//定义结点别名，链表头指针别名




// 定义树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode,*Tree;// Tree T 代表指向根节点的指针  代表一棵树从此开始遍历

//定义循环队列结构for 树
typedef struct{ //队头指针指向队头元素，队尾指针指向队尾元素的下一个位置  （和链式存储不一样）
    TreeNode* data[QueueMaxSize];
    int front,rear;
} SqQ;

//定义栈 存树的节点的指针
#define stackMaxSize 10
typedef struct{
    TreeNode* data[stackMaxSize];
    int top;
} Stack;
#endif /* Node_Define_h */
