//
//  stack.hpp
//  cpplearn
//
//  Created by Emilio-v on 2023/10/9.
//定义一个顺序栈 用数组实现  数组内容是树的节点指针类型
#include<iostream>
using namespace std;
#ifndef stack_h
#define stack_h
#include "Node_Define.hpp"

void InitStack(Stack &S)
{
    S.top=-1;//初始化栈顶指针  栈顶指针指向栈顶元素
    for(int i=0; i<stackMaxSize; i++){
        S.data[i]=NULL;
    }
}
bool StackEmpty(Stack &S){
    
    if(S.top==-1)
        return true;
    else
        return false;
}
//进栈
bool Push(Stack &S,TreeNode* e)
{
    if(S.top==stackMaxSize-1)//栈满，报错
        return false;
    S.data[++S.top]=e;
    return true;
    
}
//出栈
bool Pop(Stack &S,TreeNode* &e)
{
    if(S.top==-1)//栈空报错
        return false;
    e=S.data[S.top--];
    return true;
}
//读栈顶元素
bool GetstackTop(Stack S ,TreeNode* &e)
{
    if(S.top==-1)//栈空 报错
        return false;
    e=S.data[S.top];
    return true;
}
//打印栈中元素
bool print_Stack(Stack &S){
    if(S.top==-1)
        return false;
    int r=S.top;//指向打印的那个元素  中间变量
    while(r!=-1)
    {
        cout<<" "<<S.data[r--]->data<<"\n";
    }
    cout<<"栈底\n";
    return true;
}



/*一些基本操作  定义了一个A 到 x 的入栈顺序的栈
 
Stack S;
InitStack(S);


*/


#endif /* stack_h */
