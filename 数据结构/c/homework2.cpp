#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1


typedef int ElemType;
typedef int Status;
//�����Ľṹ
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//��ʼ��������
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

