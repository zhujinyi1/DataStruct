#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLISTSIZE 100;

typedef int ElemType;

typedef struct 
{
    /*data*/
    ElemType *elem; //储存空间地址
    int length;   //当前长度
    int listsize; //允许存储最大容量
}SqlList;

