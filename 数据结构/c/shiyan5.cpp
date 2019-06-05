/*
* ͼ�Ĳ���
* 2019��5��23��10:35:05
*/

#include <iostream>;

using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define FAIL -2;

//��ʾ��ʾ��Ϣ
void showMsg(string msg)
{
    cout << msg;
}

typedef char TElemType;
typedef int Status;
typedef int OtherInfo;
void showinfo()
{
    cout << "1710121183-���ٷ�\n";
    cout << "1--ʹ���ڽӾ�����ͼ��\n";
    cout << "2--ʹ���ڽӱ���ͼ��\n";
    cout << "3--������ȱ���ͼ��\n";
    cout << "4--������ȱ���ͼ��\n";
    cout << "5--Dijkstra�����·����\n";
    cout << "0--�����ͼ��\n";
    cout << "-1-�˳��ó���\n";
    cout << "---------����������룺";
}

//--------ͼ���ڽӾ����ʾ��ʽ------------
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
//���� �ڽӾ����һ���ܵĽṹ
typedef struct
{
    VerTexType vexs[MVNum];       //�����
    ArcType arcs[MVNum][MVNum];    //�������
    int vexnum,arcnum;              //ͼ�ĵ�ǰ�����ͱ���
}AMGraph;

//��λĳԪ�ص�λ�ã����ظ�λ�õ�����������û���ҵ�����ֱ�ӷ���FAIL��-2��
Status LocateVex(AMGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vexs[i] == v) return i;
    }
    return FAIL;
}
//�������涨���ͼ���ڽӾ��󣬲����г�ʼ���͸�ֵ
Status CreateUDN(AMGraph &G)
{
    cout << "�������ڽӾ���Ķ����� �ܱ������ÿո��������";
    cin >> G.vexnum >> G.arcnum;
    cout << "�������ڽӾ����"<<G.vexnum<<"���������Ϣ��"<<G.vexnum<<"�������ÿո��������";
    for(int i=0; i<G.vexnum; ++i)
    {
        cout << "--"<<i;
        cin >> G.vexs[i];
    }
    //��ʼ���ڽӾ��󣬰����е�ֵ����λ�����
    for(int i=0; i<G.vexnum; ++i)
    {
        for(int j=0; j<G.vexnum; ++j)
        {
            G.arcs[i][j] = MaxInt;
        }
    }

    for(int k=0; k<G.arcnum; ++k)  //�����ڽӾ���
    {
        int v1,v2,w,i,j;
        cout << "�����"<<k+1<<"���������Ķ����Ȩֵ��";
        cin >> v1 >> v2 >> w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}


//----------ͼ���ڽӱ�Ĵ洢�ṹ-------

#define MVNum 100
typedef struct ArcNode              //�߽ڵ�
{
    int adjvex;                     //�ñ���ָ��Ķ���λ��
    struct ArcNode * nextarc;       //ָ����һ���ߵ�ָ��
    OtherInfo info;                 //�ͱ���ص���Ϣ
}ArcNode;
typedef struct VNode                //������Ϣ
{
    VerTexType data;
    ArcNode *firstarc;              //ָ���һ�����������ָ��
}VNode,AdjList[MVNum];              //AdjList��ʾ�ڽӱ�����
typedef struct                      //�ڽӱ�
{
    AdjList vertices;
    int vexnum,arcnum;              //ͼ��ǰ�Ķ���ͱ���
}ALGraph;
//��λ����Ԫ�ص�λ�ã���������ֵ
Status LocateVex(ALGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vertices[i].data == v) return i;
    }
    return FAIL;
}
//ʹ���ڽӱ���ͼ
Status CreateUDG(ALGraph &G)
{//�����ڽӱ��ʾ������������ͼG
    cout << "�������ڽӾ���Ķ����� �ܱ������ÿո��������";
    cin >> G.vexnum >> G.arcnum;
    cout << "�������ڽӾ����"<<G.vexnum<<"���������Ϣ��"<<G.vexnum<<"�������ÿո��������";
    for(int i=0;i<G.vexnum; ++i)        //������㣬�������ͷ
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for(int k=0;k<G.vexnum; ++k)
    {
        int v1,v2,i,j;
        ArcNode* p1,*                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         p2;
        cin >> v1,v2;
        i = LocateVex(G,v1);
        j = LocateVex(G,v2);
        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;

        p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;

    }
    return OK;
}


//-------������ȱ�����ͨͼ------------
bool visited[MVNum];             //���ʱ�־���飬�䴦ֵΪ��false��
int FirstAdjVex(ALGraph G,int v)
{

}
int NextAdjVex(ALGraph G,int v,int w)
{

}
void DFS(ALGraph G,int v)
{ //�ӵ�v����������ݹ��������ȱ���ͼG
    cout << v;
    visited[v]=true;            //���ʵ�v�����㣬���÷��ʱ�־������Ӧ�ķ���Ϊtrue
    for(int w=FirstAdjVex(G,v);w>0;w=NextAdjVex(G,v,w))
    {//���μ��v�����еĶ���w��FirstAdjVex(G,v)��ʾV�ĵ�һ���ڽӵ�
        //NextAdjVex(G,v,w)��ʾv���w����һ���ڽӵ㣬w>=0�Ȱ����Ǵ����ڽӵ�
        if(!visited[w]) DFS(G,w);      //��v����δ���ʵ��ڽӶ���w�ݹ�

    }
}

// ---------�����������������(�����)��3����ͨͼ
void DFSTraverse(ALGraph G)
{

}
//-----------����������ں���----------
int main()
{
    showinfo();

    int input;
    cin >> input;
    switch(input)
    {
        case 1:
            {
                AMGraph G;
                int s = CreateUDN(G);
                if(s == OK) cout << "����ͼ�ɹ���";
                else cout << "����ͼʧ�ܣ�";
            }break;
    }

    return 0;
}






















