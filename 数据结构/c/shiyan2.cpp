#include <iostream>
#include <windows.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int ElemType;
typedef int Status;
//定义表的结构
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化该链表
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

//查找，单链表的按值查找
LNode *LocateElem(LinkList L,ElemType e)
{
    LinkList p;
    p = L->next;
    while(p &&  p->data != e)
        p = p->next;
    return p;
}

//case 2
//判断链式表是否为空
Status ListEmpty(LinkList &L)
{
    if(!(L->next)) return false;
    else return true;
}
// case 3
// 求现线性表的长度
Status ListLength(LinkList L,int &Length)
{
    LinkList p = L->next;

    while(p)
    {
        p = p->next;
        Length++;
    }
    return OK;
}
//case 4
//获取链表中的元素 取值 按位置查找
Status GetElem(LinkList L,int i,ElemType &e)
{
    LinkList p;
    p = L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i) return ERROR;
    e=p->data;
    return OK;
}
/**
    case 5
    向表中插入元素
*/
Status ListInsrt(LinkList &L,int i,ElemType e)
{
    LinkList p = L;
    int j = 0;
    while(p && (j<i-1))
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i-1) return ERROR;
    LinkList s = new LNode;
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}
//case 6
//单链表的删除
Status ListDelete(LinkList &L,int i)
{
    LinkList p,q;
    p = L;
    int j = 0;
    while((p->next) && (j<i-1))
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || (j>i-1)) return ERROR;
    q = p->next;
    p -> next = q->next;
    delete q;
    return OK;
}

//case 7
//显示该线性表
Status TraverseList(LinkList L)
{
     LinkList p = L->next;
    if(!p) return ERROR;
    while(p)
    {
        cout << p->data;
        p = p->next;
        if(p) cout << ", ";
    }
    return OK;
}

//case 1
//清空线性表
Status ClearList(LinkList &L)
{
    LinkList p = L->next,q;
    int length = 0;
    if(!p)
    { return OK;}

    while(p)
    {
        p = p->next;
        length++;
    }
    p = L;
    while(length != 0){
        q = p->next;
        p->next = q->next;
        delete q;
        length--;
    }
    return OK;
}

void CreatLitst_H(LinkList &L,int n)
{
    L = new LNode;
    L->next = NULL;
    LinkList r = L;
    cout << "请输入"<<n<<"个元素，以空格隔开：";
    for(int i=0;i<n;i++)
    {
        LinkList p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r=p;
    }
}
//链式表的合并
void MergeList_L()
{
    LinkList LA,LB,LC,pa,pb,pc;
    LA = new LNode;
    LB = new LNode;
    LC = new LNode;
    int i;
    cout << "要创建的A链表的长度为:";
    cin >> i;
    CreatLitst_H(LA,i);
    cout << "要创建的B链表的长度为：";
    cin >>i;
    CreatLitst_H(LB,i);

    pa = LA->next;
    pb = LB->next;
    LC=LA;
    pc = LC;
    while(pa&&pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc ->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    delete LB;
    cout << "合并后的表为：";
    TraverseList(LC);
    cout <<endl;

}
//打印提示信息
void ShowInfo()
{
    cout << "1710121183-------崔少峰\n";
    cout << "1----清空链式表\n";
    cout << "2----判断链式表是否为空\n";
    cout << "3----求链式表长度\n";
    cout << "4----获取链式表指定位置元素\n";
    cout << "5----在链式表指定位置中插入元素\n";
    cout << "6----删除链式表指定位置元素\n";
    cout << "7----显示链式表\n";
    cout << "8----链式表的合并\n";
    cout << "0-----清除屏幕\n";

    cout << "\t退出，输入一个负数！\n";
}


int main(){
    ShowInfo();
    LinkList L;
    int s = InitList(L);
    if(s == OK) cout << "链表初始化成功！\n";
    while(true) {
        cout << "请输入一个操作码：";
        int in;
        cin >> in;
        if(in < 0) in = -1;
        switch(in){
        case 1:
            {
                int sta = ClearList(L);
                if(sta == OK) cout << "清空列表成功！\n";
            }
            break;
        case 2:
            {
                bool sta = ListEmpty(L);
                if(sta)cout << "该线性表不为空！";
                else cout << "该线性表为空！";
                cout << endl;
            }
            break;
        case 3:
            {
                int length = 0;
                ListLength(L,length);
                cout << "该链式表的长度为：" << length << endl;
            }
            break;
        case 4:
            {
                cout << "请输入您要查询的位置：";
                int i;
                cin >> i;
                ElemType e;
                int sta = GetElem(L,i,e);
                if(sta == OK)
                    cout << "该位置上的元素为："<< e<<endl;
            }
          break;
        case 5:
            {
                int i=0;
                ElemType e;
                cout << "请输入插入元素的位置：";
                cin >> i;
                cout << "请输入要插入元素的值：";
                cin >> e;
                int sta = ListInsrt(L,i,e);
                if(sta == OK) cout << "插入成功！\n";
                if(sta == ERROR) cout << "插入失败！\n";
            }
            break;
        case 6:
            {
                int in = 0;
                cout << "请输入要删除的位置：";
                cin >> in;
                int sta = ListDelete(L,in);
                if(sta == 1) cout << "删除成功！\n";
                else if(sta == 0) cout << "删除失败，输入了不合法的数字！";
            }
            break;
        case 7:
            {
                cout << "该链式表的元素为：";
                int sta = TraverseList(L);
                cout << endl;
            }
            break;

        case 8:
            {
                MergeList_L();
            }
            break;
        case 0:
            {
                system("cls");
                ShowInfo();
            }
            break;
       case -1: return 0;
        default: cout << "您输入了错误的操作码，"; break;
        }
    }
    return 0;
}
