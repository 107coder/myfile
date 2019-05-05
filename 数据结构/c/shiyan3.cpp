#include <iostream>
#include <windows.h>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1


void info(int sel)
{
    switch(sel)
    {
    case 1:
        {
            cout << "链式栈操作:\n";
            cout << "建栈成功！\n";
            cout << "1--元素入栈！\n";
            cout << "2--元素出栈！\n";
            cout << "3--取栈顶元素！\n";
            cout << "0--清空当前视图！\n";
            cout << "-1-返回主目录！\n";
        }break;
    case 2:
        {
            cout << "顺序栈操作:\n";
            cout << "建栈成功！\n";
            cout << "1--元素入栈！\n";
            cout << "2--元素出栈！\n";
            cout << "3--取栈顶元素！\n";
            cout << "0--清空当前视图！\n";
            cout << "-1-返回主目录！\n";
        }break;
    case 3:
        {
            cout << "链式队列操作:\n";
            cout << "建队成功！\n";
            cout << "1--元素入队！\n";
            cout << "2--元素出队！\n";
            cout << "3--取队头元素！\n";
            cout << "0--清空当前视图！\n";
            cout << "-1-返回主目录！\n";
        }break;
    case 4:
        {
            cout << "顺序队列操作:\n";
            cout << "建队成功！\n";
            cout << "1--元素入队！\n";
            cout << "2--元素出队！\n";
            cout << "3--取队头元素！\n";
            cout << "0--清空当前视图！\n";
            cout << "-1-返回主目录！\n";
        }break;
    default: break;

    }
}

int select()
{
    int sel;
    cout << "1--链式栈操作！\n";
    cout << "2--顺序栈操作！\n";
    cout << "3--顺序队操作！\n";
    cout << "4--链式队操作！\n";
    cout << "0--退出程序!\n";
    cout << "请选择您需要的操作：";
    re: cin >> sel;
    if(sel<0 || sel > 4)
    {
        cout << "您的选择有误，请重新选择：";
        goto re;
    }else
    {
        return sel;
    }
}


typedef int SElemType;
typedef int QElemType;
typedef int Status;
/*
* 链式栈操作
*/
//定义链式栈结构
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
//1-1创建链式栈，初始化
Status InitStack(LinkStack &S)
{
    S=NULL;
    return OK;
}
//1-2入栈
Status Push(LinkStack &S,SElemType e)
{
    LinkStack p = new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;
}
//1-3出栈
Status Pop(LinkStack &S,SElemType &e)
{
    if(S==NULL) return ERROR;
    e=S->data;
    LinkStack p=S;
    S=S->next;
    delete p;
    return OK;
}
//1-4取栈顶元素
SElemType GetTop(LinkStack S)
{
    if(S!=NULL)
        return S->data;
    else
        return ERROR;
}
/*
* 顺序栈操作
*/
//定义顺序栈结构
#define MAXSIZE 100;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
//2-1 创建顺序栈 初始化
Status InitStack(SqStack &S)
{
    S.base = new SElemType;
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//2-2 入栈
Status Push(SqStack &S,SElemType e)
{
    if(S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}
//2-3 出栈
Status Pop(SqStack &S,SElemType &e)
{
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
//2-4 取栈顶元素
SElemType GetTop(SqStack S)
{
    if(S.top != S.base)
        return *(S.top-1);
    else
        return ERROR;
}

/*
* 循环队列
*/
//定义表结构
#define MAXQSIZE 100
typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
///3-1队列的创建于与初始化
Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//3-2入队操作
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}
//3-3出队操作
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}
//3-4去队头元素
SElemType GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.base[Q.front];
    else
        return ERROR;
}

