
/*
* �������Ĳ���
* ʱ��2019��4��18��11:11:58
*/
#include <iostream>
#include <windows.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef char TElemType;
typedef int Status;

typedef int QElemType;

void showinfo()
{
    cout << "1710121183-���ٷ�\n";
    cout << "���ɶ���������������������\n";
    cout << "��������ʼ���ɹ���\n";
    cout << "1--������������\n";
    cout << "2--���������������\n";
    cout << "3--���������������\n";
    cout << "4--���������������\n";
    cout << "5--����ǵݹ������������\n";
    cout << "6--���������������\n";
    cout << "7--���������ȣ�\n";
    cout << "8--�������Ҷ�ӽڵ������\n";
    cout << "0--�����ͼ��\n";
    cout << "-1-�˳��ó���\n";
}


//-----------�������Ķ�������洢��ʾ---------------
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;
typedef BiTree SElemType;

typedef BiTree QueueElemType;
//-----------���������˳������������------------------
void CreateBiTree(BiTree &T)
{
    TElemType ch;
    cin >> ch;
    if(ch=='#')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//------------�������������---------------------
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T->data << ' ';
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//------------�������������---------------------
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data<<" ";
        InOrderTraverse(T->rchild);
    }
}
//------------�������������---------------------
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data<< " ";
    }
}
//-------------�ǵݹ�ʵ���������-----------------

//������ʽջ�ṹ
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode,*LinkStack;
//��ʼ��һ����ջ
Status InitStack(LinkStack &S)
{
    S=NULL;
    return OK;
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
    if(S==NULL)
    {
        return OK;
    }
    else
    {

        return ERROR;
    }
}
//ʵ����ջ
Status Push(LinkStack &S,SElemType e)
{
    LinkStack p = new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;
}
//��ջ����
Status Pop(LinkStack &S,SElemType &e)
{
    if(S==NULL)
        return ERROR;
    e=S->data;
    LinkStack p=S;
    S=S->next;
    delete p;
    return OK;
}
//����
void InOrderTraverse2(BiTree T)
{
    LinkStack S;
    InitStack(S);
    BiTree p = T;
    BiTree q = new BiTNode;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,q);
            cout << q->data << " ";
            p = q->rchild;
        }
    }
}
//---------------�������������----------------
//�������ӵĽṹ��
typedef struct QNode
{
    QueueElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear){
        return OK;
    }else
    {
        return ERROR;
    }
}
//��ʽ���еĽ������ʼ��
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next=NULL;
    return OK;
}
//���ӵ����
Status EnQueue(LinkQueue &Q,QueueElemType e)
{
    QueuePtr p=new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
//���ӵĳ���
Status DeQueue(LinkQueue &Q,QueueElemType &e)
{
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p=Q.front->next;
    e=p->data;
    Q.front->next = p->next;
    if(Q.rear==p) Q.rear=Q.front;
    delete p;
    return OK;
}
void LevelOrderTraverse(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p = T;
    BiTree q = new BiTNode;
    if(T != NULL){
        EnQueue(Q,T);
    }

    while(QueueEmpty(Q) == ERROR)
    {
        DeQueue(Q,p);
        cout << p->data << " ";

        if(p->lchild != NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild != NULL){
            EnQueue(Q,p->rchild);
        }
    }
}
//---------------������������----------------
int Depth(BiTree T)
{
    if(T==NULL) return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m>n){
            return (m+1);
        }else{
            return (n+1);
        }
    }
}
//---------------��������Ľڵ����----------------
int NodeCount(BiTree T)
{
    if(!T) return 0;
    else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
int main(void)
{
    int item=0;
    while(true)
    {
        BiTree T;
        if(item==0)
            showinfo();
        cout << "�������������";
        cin >> item;
        switch(item)
        {
        case 1:
        {
            cout << "��������Ҫ��������ݣ�";
            //String str = "ABC##DE#G##F###":
            //for(int i=0; i<str.length(); i++){
                CreateBiTree(T);
            //}


        }
        break;
        case 2:
        {
            cout << "��������Ľ��Ϊ��";
            PreOrderTraverse(T);
            cout << endl;
        }
        break;
        case 3:
        {
            cout << "��������Ľ��Ϊ��";
            InOrderTraverse(T);
            cout << endl;
        }
        break;
        case 4:
        {
            cout << "��������Ľ��Ϊ��";
            PostOrderTraverse(T);
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "����ǵݹ�����Ľ��Ϊ��";
            InOrderTraverse2(T);
            cout << endl;
        }
        break;
          case 6:
        {
            cout << "��������Ľ��Ϊ��";
            LevelOrderTraverse(T);
            cout << endl;
        }
        break;case 7:
        {
            cout << "�����������Ϊ��";
            cout << Depth(T);
            cout << endl;
        }
        break;case 8:
        {
            cout << "�ö�������Ҷ�ӽڵ���Ϊ��";
            cout << NodeCount(T);
            cout << endl;
        }
        break;case 0:
        {
            system("cls");
        }
        break;
        case -1:
            return 0;
        default:
        {
            cout << "��������\n";
        }
        break;
        }
    }


    return 0;
}
