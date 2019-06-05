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

//显示提示信息
void showMsg(string msg)
{
    cout << msg;
}

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
//定于 邻接矩阵的一个总的结构
typedef struct
{
    VerTexType vexs[MVNum];       //顶点表
    ArcType arcs[MVNum][MVNum];    //顶点矩阵
    int vexnum,arcnum;              //图的当前点数和边数
}AMGraph;

//定位某元素的位置，返回该位置的索引，若是没有找到，就直接返回FAIL（-2）
Status LocateVex(AMGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vexs[i] == v) return i;
    }
    return FAIL;
}
//传入上面定义的图的邻接矩阵，并进行初始化和赋值
Status CreateUDN(AMGraph &G)
{
    cout << "请输入邻接矩阵的顶点数 总边数（用空格隔开）：";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入邻接矩阵的"<<G.vexnum<<"个顶点的信息（"<<G.vexnum<<"个数，用空格隔开）：";
    for(int i=0; i<G.vexnum; ++i)
    {
        cout << "--"<<i;
        cin >> G.vexs[i];
    }
    //初始化邻接矩阵，把所有的值都置位无穷大
    for(int i=0; i<G.vexnum; ++i)
    {
        for(int j=0; j<G.vexnum; ++j)
        {
            G.arcs[i][j] = MaxInt;
        }
    }

    for(int k=0; k<G.arcnum; ++k)  //构造邻接矩阵
    {
        int v1,v2,w,i,j;
        cout << "输入第"<<k+1<<"条边依附的顶点和权值：";
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
typedef struct ArcNode              //边节点
{
    int adjvex;                     //该边所指向的顶点位置
    struct ArcNode * nextarc;       //指向下一条边的指针
    OtherInfo info;                 //和边相关的信息
}ArcNode;
typedef struct VNode                //顶点信息
{
    VerTexType data;
    ArcNode *firstarc;              //指向第一条依附顶点的指针
}VNode,AdjList[MVNum];              //AdjList表示邻接表类型
typedef struct                      //邻接表
{
    AdjList vertices;
    int vexnum,arcnum;              //图当前的顶点和边数
}ALGraph;
//定位表中元素的位置，返回索引值
Status LocateVex(ALGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
    {
        if(G.vertices[i].data == v) return i;
    }
    return FAIL;
}
//使用邻接表创建图
Status CreateUDG(ALGraph &G)
{//采用邻接表表示话，创建无向图G
    cout << "请输入邻接矩阵的顶点数 总边数（用空格隔开）：";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入邻接矩阵的"<<G.vexnum<<"个顶点的信息（"<<G.vexnum<<"个数，用空格隔开）：";
    for(int i=0;i<G.vexnum; ++i)        //输入各点，构造结点表头
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
int FirstAdjVex(ALGraph G,int v)
{

}
int NextAdjVex(ALGraph G,int v,int w)
{

}
void DFS(ALGraph G,int v)
{ //从第v个顶点出发递归地深度优先遍历图G
    cout << v;
    visited[v]=true;            //访问第v个顶点，并置访问标志数组相应的分量为true
    for(int w=FirstAdjVex(G,v);w>0;w=NextAdjVex(G,v,w))
    {//依次检查v的所有的顶点w，FirstAdjVex(G,v)表示V的第一个邻接点
        //NextAdjVex(G,v,w)表示v相对w的下一个邻接点，w>=0比爱你是存在邻接点
        if(!visited[w]) DFS(G,w);      //对v的尚未访问的邻接顶点w递归

    }
}

// ---------深度优先搜索遍历︿(￣︶￣)︿3非连通图
void DFSTraverse(ALGraph G)
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






















