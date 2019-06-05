#include <iostream>
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


int main()
{
    LinkList &L;
    InitList( L);

    return 0;
}

