#include"information.hpp"

//初始化线性表
void InitList(SqlList &L,int maxize){
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
