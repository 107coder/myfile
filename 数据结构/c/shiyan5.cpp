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
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

Status LocateVex(AMGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vexs[i] == v) return i;
    }
    return FAIL;
}
Status CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for(int i=0; i<G.vexnum; ++i)
    {
        cin >> G.vexnum;
    }
    for(int i=0; i<G.vexnum; ++i)
    {
        for(int j=0; j<G.vexnum; ++j)
        {
            G.arcs[i][j] = MaxInt;
        }
    }

    for(int k=0; k<G.arcnum; ++k)
    {
        int v1,v2,w,i,j;
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
typedef struct ArcNode              //��ڵ�
{
    int adjvex;                     //�ñ���ָ��Ķ���λ��
    struct ArcNode * nextarc;       //ָ����һ���ߵ�ָ��
    OtherInfo info;                 //�ͱ���ص���Ϣ
}ArcNode;
typedef struct VNode
{
    VerTexType data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

Status LocateVex(ALGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vertices[i].data == v) return i;
    }
    return FAIL;
}

Status CreateUDG(ALGraph &G)
{

    cin >> G.vexnum >> G.arcnum;
    for(int i=0;i<G.vexnum; ++i)
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
void DFS(Graph G,int v)
{//�ӵ�v����������ݹ��������ȱ���ͼG
    cout << v;
    visited[v]=true;            //���ʵ�v�����㣬���÷��ʱ�־������Ӧ�ķ���Ϊtrue
    for(int w=FirstAdjVex(G,v);w>0;w=NextAdjVex(G,v,w))
    {//���μ��v�����еĶ���w��FirstAdjVex(G,v)��ʾV�ĵ�һ���ڽӵ�
        //NextAdjVex(G,v,w)��ʾv���w����һ���ڽӵ㣬w>=0�Ȱ����Ǵ����ڽӵ�
        if(!visited[w]) DFS(G,w);      //��v����δ���ʵ��ڽӶ���w�ݹ�

    }
}

// ---------�����������������(�����)��3����ͨͼ
void DFSTraverse(Graph G)
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






















