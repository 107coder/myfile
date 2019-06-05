
/*
* 哈夫曼树的操作
* 时间2019年5月9日10:31:02
*/
#include <iostream>
#include <windows.h>
//#include <sstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MaxInt 32767

typedef char TElemType;
typedef int Status;
int weight[27] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168};
char character[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
typedef struct                        //哈夫曼树存储表示     一个结点
{
    char value;
    int weight;                       //结点的权值
    int parent,lchild,rchild;         //结点的双亲、左孩子、右孩子的下标
} HTNode,*HuffmanTree;                //动态分配数组存储哈夫曼树

void showMassage()
{
    cout << "***************************************************************************\n";
    cout << "********** 1.输入HuffmanTree的参数.                              **********\n";
    cout << "**********  .初始化HuffmanTree的参数.(含有26个字母和空格)        **********\n";
    cout << "********** 2.创建HuffmanTree和编码表.                            **********\n";
    cout << "********** 3.输出编码表.                                         **********\n";
    cout << "********** 4.输出编码，并编译成字符.                             **********\n";
    cout << "********** 5.输出字符，并实现转码.                               **********\n";
    cout << "********** 6.退出.                                               **********\n";
    cout << "***************************************************************************\n";
}
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
    int a1=MaxInt;
    int a2=MaxInt;
    for(int i=0;i<=n;i++)
    {
        if(HT[i].parent==0)
        {
            if(HT[i].weight<a1)
            {
                s2=s1;
                s1=i;
                a2=a1;
                a1=HT[i].weight;
            }
            else if(HT[i].weight<a2)
            {
                s2=i;
                a2=HT[i].weight;
            }
        }
    }
}
void Select1(HuffmanTree HT,int i,int &s1,int &s2)
{
    int tmp=MaxInt;
    //求s1
    for(int k=1; k<i+1; k++)
    {
        if(HT[k].weight<tmp)
        {
            tmp = HT[k].weight;
            if( HT[k].parent == 0)
            {
                s1 = k;
            }
        }
    }
    //求s2
    tmp=MaxInt;
    for(int k=1; k<i+1; k++)
    {
        if(k==s1)continue;
        if(HT[k].weight<tmp)
        {
            tmp = HT[k].weight;
            if( HT[k].parent == 0)
            {
                s2 = k;
            }
        }
    }
}
void CreateHuffmanTree(HuffmanTree &HT, int n)   //创建哈夫曼树
{
    if(n<=1)
        return;
    int m = 2*n-1;
    HT = new HTNode[m+1];              //0号单元未使用。所以需要动态分配m+1个单元，HT[m]表示根节点
    for(int i=1; i<=m; i++)            //将1~m号单元中的双亲、左孩子、右孩子的下标都初始化为0
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1; i<n+1; ++i)             //输入前n个单元中叶子叶子结点的权值
    {
//        cout << "请输入第"<<i<<"个结点的字符 权值（以空格隔开）：";
//        cin >> HT[i].value;
//        cin >> HT[i].weight;
          HT[i].weight = weight[i-1];
    }
    //------------------上面是哈夫曼树的初始化工作----------------
    int s1,s2;
    for(int i=n+1; i<=m; ++i)
    {
        //通过n-1次的选择、删除、合并来创建哈夫曼树
        Select(HT,i-1,s1,s2);
        //在HT[k](1<=k<=i-1)中选择两个其双亲域为0且权值最小的节点，并返回他们在HT中的序号s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //得到新结点i，从森林中删除s1，s2，将s1和s2的双亲域由0变为i
        HT[i].lchild = s1;                              //s1，s2分别作为i的左右孩子
        HT[i].rchild = s2;                              //i的权值为左右孩子权值之和
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

typedef char **HuffmanCode;                    //哈夫曼编码表的存储形式，动态分配数组存储哈夫曼编码表

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
    HC = new char*[n+1];               //分配存储n个字符编码的编码表空间
    char cd[n];                        //分配临时存放个字符编码的动态数组空间
    cd[n-1] = '\0';                    //编码结束符
    for(int i=1; i<=n; ++i)            //逐个字符求哈法曼编码
    {
        int start = n-1;               //start开始是指向最后，即编码结束符位置
        int c=i;
        int f=HT[i].parent;            //f指向结点c的双亲结点
        while(f!=0)                    //从叶子节点开始向上回溯，知道根节点
        {
            --start;                   //回溯一次start向前指一个位置
            if(HT[f].lchild==c)        //结点c是f的左孩子，则生成代码0
            {
                cd[start] = '0';
            }
            else                        //结点c是f的右孩子，则生成代码1
            {
                cd[start] = '1';
            }
            c=f;
            f=HT[f].parent;             //继续向上回溯
        }                               //求出第i个字符的编码
        HC[i]=new char[n-start];        //为第i个字符编码分配空间
        strcpy(HC[i],&cd[start]);       //将求得的编码从临时空间cd复制到HC的当前行中
    }                                   //for
    delete cd;                          //释放临时空间
}


void CodeToChar(HuffmanCode HC,string code)
{
    string result="输出：";
    string tmp;
    for(int i=0;i<code.length();i++)
    {
        tmp += code[i];
        for(int k=0;k<27;k++){
            if(tmp == HC[k+1])
            {
                result += character[k];
                tmp = "";
            }
        }
    }
    cout << result<< endl;
}

void CharToCode(HuffmanCode HC,string char1)
{
    string result = "输出：";
    for(int i=0;i<char1.length();i++)
    {
        for(int k=0;k<27;k++)
        {
            if(character[k] == char1[i])
            {
                result += HC[k+1];
            }
        }
    }
    cout << result<<endl;
}
int main()
{
    SetConsoleTitle("1710121183-崔少峰-数据结构-实验哈夫曼编码");
    showMassage();
    int select;
again:
    cout << "请输入选择：";
    cin >> select;
    HuffmanTree H;
    HuffmanCode HC;
    int n=27;
    switch(select)
    {
        case 1:
        {
//            cout << "输入哈夫曼树结点的个数：";
//            cin >> n;
            n=27;
            CreateHuffmanTree(H,n);
            cout << "初始化成功！\n";
            goto again;
        }
        break;
        case 2:
            {
                CreateHuffmanCode(H,HC,n);
                cout << "创建成功\n";
                goto again;
            }break;
        case 3:
            {
                for(int k=0;k<n;k++)
                {
                    cout << character[k]<< "->"<< HC[k+1]<<endl;
                }
                goto again;
            }break;
        case 4:
            {
                string char1;
                cout << "输入：";
                cin.ignore(1024,'\n');
                getline(cin,char1,'\n');
                CharToCode(HC,char1);

                goto again;
            }
        case 5:
            {
                cout << "输入：";
                string char2="";
                cin.ignore(1024,'\n');
                getline(cin,char2,'\n');
                CodeToChar(HC,char2);
                goto again;
            }break;
        case 6:
            {
                return 0;
            }
        default:
            {
                cout << "error"<<endl;goto again;
            }
    }
    return 0;
}
