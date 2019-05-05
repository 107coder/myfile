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
            cout << "��ʽջ����:\n";
            cout << "��ջ�ɹ���\n";
            cout << "1--Ԫ����ջ��\n";
            cout << "2--Ԫ�س�ջ��\n";
            cout << "3--ȡջ��Ԫ�أ�\n";
            cout << "0--��յ�ǰ��ͼ��\n";
            cout << "-1-������Ŀ¼��\n";
        }break;
    case 2:
        {
            cout << "˳��ջ����:\n";
            cout << "��ջ�ɹ���\n";
            cout << "1--Ԫ����ջ��\n";
            cout << "2--Ԫ�س�ջ��\n";
            cout << "3--ȡջ��Ԫ�أ�\n";
            cout << "0--��յ�ǰ��ͼ��\n";
            cout << "-1-������Ŀ¼��\n";
        }break;
    case 3:
        {
            cout << "��ʽ���в���:\n";
            cout << "���ӳɹ���\n";
            cout << "1--Ԫ����ӣ�\n";
            cout << "2--Ԫ�س��ӣ�\n";
            cout << "3--ȡ��ͷԪ�أ�\n";
            cout << "0--��յ�ǰ��ͼ��\n";
            cout << "-1-������Ŀ¼��\n";
        }break;
    case 4:
        {
            cout << "˳����в���:\n";
            cout << "���ӳɹ���\n";
            cout << "1--Ԫ����ӣ�\n";
            cout << "2--Ԫ�س��ӣ�\n";
            cout << "3--ȡ��ͷԪ�أ�\n";
            cout << "0--��յ�ǰ��ͼ��\n";
            cout << "-1-������Ŀ¼��\n";
        }break;
    default: break;

    }
}

