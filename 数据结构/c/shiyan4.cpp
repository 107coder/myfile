
/*
* 二叉树的操作
* 时间2019年4月18日11:11:58
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
    cout << "1710121183-崔少峰\n";
    cout << "生成二叉树……………………\n";
    cout << "二叉树初始化成功！\n";
    cout << "1--创建二叉树！\n";
    cout << "2--先序遍历二叉树！\n";
    cout << "3--中序遍历二叉树！\n";
    cout << "4--后序遍历二叉树！\n";
    cout << "5--中序非递归遍历二叉树！\n";
    cout << "6--层序遍历二叉树！\n";
    cout << "7--求二叉树深度！\n";
    cout << "8--求二叉树叶子节点个数！\n";
    cout << "0--清空视图！\n";
    cout << "-1-退出该程序！\n";
}


//-----------二叉树的二叉链表存储表示---------------
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;
typedef BiTree SElemType;

typedef BiTree QueueElemType;
//-----------先序遍历的顺序建立二叉链表------------------
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
//------------先序遍历二叉树---------------------
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T->data << ' ';
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//------------中序遍历二叉树---------------------
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data<<" ";
        InOrderTraverse(T->rchild);
    }
}
//------------后序遍历二叉树---------------------
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data<< " ";
    }
}
//-------------非递归实现中序遍历-----------------

//定义链式栈结构
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode,*LinkStack;
//初始化一个空栈
Status InitStack(LinkStack &S)
{
    S=NULL;
    return OK;
}
//判断栈是否为空
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
//实现入栈
Status Push(LinkStack &S,SElemType e)
{
    LinkStack p = new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;
}
//出栈方法
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
//遍历
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
//---------------层序遍历二叉树----------------
//定义链队的结构体
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
//判断队列是否为空
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear){
        return OK;
    }else
    {
        return ERROR;
    }
}
//链式队列的建队与初始化
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next=NULL;
    return OK;
}
//链队的入队
Status EnQueue(LinkQueue &Q,QueueElemType e)
{
    QueuePtr p=new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
//链队的出队
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
//---------------求二叉树的深度----------------
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
//---------------求二叉树的节点个数----------------
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
        cout << "请输入操作数：";
        cin >> item;
        switch(item)
        {
        case 1:
        {
            cout << "请输入您要插入的数据：";
            //String str = "ABC##DE#G##F###":
            //for(int i=0; i<str.length(); i++){
                CreateBiTree(T);
            //}


        }
        break;
        case 2:
        {
            cout << "先序遍历的结果为：";
            PreOrderTraverse(T);
            cout << endl;
        }
        break;
        case 3:
        {
            cout << "中序遍历的结果为：";
            InOrderTraverse(T);
            cout << endl;
        }
        break;
        case 4:
        {
            cout << "后序遍历的结果为：";
            PostOrderTraverse(T);
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "中序非递归遍历的结果为：";
            InOrderTraverse2(T);
            cout << endl;
        }
        break;
          case 6:
        {
            cout << "层序遍历的结果为：";
            LevelOrderTraverse(T);
            cout << endl;
        }
        break;case 7:
        {
            cout << "二叉树的深度为：";
            cout << Depth(T);
            cout << endl;
        }
        break;case 8:
        {
            cout << "该二叉树的叶子节点数为：";
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
            cout << "输入有误！\n";
        }
        break;
        }
    }


    return 0;
}
