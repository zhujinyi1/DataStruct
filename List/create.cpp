#include<iostream>
using namespace std;

#define MAXLISTSIZE 100;

typedef int ElemType;

typedef struct 
{
    /*data*/
    ElemType *elem; //储存空间地址
    int length;   //当前长度
    int listsize; //允许存储最大容量
}SqList;

//compare
bool compare(ElemType a,ElemType b){
    return (a==b);
}

//初始化线性表
void InitList(SqList &L,int maxize){
    //构造一个空线性表
    if(maxize == 0){
        maxize = MAXLISTSIZE;
    }
    L.elem = new ElemType[maxize];
    if(!L.elem) //储存空间分配失败
        exit(1);
    L.length = 0; //初始长度为0
    L.listsize = maxize;//可储存长度最大容量
}

//元素定位操作
int LocateElem(SqList L,ElemType e,bool (*compare)(ElemType,ElemType)){
    //找线性表中和e满足条件compare（）的第一个元素的位序，
    //否则返回0
    int i = 1; //第一个元素位序
    ElemType* p = L.elem; 
    while(i<=L.length&&!compare(*p++,e)){
        ++i;
    }
    if(i<=L.length){
        return i;
    }else{
        return 0;
    }
}

//主函数
int main(){
    int maxize,i,e;
    SqList list;

    while(1){
        printf("1.");
        printf("2.");
        printf("3.");
        printf("4.");
        printf("5.");
        printf("6.");
        printf("7.");
        printf("8.");
        printf("9.");
        printf("10.");
        cin >> i;

    }
    scanf("%d",&maxize);
    InitList(list,maxize);
    LocateElem(list,e,compare);
}