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
    //若储存空间不满且1<=pos<=Listlength(L)+1,则在顺序表L的第pos
    //个元素之前插入新的元素e且返回true，否则返回false
    int j;
    if(pos<1 || pos>L.length+1) return false;//插入位置不合法
    if(L.length >=L.listsize) return false;//储存空间已满
    for(j = L.length-1;j>pos-1;--j){
        L.elem[j+1] = L.elem[j]; //元素后移
        L.elem[pos-1] = e; //插入e
        ++L.length; //表长+1
    }
    return true; 
}

    //删除元素
bool ListDelete(SqList &L,int pos,ElemType &e){
    //若1<=pos<=ListLength(L),则以e带回从顺序表L中删除
    //的第pos个元素且返回TRUE，否则返回false
    int j;
    if((pos<1)||(pos>L.length))
        return false; //删除位置不合法、
    e = L.elem[pos-1];
    for(j = pos;j<L.length;++j){
        L.elem[j-1] = L.elem[j];  //被删除的元素左移
    }
    --L.length;
    return true;
}

    //线性表销毁
void DestroyList( SqList &L )
{
    // 释放顺序表 L 所占存储空间
    delete[ ] L.elem;
    L.listsize = 0;
    L.length = 0;
} 

    //线性表比较
int compare(SqList &A, SqList &B){
    //若A<B，则返回-1；若A>B，则返回0；若A>B,则返回1
    int j = 0;
    while(j<A.length && B.length)
        if(A.elem[j]<B.elem[j]) 
            return -1;
        else if(A.elem[j]>B.elem[j])
            return 1;
        else
            j++;
    if(A.length == B.length)
        return 0;
    else if(A.length <B.length)
        return -1;
    else
        return 1;
}

    //顺序表逆置
void invert(ElemType *R,int s,int t){
    int k,w;
    for(k=s;k<=(s+t)/2;k++){
        w = *(R+k);
        *(R+k) = *(R+t-k+s);
        *(R+t-k+s) = w; 
    }
}

void exchange(SqList &A,int m){
    //前m元素和后n元素互换
    int n;
    if(m>0&&m<A.length){
        n = A.length-m;
        invert(A.elem,0,m+n-1);
        invert(A.elem,0,n-1);
        invert(A.elem,n,m+n-1);
    }
}
    
void purge_Sq(SqList &L){
    //删除L中冗余的元素，即使操作之后的顺序表中只保留
    //操作之前表中所有的值都不相同的元素
    int j,k = -1,i;
    for(i = 0;i<L.length;++i){
        j = 0;
        while(j<=k&&L.elem[j]!=L.elem[i]){
            ++j;
        }
        if(k==-1||j>k){
            L.elem[++k] = L.elem[i];
        }
    }
    L.length = k+1;
}

//主函数
int main(){
    int maxsize,i,e,l,pos,s,t;
    SqList list;
    bool f;

    while(1){
        printf("1.初始化\n");
        printf("2.输入\n");
        printf("3.元素定位\n");
        printf("4.遍历\n");
        printf("5.插入\n");
        printf("6.删除元素\n");
        printf("7.销毁线性表\n");
        printf("8.线性表比较\n");
        printf("9.顺序表逆置\n");
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
                cout << "输入插入位置";
                cin >> pos;
                cout << "插入的数";
                cin >> e;
                f = ListInsert(list,pos,e);
                if(f){
                    cout << "插入成功" << endl;
                }else{
                    cout << "插入失败" << endl;
                }
                system("pause");
                system("cls");
                break;
            case 6:
                cout << "输入删除位置";
                cin >> pos;
                f = ListDelete(list,pos,e);
                if(f){
                    cout << "删除成功" << endl;
                }else{
                    cout << "删除失败" << endl;
                }
                system("pause");
                system("cls");
                break;
            case 7:
                DestroyList( list );
                system("pause");
                system("cls");
                break;
            case 8:
                //int i = compare(list,list);//
                system("pause");
                system("cls");
                break;
            case 9:
                cout << "起点" ;
                cin >> s;
                cout << "终点";
                cin >> t;
                invert(list.elem,s,t);
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