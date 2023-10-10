//
//  queue.hpp
//  cpplearn
//
//  Created by Emilio-v on 2023/9/24.
//实现一个数据类型是char的队列

#ifndef queueforSLlist_hpp
#define queueforSLlist_hpp

#include <iostream>
#include <stdio.h>
using namespace  std;
#include "SLlist.hpp"

//定义队列结构体  存队列的头尾指针。    指向一个头结点       此文带头结点
typedef struct {
    SLlist_Node *front,*rear;
}Queue;

//初始化队列
void InitQueue(Queue &Q) {
    Q.front=Q.rear=(SLlist_Node*)malloc(sizeof(SLlist_Node));//初始化  让头和尾指针都指向头结点
    Q.front->next=NULL; //将头结点指针域设为 NULL
}

//入队  从队尾入队
 void input_Q(Queue &Q ,char &data)
{
     SLlist_Node* p=(SLlist_Node*)malloc(sizeof(SLlist_Node));
     p->next=NULL;
     p->data=data;
     Q.rear->next=p;
     Q.rear=p;
     
 }

//出队
 char output_queue(Queue &Q) //出队并返回该结点 data 值
{
    char data;
    //先判断对空否？
    if(Q.front==Q.rear)
        return 'o';//返回 o 代表队空，则输入时 data 不能为 o
    
    //需要判断是否是最后一个元素
    if(Q.front->next->next==NULL)
    {
        Q.rear=Q.front;
    }
    SLlist_Node* s;//暂存指针
    s=Q.front->next;
    data=s->data;
    Q.front->next=s->next;
    free(s);
    return data;
    //需要判断是否是最后一个元素
}

//打印当前队列  从头到尾

void print_Q(Queue &Q){
    
    SLlist_Node* r=Q.front->next;
    while(r!=NULL)
    {
        cout<<r->data<<' ';
        r=r->next;
    }
    cout<<"\n";
    
}




#endif /* queueforSLlist_hpp */
