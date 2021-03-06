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

    //填入元素
void InPut(SqList &L){
    int a,t;
    ElemType*p = L.elem;
    cin >> a;
    while(L.length<=L.listsize){
        L.length++;
        (*p)=a;
        p++;
        cout  << "是否再次输入？（是1）" << endl;
        cin >> t;
        if(t != 1)
            break;
        cout << "请输入：";
        cin >> a; 
    }

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

    //遍历
void Display(SqList L){
    ElemType *p = L.elem;
    int l = L.length;
    while(l>0){
        cout << *p << " ";
        l--;
        p++;
    }
    cout << endl;
}

    //线性表插入
bool ListInsert(SqList &L,int pos,ElemType e){
    //若储存空间不满且1<=pos<=Listlength(L)+1,则在顺序表L

}

//主函数
int main(){
    int maxsize,i,e,l;
    SqList list;

    while(1){
        printf("1.初始化\n");
        printf("2.输入\n");
        printf("3.元素定位\n");
        printf("4.遍历\n");
        printf("5.\n");
        printf("6.\n");
        printf("7.\n");
        printf("8.\n");
        printf("9.\n");
        printf("10.\n");
        cin >> i;
        switch(i){
            case 1:
                cout << "请输入表格最大长度" << endl;
                cin >> maxsize;
                InitList(list,maxsize);
                system("pause");
                system("cls");
                break;
            case 2:
                InPut(list);
                system("pause");
                system("cls");
                break;
            case 3:
                cout << "请输入要查找的数" << endl;
                cin >> e;
                l = LocateElem(list,e,compare);
                cout << "该元素位置为" << l << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                Display(list);
                system("pause");
                system("cls");
                break;
            case 5:
                system("pause");
                system("cls");
                break;
            case 6:
                system("pause");
                system("cls");
                break;
            case 7:
                system("pause");
                system("cls");
                break;
            case 8:
                system("pause");
                system("cls");
                break;
            case 9:
                system("pause");
                system("cls");
                break;
            case 10:
                system("pause");
                system("cls");
                break;
            case 11:
                system("pause");
                system("cls");
                break;
            case 12:
                system("pause");
                system("cls");
                break;
            default:
                system("pause");
                system("cls");
                i=0;
                break;
        }
        if(i==0)
            break;
    }
    
    
}