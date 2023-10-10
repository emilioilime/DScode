//
//  tree.hpp
//  cpplearn
//
//  Created by Emilio-v on 2023/10/9.
//

#ifndef tree_h
#define tree_h
#include "queueforTree.hpp"
#include "Node_Define.hpp"


void InitTree(Tree &T){//初始化树 给他一个根节点并将左右指针域清零；
    T=(TreeNode*)malloc(sizeof(TreeNode));
    T->lchild=NULL;
    T->rchild=NULL;
    T->data='A';
}
//通过树的顺序存储数组构造一颗链式存储树（仅二叉树适用）
TreeNode* addTreeNode(){//返回一个左右指针域都为 NULL 的节点
    TreeNode* s=(TreeNode*)malloc(sizeof(TreeNode));
    s->lchild=NULL;
    s->rchild=NULL;
    return s;
    
}
void tobuild_Link_Tree(Tree T,char a[],int n){//该数组从 1 开始存储，否则二叉树特性可能无法满足
    //假设这个T 已经初始化过了
    //n为当前节点在数组里的编号（满二叉树情况下) 最开始从 1 开始
    //char 数组内若是'-'则代表没有该结点
    T->data=a[n];
    
    //判当前节点有无左孩子  有则将当前节点的左指针指向该节点
   if(a[2*n]!='-'&&a[2*n]!='\0'&&(2*n)<=20)//防止数组越界 数组大小变化的话每次都要改
   { TreeNode* s=addTreeNode();
       T->lchild=s;
       tobuild_Link_Tree(T->lchild,a,2*n);
   }
    //有的话就递归进去
    if(a[2*n+1]!='-'&&a[2*n+1]!='\0'&&(2*n)<=20)
    { TreeNode* s=addTreeNode();
        
        T->rchild=s;
        tobuild_Link_Tree(T->rchild,a,2*n+1);
    }
    //判有无有孩子

}



//打印该树 使用层序遍历  队列的节点要改成树的节点类型才行

//递归版本

//二叉树的层序遍历
void levelOrder(Tree T){
    
    SqQ Q=Init_SqQ();
    En_SqQ(Q,T);
    TreeNode* x;//用来保存出队元素的指针
    while(SqQ_Empty(Q)==false)
    {
        De_SqQ(Q,x);
        if(x->lchild!=NULL)
        {
            En_SqQ(Q,x->lchild);
        }
        if(x->rchild!=NULL)
        {
            En_SqQ(Q,x->rchild);
        }
        //出队时要做的事情
        cout<<x->data<<' ';
       
    }
}
//二叉树的先序遍历
void print_NLR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 访问当前节点
    cout<<root->data<<' ';
    // 递归遍历左子树
    print_NLR(root->lchild);
    // 递归遍历右子树
    print_NLR(root->rchild);
}
void EnterSqQ_NLR(TreeNode* root,SqQ &Q) {
    if (root == NULL) {
        return;
    }
    En_SqQ(Q,root);
    // 访问当前节点
    // 递归遍历左子树
    EnterSqQ_NLR(root->lchild,Q);
    // 递归遍历右子树
    EnterSqQ_NLR(root->rchild,Q);
}

//二叉树的中序遍历
void print_LNR(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 递归遍历左子树
    print_LNR(root->lchild);
    
    // 访问当前节点
    cout<<root->data<<' ';
    
    // 递归遍历右子树
    print_LNR(root->rchild);
}
//二叉树的后序遍历
void print_LRN(TreeNode* root) {
    if (root == NULL) {
        return;
    }
   
    // 递归遍历左子树
    print_LRN(root->lchild);
    // 递归遍历右子树
    print_LRN(root->rchild);
    // 访问当前节点
    cout<<root->data<<' ';
}
//非递归版本

//二叉树的层序遍历

//二叉树的先序遍历

//二叉树的中序遍历
//二叉树的后序遍历
void LRN_Non_recursive(Tree T){
    Stack S;
    InitStack(S);
    TreeNode *p=T;
    TreeNode *r=NULL;
    while(p!=NULL||!StackEmpty(S))
    {
        if(p){      //往最左下走  将不能立即访问的结点存入栈中，栈顶结点仅当左右孩子都被访问过了才能出栈
            Push(S, p);
            p=p->lchild;
        }
        else{
            GetstackTop(S,p);//
            if(p->rchild && p->rchild!=r){
                p=p->rchild;    //转向右节点进入下一个循环  直到转向右节点最左下的结点后才出栈
            }
            else
            {
                Pop(S, p);
                //出栈顶元素，并访问该节点
                //打印出栈顶之前的栈内结构
                cout<<' '<<p->data<<'\n';
                print_Stack(S);
                //记录最近访问过的节点
                r=p;
                p=NULL;//结点访问完后，重置 p 指针
                
            }
        }
        
    }
}

//计算树高 //利用后序遍历的非递归算法看栈深
int count_tree_h(Tree T){
    int hmax=0;
    Stack S;
    InitStack(S);
    TreeNode *p=T;
    TreeNode *r=NULL;
    while(p!=NULL||!StackEmpty(S))
    {
        if(p){      //往最左下走  将不能立即访问的结点存入栈中，栈顶结点仅当左右孩子都被访问过了才能出栈
            Push(S, p);
            p=p->lchild;
        }
        else{
            GetstackTop(S,p);//
            if(p->rchild && p->rchild!=r){
                p=p->rchild;    //转向右节点进入下一个循环  直到转向右节点最左下的结点后才出栈
            }
            else
            {
                Pop(S, p);
                //出栈顶元素，并访问该节点
                if(S.top+2>hmax)
                    hmax=S.top+2;
                //记录最近访问过的节点
                r=p;
                p=NULL;//结点访问完后，重置 p 指针
                
            }
        }
        
    }

    return hmax;
}


//美观的打印树的结构 使用一个二维数组来保存树的结构 打印这个数组即可 需要求树的宽度和树的高度来决定长宽 此处暂时先设为 21*21

#endif /* tree_h */
