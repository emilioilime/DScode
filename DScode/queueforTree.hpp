//
//  queue.hpp
//  cpplearn
//
//  Created by Emilio-v on 2023/9/24.
//使用循环队列实现，储存的是树结点的指针

#ifndef queueforTree_hpp
#define queueforTree_hpp


#include <iostream>
#include <stdio.h>
#include "Node_Define.hpp"



using namespace  std;




SqQ Init_SqQ(){
    SqQ Q;//声明一个队列
    Q.front=Q.rear=0;//将队列初始化
    for(int i=0;i<QueueMaxSize;i++){
        Q.data[i]=NULL;
    }
    return Q;
}
bool SqQ_Empty(SqQ &Q){ //队空两指针相等
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}
bool SqQ_Full(SqQ &Q){//约定队头指针在队尾指针的下一位置作为队满的标志
    if(Q.front==Q.rear+1)
        return true;
    else
        return false;
}
bool En_SqQ(SqQ &Q,TreeNode* s){//进队操作
    if (SqQ_Full(Q))
    {
        return false;
    }
    Q.data[Q.rear] = s;
    Q.rear = (Q.rear + 1) % QueueMaxSize;
    return true;
}
bool De_SqQ(SqQ &Q,TreeNode* &x){//出队操作
    if (SqQ_Empty(Q))
    {
        return false;
    }
    x=Q.data[Q.front];
    Q.data[Q.front]=NULL;
    Q.front = (Q.front + 1) % QueueMaxSize;
    return true;
}
void GetHead_SqQ(SqQ &Q,TreeNode* x){ //读队头元素
    
}
void Print_SqQ(SqQ &Q){
    int r = Q.front;
    while (r!= Q.rear)
    {
        cout << Q.data[r]->data<<' ';
        r = (r + 1) % QueueMaxSize;
    }
    cout<<'\n';
}







#endif /* queueforTree_hpp */