int main()
{
    int sel;
    while(true)
    {
indexMenu:
        sel = select();
        if(sel == 0) break;
        system("cls");
        switch(sel)
        {
            case 1:
            {
                clearv1:info(sel);
                LinkStack S;
                if(InitStack(S)==OK) cout << "初始化成功！\n";
                else cout << "初始化失败！\n";
                while(true)
                {
                    cout << "请输入操作数：";
                    int item;
                    cin >> item;
                    if(item == -1){ system("cls"); goto indexMenu;}
                    if(item == 0){ system("cls"); goto clearv1;}

                    switch(item)
                    {
                        case 1:
                            {
                                SElemType e;
                                cout << "请输入要入栈的数据(一个整数)：";
                                cin >> e;
                                if(Push(S,e) == OK){cout << "插入成功！\n";}
                                else {cout << "插入失败！\n";}
                            }break;
                             case 2:
                            {
                                SElemType e;
                                if(Pop(S,e)==OK){cout << "出栈成功，出栈的元素为："<<e<<endl;}
                                else {cout << "该栈为空，出栈失败！\n";}
                            }break;
                        case 3:
                            {
                                if(GetTop(S)==ERROR){cout << "该栈为空，无栈顶元素！\n";}
                                else{cout << "栈顶的元素为："<<GetTop(S)<<endl;}

                            }break;
                            default: cout<< "输入的操作码有误!\n";
                    }

                }

            }break;
            case 2:
            {
                SqStack S;
                clearv2:info(sel);
                    if(InitStack(S)==OK) cout << "初始化成功！\n";
                    else cout << "初始化失败！\n";
                while(true)
                {
                    cout << "请输入操作数：";
                    int item;
                    cin >> item;
                    if(item == -1){ system("cls");  goto indexMenu;}
                    if(item == 0){ system("cls"); goto clearv2;}

                    switch(item)
                    {
                        case 1:
                            {
                                SElemType e;
                                cout << "请输入要入栈的数据(一个整数)：";
                                cin >> e;
                                if(Push(S,e) == OK){cout << "插入成功！\n";}
                                else {cout << "插入失败！\n";}
                            }break;
                        case 2:
                            {
                                SElemType e;
                                if(Pop(S,e)==OK){cout << "出栈成功，出栈的元素为："<<e<<endl;}
                                else {cout << "该栈为空，出栈失败！\n";}
                            }break;
                        case 3:
                            {
                                if(GetTop(S)==ERROR){cout << "该栈为空，无栈顶元素！\n";}
                                else{cout << "栈顶的元素为："<<GetTop(S)<<endl;}

                            }break;
                            default: cout<< "输入的操作码有误!\n";
                    }
                }

            }break;
            case 3:
            {
                clearv3:info(sel);
                SqQueue Q;
                if(InitQueue(Q)==OK) cout << "初始化成功！\n";
                else cout << "初始化失败！\n";
                while(true)
                {
                      cout << "请输入操作数：";
                int item;
                cin >> item;
                if(item == -1){ system("cls");  goto indexMenu;}
                if(item == 0){ system("cls"); goto clearv3;}
                switch(item)
                    {
                        case 1:
                            {
                                QElemType e;
                                cout << "请输入要入栈的数据(一个整数)：";
                                cin >> e;
                                if(EnQueue(Q,e) == OK){cout << "插入成功！\n";}
                                else {cout << "插入失败！\n";}
                            }break;
                        case 2:
                            {
                                QElemType e;
                                if(DeQueue(Q,e)==OK){cout << "出栈成功，出栈的元素为："<<e<<endl;}
                                else {cout << "该栈为空，出栈失败！\n";}
                            }break;
                        case 3:
                            {
                                if(GetHead(Q)==ERROR){cout << "该栈为空，无栈顶元素！\n";}
                                else{cout << "栈顶的元素为："<<GetHead(Q)<<endl;}

                            }break;
                            default: cout<< "输入的操作码有误!\n";
                        }
                }

            }break;
            case 4:
            {
                clearv4:info(sel);
                int item;
                cin >> item;
                if(item == -1){ system("cls");  goto indexMenu;}
                if(item == 0){ system("cls"); goto clearv4;}
            }break;
        }
  clearv:info(sel);
        int item;
        cin >> item;
        if(item == -1){ system("cls");  goto indexMenu;}
        if(item == 0){ system("cls"); goto clearv;}
    }

    return 0;
}
