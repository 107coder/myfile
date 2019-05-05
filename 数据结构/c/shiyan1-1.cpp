#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType ;
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
        L.elem[j+1] = L.elem[j];
        L.elem[i-1] = e;
    ++L.length;
    return OK;
}

//显示数据
Status TraverseList(SqList L) {
        if(L.length == 0)
            cout << "该顺序表为空！";
        else
            cout << "该顺序表里的元素为：";

        for(int i=0; i<L.length; i++){
            cout << L.elem[i];
            if(i != L.length-1) cout << ",";
        }

        cout << endl;
}
//清空数据表
Status ClearList(SqList &L) {
    L.length=0;
    return OK;
}
//判断线性表是否为空
Status ListEmpty(SqList L) {
    if(L.length == 0)
        cout << "该线性表为空！"<<endl;
    else
        cout << "该线性表不为空！"<<endl;
    return OK;
}
//求线性表得长度
Status ListLength(SqList L) {
    cout << "该线性表得长度为：" << L.length <<endl;
    return OK;
}

//获取指定位置的元素
Status GetElem(SqList L,int i,ElemType &e) {
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}
//求前驱
Status PriorElem(SqList &L,ElemType cur_e,ElemType &pre_e)
{
    int i = 0;
    for( i=0; i<L.length;i++)
        if(L.elem[i] == cur_e) break;

    if(i==0){
        cout << "该元素为第一个元素，无前驱！\n";  return ERROR;
    }else if(i>=L.length){
        cout << "表中无此元素！\n";  return ERROR;
    }else{
        pre_e = L.elem[i-1];
        cout << "该元素的前驱为"<<pre_e<<"\n";
    }
    return OK;
}
//求后继

Status NextElem(SqList &L,ElemType cur_e,ElemType &next_e)
{
    int i = 0;
    for( i=0; i<L.length;i++)
        if(L.elem[i] == cur_e) break;

    if(i==L.length-1){
        cout << "该元素为最后一个元素，无后继！\n";  return ERROR;
    }else if(i>=L.length){
        cout << "表中无此元素！\n"; return ERROR;
    }else{
        next_e = L.elem[i+1];
        cout << "该元素的后继为："<<next_e<<"\n";
    }
    return OK;
}
//删除指定位置的元素
Status ListDelete(SqList &L,ElemType i)
{
    if( i<1 || i>(L.length-1)) return ERROR;
    for(int j=i-1; j<L.length-1;j++)
        L.elem[j] = L.elem[j+1];
    --L.length;
    return OK;
}

//打印提示信息
void ShowInfo()
{
    cout << "1710121183-------崔少峰\n";
    cout << "1----清空线性表\n";
    cout << "2----判断线性表是否为空\n";
    cout << "3----求线性表长度\n";
    cout << "4----获取线性表指定位置元素\n";
    cout << "5----求前驱\n";
    cout << "6----求后继\n";
    cout << "7----在线性表指定位置中插入元素\n";
    cout << "8----删除线性表指定位置元素\n";
    cout << "9----显示线性表\n";
    cout << "0-----清除屏幕\n";

    cout << "\t退出，输入一个负数！\n";

}

int main(void) {
    SqList L;
    InitList(L);

    ShowInfo();

    int in;
    while(true) {
        cout << "请输入一个操作码：";
        cin >> in;
        if(in < 0) in = -1;
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
            int $status = GetElem(L,n,e);
            if($status == 0){
                cout << "查询的位置不存在！\n";
            } else{
                cout << "顺序表中第"<< n <<"个元素为：" << e <<endl;
            }
            break;
        }
        case 5:{
            int in = 0;
            ElemType out;
            cout <<"请输入元素：";
            cin >> in;
            PriorElem(L,in,out);

            break;
        }
        case 6:{
            int in = 0;
            ElemType out;
            cout <<"请输入元素：";
            cin >> in;
            NextElem(L,in,out);
            break;
        }

        case 7: {
            int i;
            ElemType e;
            cout << "请输入要插入的位置：";
            cin >> i;
            cout << "请输入要插入的值：";
            cin >> e;
            int $status = ListInsert(L,i,e);
            if($status == 0) cout << "输入的位置不存在，插入失败！\n";
            else cout << "插入成功！\n";
            break;
        }
        case 8:{
            int in = 0;
            cout << "请输入删除元素的位置：";
            cin >>in;
            int $status = ListDelete(L,in);
            if($status == 1) cout << "删除成功！\n";
            else cout << "位置不存在，删除失败！\n";
            break;
        }
        case 9:
            TraverseList(L);
            break;
        case 0:
            system("cls");
            ShowInfo();
            break;
        case -1: return 0;
        default: cout << "您输入了错误的操作码，"; break;
        }
    }


    return 0;
}
