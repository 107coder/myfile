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
        L.elem[j+1] = L.elem[j];
        L.elem[i-1] = e;
    ++L.length;
    return OK;
}

//��ʾ����
Status TraverseList(SqList L) {
        if(L.length == 0)
            cout << "��˳���Ϊ�գ�";
        else
            cout << "��˳������Ԫ��Ϊ��";

        for(int i=0; i<L.length; i++){
            cout << L.elem[i];
            if(i != L.length-1) cout << ",";
        }

        cout << endl;
}
//������ݱ�
Status ClearList(SqList &L) {
    L.length=0;
    return OK;
}
//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty(SqList L) {
    if(L.length == 0)
        cout << "�����Ա�Ϊ�գ�"<<endl;
    else
        cout << "�����Ա�Ϊ�գ�"<<endl;
    return OK;
}
//�����Ա�ó���
Status ListLength(SqList L) {
    cout << "�����Ա�ó���Ϊ��" << L.length <<endl;
    return OK;
}

//��ȡָ��λ�õ�Ԫ��
Status GetElem(SqList L,int i,ElemType &e) {
    if(i<1 || i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}
//��ǰ��
Status PriorElem(SqList &L,ElemType cur_e,ElemType &pre_e)
{
    int i = 0;
    for( i=0; i<L.length;i++)
        if(L.elem[i] == cur_e) break;

    if(i==0){
        cout << "��Ԫ��Ϊ��һ��Ԫ�أ���ǰ����\n";  return ERROR;
    }else if(i>=L.length){
        cout << "�����޴�Ԫ�أ�\n";  return ERROR;
    }else{
        pre_e = L.elem[i-1];
        cout << "��Ԫ�ص�ǰ��Ϊ"<<pre_e<<"\n";
    }
    return OK;
}
//����

Status NextElem(SqList &L,ElemType cur_e,ElemType &next_e)
{
    int i = 0;
    for( i=0; i<L.length;i++)
        if(L.elem[i] == cur_e) break;

    if(i==L.length-1){
        cout << "��Ԫ��Ϊ���һ��Ԫ�أ��޺�̣�\n";  return ERROR;
    }else if(i>=L.length){
        cout << "�����޴�Ԫ�أ�\n"; return ERROR;
    }else{
        next_e = L.elem[i+1];
        cout << "��Ԫ�صĺ��Ϊ��"<<next_e<<"\n";
    }
    return OK;
}
//ɾ��ָ��λ�õ�Ԫ��
Status ListDelete(SqList &L,ElemType i)
{
    if( i<1 || i>(L.length-1)) return ERROR;
    for(int j=i-1; j<L.length-1;j++)
        L.elem[j] = L.elem[j+1];
    --L.length;
    return OK;
}

//��ӡ��ʾ��Ϣ
void ShowInfo()
{
    cout << "1710121183-------���ٷ�\n";
    cout << "1----������Ա�\n";
    cout << "2----�ж����Ա��Ƿ�Ϊ��\n";
    cout << "3----�����Ա���\n";
    cout << "4----��ȡ���Ա�ָ��λ��Ԫ��\n";
    cout << "5----��ǰ��\n";
    cout << "6----����\n";
    cout << "7----�����Ա�ָ��λ���в���Ԫ��\n";
    cout << "8----ɾ�����Ա�ָ��λ��Ԫ��\n";
    cout << "9----��ʾ���Ա�\n";
    cout << "0-----�����Ļ\n";

    cout << "\t�˳�������һ��������\n";

}

int main(void) {
    SqList L;
    InitList(L);

    ShowInfo();

    int in;
    while(true) {
        cout << "������һ�������룺";
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
            cout << "�������ѯԪ�ص�λ�ã�";
            cin >> n;
            ElemType e;
            int $status = GetElem(L,n,e);
            if($status == 0){
                cout << "��ѯ��λ�ò����ڣ�\n";
            } else{
                cout << "˳����е�"<< n <<"��Ԫ��Ϊ��" << e <<endl;
            }
            break;
        }
        case 5:{
            int in = 0;
            ElemType out;
            cout <<"������Ԫ�أ�";
            cin >> in;
            PriorElem(L,in,out);

            break;
        }
        case 6:{
            int in = 0;
            ElemType out;
            cout <<"������Ԫ�أ�";
            cin >> in;
            NextElem(L,in,out);
            break;
        }

        case 7: {
            int i;
            ElemType e;
            cout << "������Ҫ�����λ�ã�";
            cin >> i;
            cout << "������Ҫ�����ֵ��";
            cin >> e;
            int $status = ListInsert(L,i,e);
            if($status == 0) cout << "�����λ�ò����ڣ�����ʧ�ܣ�\n";
            else cout << "����ɹ���\n";
            break;
        }
        case 8:{
            int in = 0;
            cout << "������ɾ��Ԫ�ص�λ�ã�";
            cin >>in;
            int $status = ListDelete(L,in);
            if($status == 1) cout << "ɾ���ɹ���\n";
            else cout << "λ�ò����ڣ�ɾ��ʧ�ܣ�\n";
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
        default: cout << "�������˴���Ĳ����룬"; break;
        }
    }


    return 0;
}
