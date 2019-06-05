/*
* 图的操作
* 2019年5月23日10:35:05
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
    cout << "1710121183-崔少峰\n";
    cout << "1--使用邻接矩阵建立图！\n";
    cout << "2--使用邻接表建立图！\n";
    cout << "3--深度优先遍历图！\n";
    cout << "4--广度优先便利图！\n";
    cout << "5--Dijkstra求最短路径！\n";
    cout << "0--清空视图！\n";
    cout << "-1-退出该程序！\n";
    cout << "---------请输入操作码：";
}

//--------图的邻接矩阵表示形式------------
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


//----------图的邻接表的存储结构-------

#define MVNum 100
typedef struct ArcNode              //变节点
{
    int adjvex;                     //该边所指向的顶点位置
    struct ArcNode * nextarc;       //指向下一条边的指针
    OtherInfo info;                 //和边相关的信息
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


//-------深度优先遍历连通图------------
bool visited[MVNum];             //访问标志数组，其处值为“false”
void DFS(Graph G,int v)
{//从第v个顶点出发递归地深度优先遍历图G
    cout << v;
    visited[v]=true;            //访问第v个顶点，并置访问标志数组相应的分量为true
    for(int w=FirstAdjVex(G,v);w>0;w=NextAdjVex(G,v,w))
    {//依次检查v的所有的顶点w，FirstAdjVex(G,v)表示V的第一个邻接点
        //NextAdjVex(G,v,w)表示v相对w的下一个邻接点，w>=0比爱你是存在邻接点
        if(!visited[w]) DFS(G,w);      //对v的尚未访问的邻接顶点w递归

    }
}

// ---------深度优先搜索遍历︿(￣︶￣)︿3非连通图
void DFSTraverse(Graph G)
{

}
//-----------主函数，入口函数----------
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
                if(s == OK) cout << "创建图成功！";
                else cout << "创建图失败！";
            }break;
    }

    return 0;
}






















