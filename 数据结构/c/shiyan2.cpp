#include <iostream>
#include <windows.h>
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

//���ң�������İ�ֵ����
LNode *LocateElem(LinkList L,ElemType e)
{
    LinkList p;
    p = L->next;
    while(p &&  p->data != e)
        p = p->next;
    return p;
}

//case 2
//�ж���ʽ���Ƿ�Ϊ��
Status ListEmpty(LinkList &L)
{
    if(!(L->next)) return false;
    else return true;
}
// case 3
// �������Ա�ĳ���
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
//��ȡ�����е�Ԫ�� ȡֵ ��λ�ò���
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
    ����в���Ԫ��
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
//�������ɾ��
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
//��ʾ�����Ա�
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
//������Ա�
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
    cout << "������"<<n<<"��Ԫ�أ��Կո������";
    for(int i=0;i<n;i++)
    {
        LinkList p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r=p;
    }
}
//��ʽ��ĺϲ�
void MergeList_L()
{
    LinkList LA,LB,LC,pa,pb,pc;
    LA = new LNode;
    LB = new LNode;
    LC = new LNode;
    int i;
    cout << "Ҫ������A����ĳ���Ϊ:";
    cin >> i;
    CreatLitst_H(LA,i);
    cout << "Ҫ������B����ĳ���Ϊ��";
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
    cout << "�ϲ���ı�Ϊ��";
    TraverseList(LC);
    cout <<endl;

}
//��ӡ��ʾ��Ϣ
void ShowInfo()
{
    cout << "1710121183-------���ٷ�\n";
    cout << "1----�����ʽ��\n";
    cout << "2----�ж���ʽ���Ƿ�Ϊ��\n";
    cout << "3----����ʽ����\n";
    cout << "4----��ȡ��ʽ��ָ��λ��Ԫ��\n";
    cout << "5----����ʽ��ָ��λ���в���Ԫ��\n";
    cout << "6----ɾ����ʽ��ָ��λ��Ԫ��\n";
    cout << "7----��ʾ��ʽ��\n";
    cout << "8----��ʽ��ĺϲ�\n";
    cout << "0-----�����Ļ\n";

    cout << "\t�˳�������һ��������\n";
}


int main(){
    ShowInfo();
    LinkList L;
    int s = InitList(L);
    if(s == OK) cout << "�����ʼ���ɹ���\n";
    while(true) {
        cout << "������һ�������룺";
        int in;
        cin >> in;
        if(in < 0) in = -1;
        switch(in){
        case 1:
            {
                int sta = ClearList(L);
                if(sta == OK) cout << "����б�ɹ���\n";
            }
            break;
        case 2:
            {
                bool sta = ListEmpty(L);
                if(sta)cout << "�����Ա�Ϊ�գ�";
                else cout << "�����Ա�Ϊ�գ�";
                cout << endl;
            }
            break;
        case 3:
            {
                int length = 0;
                ListLength(L,length);
                cout << "����ʽ��ĳ���Ϊ��" << length << endl;
            }
            break;
        case 4:
            {
                cout << "��������Ҫ��ѯ��λ�ã�";
                int i;
                cin >> i;
                ElemType e;
                int sta = GetElem(L,i,e);
                if(sta == OK)
                    cout << "��λ���ϵ�Ԫ��Ϊ��"<< e<<endl;
            }
          break;
        case 5:
            {
                int i=0;
                ElemType e;
                cout << "���������Ԫ�ص�λ�ã�";
                cin >> i;
                cout << "������Ҫ����Ԫ�ص�ֵ��";
                cin >> e;
                int sta = ListInsrt(L,i,e);
                if(sta == OK) cout << "����ɹ���\n";
                if(sta == ERROR) cout << "����ʧ�ܣ�\n";
            }
            break;
        case 6:
            {
                int in = 0;
                cout << "������Ҫɾ����λ�ã�";
                cin >> in;
                int sta = ListDelete(L,in);
                if(sta == 1) cout << "ɾ���ɹ���\n";
                else if(sta == 0) cout << "ɾ��ʧ�ܣ������˲��Ϸ������֣�";
            }
            break;
        case 7:
            {
                cout << "����ʽ���Ԫ��Ϊ��";
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
        default: cout << "�������˴���Ĳ����룬"; break;
        }
    }
    return 0;
}
