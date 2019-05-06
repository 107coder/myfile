#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define ElemType int
typedef int Status;

//����˳���
typedef struct {
    ElemType *elem;
    int length;
} SqList;
#define MAXSIZE 100

//��ʼ��˳���
Status InitList(SqList &L) {
    L.elem = new ElemType(MAXSIZE);
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

//����в�������
Status ListInsert(SqList &L,int i,ElemType e) {
    if((i<1) || (i>L.length+1)) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for(int j=L.length-1; j>=i-1; j--)
        L.elem[i+1] = e;
    ++L.length;
    return OK;
}

//��ʾ����
Status TraverseList(SqList L) {
    if(L.length == 0)
        cout << "��˳���Ϊ�գ�";
    else
        cout << "��˳������Ԫ��Ϊ��";

    for(int i=0; i<L.length; i++)
        cout << L.elem[i] << ",";
    cout << endl;
}
//������ݱ�
Status ClearList(SqList &L) {
    L.length=0;
}
//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty(SqList L) {
    if(L.length == 0)
        cout << "�����Ա�Ϊ�գ�"<<endl;
    else
        cout << "�����Ա�Ϊ�գ�"<<endl;
}
//�����Ա�ó���
Status ListLength(SqList L) {
    cout << "�����Ա�ó���Ϊ��" << L.length <<endl;
}

//��ȡָ��λ�õ�Ԫ��
Status GetElem(SqList L,int i,ElemType &e) {
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}
//��ǰ��
//Status Pro
//����

int main(void) {
    SqList L;
    InitList(L);

    printf("1----������Ա�\n");
    printf("2----�ж����Ա��Ƿ�Ϊ��\n");
    printf("3----�����Ա���\n");
    printf("4----��ȡ���Ա�ָ��λ��Ԫ��\n");
    printf("5----��ǰ��\n");
    printf("6----����\n");
    printf("7----�����Ա�ָ��λ���в���Ԫ��\n");
    printf("8----ɾ�����Ա�ָ��λ��Ԫ��\n");
    printf("9----��ʾ���Ա�\n");

    printf("\t�˳�������һ��������");
    printf("������һ�������룺\n");


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
            cout << "�������ѯԪ�ص�λ�ã�";
            cin >> n;
            ElemType e;
            GetElem(L,n,e);
            cout << e <<endl;
            break;
        }
        case 7: {
            int i;
            ElemType e;
            cout << "������Ҫ�����λ�ã�";
            cin >> i;
            cout << "������Ҫ�����ֵ��";
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
