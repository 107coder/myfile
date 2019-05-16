#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define ElemType int
typedef int Status;

//建立顺序表
typedef struct {
    ElemType *elem;
    int length;
} SqList;
#define MAXSIZE 100

//初始化顺序表
Status InitList(SqList &L) {
    L.elem = new ElemType(MAXSIZE);
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

//向表中插入数据
Status ListInsert(SqList &L,int i,ElemType e) {
    if((i<1) || (i>L.length+1)) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for(int j=L.length-1; j>=i-1; j--)
        L.elem[i+1] = e;
    ++L.length;
    return OK;
}

//显示数据
Status TraverseList(SqList L) {
    if(L.length == 0)
        cout << "该顺序表为空！";
    else
        cout << "该顺序表里的元素为：";

    for(int i=0; i<L.length; i++)
        cout << L.elem[i] << ",";
    cout << endl;
}
//清空数据表
Status ClearList(SqList &L) {
    L.length=0;
}
//判断线性表是否为空
Status ListEmpty(SqList L) {
    if(L.length == 0)
        cout << "该线性表为空！"<<endl;
    else
        cout << "该线性表不为空！"<<endl;
}
//求线性表得长度
Status ListLength(SqList L) {
    cout << "该线性表得长度为：" << L.length <<endl;
}

//获取指定位置的元素
Status GetElem(SqList L,int i,ElemType &e) {
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}
//求前驱
//Status Pro
//求后继

int main(void) {
    SqList L;
    InitList(L);

    printf("1----清空线性表\n");
    printf("2----判断线性表是否为空\n");
    printf("3----求线性表长度\n");
    printf("4----获取线性表指定位置元素\n");
    printf("5----求前驱\n");
    printf("6----求后继\n");
    printf("7----在线性表指定位置中插入元素\n");
    printf("8----删除线性表指定位置元素\n");
    printf("9----显示线性表\n");

    printf("\t退出，输入一个负数；");
    printf("请输入一个操作码：\n");


    int in;
    while(true) {
        cin >> in;
        if(in < 0) in = 0;
        switch(in) {

        case 1:
            ClearList(L);
            break;
        case 2:
            ListEmpty(L);
            break;
        case 3:
            ListLength(L);
            break;
        case 4: {
            int n = 0;
            cout << "请输入查询元素的位置：";
            cin >> n;
            ElemType e;
            GetElem(L,n,e);
            cout << e <<endl;
            break;
        }
        case 7: {
            int i;
            ElemType e;
            cout << "请输入要插入的位置：";
            cin >> i;
            cout << "请输入要插入的值：";
            cin >> e;
            ListInsert(L,i,e);
            break;
        }
        case 9:
            TraverseList(L);
            break;
        case 0:
            return 0;
        }
    }





    return 0;
}