int select()
{
    int sel;
    cout << "1--��ʽջ������\n";
    cout << "2--˳��ջ������\n";
    cout << "3--˳��Ӳ�����\n";
    cout << "4--��ʽ�Ӳ�����\n";
    cout << "0--�˳�����!\n";
    cout << "��ѡ������Ҫ�Ĳ�����";
    re: cin >> sel;
    if(sel<0 || sel > 4)
    {
        cout << "����ѡ������������ѡ��";
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
* ��ʽջ����
*/
//������ʽջ�ṹ
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;
//1-1������ʽջ����ʼ��
Status InitStack(LinkStack &S)
{
    S=NULL;
    return OK;
}
//1-2��ջ
Status Push(LinkStack &S,SElemType e)
{
    LinkStack p = new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;
}
//1-3��ջ
Status Pop(LinkStack &S,SElemType &e)
{
    if(S==NULL) return ERROR;
    e=S->data;
    LinkStack p=S;
    S=S->next;
    delete p;
    return OK;
}
//1-4ȡջ��Ԫ��
SElemType GetTop(LinkStack S)
{
    if(S!=NULL)
        return S->data;
    else
        return ERROR;
}
/*
* ˳��ջ����
*/
//����˳��ջ�ṹ
#define MAXSIZE 100;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
//2-1 ����˳��ջ ��ʼ��
Status InitStack(SqStack &S)
{
    S.base = new SElemType;
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//2-2 ��ջ
Status Push(SqStack &S,SElemType e)
{
    if(S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}
//2-3 ��ջ
Status Pop(SqStack &S,SElemType &e)
{
    if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
//2-4 ȡջ��Ԫ��
SElemType GetTop(SqStack S)
{
    if(S.top != S.base)
        return *(S.top-1);
    else
        return ERROR;
}

/*
* ѭ������
*/
//�����ṹ
#define MAXQSIZE 100
typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
///3-1���еĴ��������ʼ��
Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//3-2��Ӳ���
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}
//3-3���Ӳ���
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}
//3-4ȥ��ͷԪ��
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
                if(InitStack(S)==OK) cout << "��ʼ���ɹ���\n";
                else cout << "��ʼ��ʧ�ܣ�\n";
                while(true)
                {
                    cout << "�������������";
                    int item;
                    cin >> item;
                    if(item == -1){ system("cls"); goto indexMenu;}
                    if(item == 0){ system("cls"); goto clearv1;}

                    switch(item)
                    {
                        case 1:
                            {
                                SElemType e;
                                cout << "������Ҫ��ջ������(һ������)��";
                                cin >> e;
                                if(Push(S,e) == OK){cout << "����ɹ���\n";}
                                else {cout << "����ʧ�ܣ�\n";}
                            }break;
                             case 2:
                            {
                                SElemType e;
                                if(Pop(S,e)==OK){cout << "��ջ�ɹ�����ջ��Ԫ��Ϊ��"<<e<<endl;}
                                else {cout << "��ջΪ�գ���ջʧ�ܣ�\n";}
                            }break;
                        case 3:
                            {
                                if(GetTop(S)==ERROR){cout << "��ջΪ�գ���ջ��Ԫ�أ�\n";}
                                else{cout << "ջ����Ԫ��Ϊ��"<<GetTop(S)<<endl;}

                            }break;
                            default: cout<< "����Ĳ���������!\n";
                    }

                }

            }break;
            case 2:
            {
                SqStack S;
                clearv2:info(sel);
                    if(InitStack(S)==OK) cout << "��ʼ���ɹ���\n";
                    else cout << "��ʼ��ʧ�ܣ�\n";
                while(true)
                {
                    cout << "�������������";
                    int item;
                    cin >> item;
                    if(item == -1){ system("cls");  goto indexMenu;}
                    if(item == 0){ system("cls"); goto clearv2;}

                    switch(item)
                    {
                        case 1:
                            {
                                SElemType e;
                                cout << "������Ҫ��ջ������(һ������)��";
                                cin >> e;
                                if(Push(S,e) == OK){cout << "����ɹ���\n";}
                                else {cout << "����ʧ�ܣ�\n";}
                            }break;
                        case 2:
                            {
                                SElemType e;
                                if(Pop(S,e)==OK){cout << "��ջ�ɹ�����ջ��Ԫ��Ϊ��"<<e<<endl;}
                                else {cout << "��ջΪ�գ���ջʧ�ܣ�\n";}
                            }break;
                        case 3:
                            {
                                if(GetTop(S)==ERROR){cout << "��ջΪ�գ���ջ��Ԫ�أ�\n";}
                                else{cout << "ջ����Ԫ��Ϊ��"<<GetTop(S)<<endl;}

                            }break;
                            default: cout<< "����Ĳ���������!\n";
                    }
                }

            }break;
            case 3:
            {
                clearv3:info(sel);
                SqQueue Q;
                if(InitQueue(Q)==OK) cout << "��ʼ���ɹ���\n";
                else cout << "��ʼ��ʧ�ܣ�\n";
                while(true)
                {
                      cout << "�������������";
                int item;
                cin >> item;
                if(item == -1){ system("cls");  goto indexMenu;}
                if(item == 0){ system("cls"); goto clearv3;}
                switch(item)
                    {
                        case 1:
                            {
                                QElemType e;
                                cout << "������Ҫ��ջ������(һ������)��";
                                cin >> e;
                                if(EnQueue(Q,e) == OK){cout << "����ɹ���\n";}
                                else {cout << "����ʧ�ܣ�\n";}
                            }break;
                        case 2:
                            {
                                QElemType e;
                                if(DeQueue(Q,e)==OK){cout << "��ջ�ɹ�����ջ��Ԫ��Ϊ��"<<e<<endl;}
                                else {cout << "��ջΪ�գ���ջʧ�ܣ�\n";}
                            }break;
                        case 3:
                            {
                                if(GetHead(Q)==ERROR){cout << "��ջΪ�գ���ջ��Ԫ�أ�\n";}
                                else{cout << "ջ����Ԫ��Ϊ��"<<GetHead(Q)<<endl;}

                            }break;
                            default: cout<< "����Ĳ���������!\n";
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
