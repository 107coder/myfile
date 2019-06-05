
/*
* ���������Ĳ���
* ʱ��2019��5��9��10:31:02
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
typedef struct                        //���������洢��ʾ     һ�����
{
    char value;
    int weight;                       //����Ȩֵ
    int parent,lchild,rchild;         //����˫�ס����ӡ��Һ��ӵ��±�
} HTNode,*HuffmanTree;                //��̬��������洢��������

void showMassage()
{
    cout << "***************************************************************************\n";
    cout << "********** 1.����HuffmanTree�Ĳ���.                              **********\n";
    cout << "**********  .��ʼ��HuffmanTree�Ĳ���.(����26����ĸ�Ϳո�)        **********\n";
    cout << "********** 2.����HuffmanTree�ͱ����.                            **********\n";
    cout << "********** 3.��������.                                         **********\n";
    cout << "********** 4.������룬��������ַ�.                             **********\n";
    cout << "********** 5.����ַ�����ʵ��ת��.                               **********\n";
    cout << "********** 6.�˳�.                                               **********\n";
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
    //��s1
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
    //��s2
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
void CreateHuffmanTree(HuffmanTree &HT, int n)   //������������
{
    if(n<=1)
        return;
    int m = 2*n-1;
    HT = new HTNode[m+1];              //0�ŵ�Ԫδʹ�á�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ���ڵ�
    for(int i=1; i<=m; i++)            //��1~m�ŵ�Ԫ�е�˫�ס����ӡ��Һ��ӵ��±궼��ʼ��Ϊ0
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1; i<n+1; ++i)             //����ǰn����Ԫ��Ҷ��Ҷ�ӽ���Ȩֵ
    {
//        cout << "�������"<<i<<"�������ַ� Ȩֵ���Կո��������";
//        cin >> HT[i].value;
//        cin >> HT[i].weight;
          HT[i].weight = weight[i-1];
    }
    //------------------�����ǹ��������ĳ�ʼ������----------------
    int s1,s2;
    for(int i=n+1; i<=m; ++i)
    {
        //ͨ��n-1�ε�ѡ��ɾ�����ϲ���������������
        Select(HT,i-1,s1,s2);
        //��HT[k](1<=k<=i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľڵ㣬������������HT�е����s1��s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
        HT[i].lchild = s1;                              //s1��s2�ֱ���Ϊi�����Һ���
        HT[i].rchild = s2;                              //i��ȨֵΪ���Һ���Ȩֵ֮��
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

typedef char **HuffmanCode;                    //�����������Ĵ洢��ʽ����̬��������洢�����������

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
    HC = new char*[n+1];               //����洢n���ַ�����ı����ռ�
    char cd[n];                        //������ʱ��Ÿ��ַ�����Ķ�̬����ռ�
    cd[n-1] = '\0';                    //���������
    for(int i=1; i<=n; ++i)            //����ַ������������
    {
        int start = n-1;               //start��ʼ��ָ����󣬼����������λ��
        int c=i;
        int f=HT[i].parent;            //fָ����c��˫�׽��
        while(f!=0)                    //��Ҷ�ӽڵ㿪ʼ���ϻ��ݣ�֪�����ڵ�
        {
            --start;                   //����һ��start��ǰָһ��λ��
            if(HT[f].lchild==c)        //���c��f�����ӣ������ɴ���0
            {
                cd[start] = '0';
            }
            else                        //���c��f���Һ��ӣ������ɴ���1
            {
                cd[start] = '1';
            }
            c=f;
            f=HT[f].parent;             //�������ϻ���
        }                               //�����i���ַ��ı���
        HC[i]=new char[n-start];        //Ϊ��i���ַ��������ռ�
        strcpy(HC[i],&cd[start]);       //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
    }                                   //for
    delete cd;                          //�ͷ���ʱ�ռ�
}


void CodeToChar(HuffmanCode HC,string code)
{
    string result="�����";
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
    string result = "�����";
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
    SetConsoleTitle("1710121183-���ٷ�-���ݽṹ-ʵ�����������");
    showMassage();
    int select;
again:
    cout << "������ѡ��";
    cin >> select;
    HuffmanTree H;
    HuffmanCode HC;
    int n=27;
    switch(select)
    {
        case 1:
        {
//            cout << "��������������ĸ�����";
//            cin >> n;
            n=27;
            CreateHuffmanTree(H,n);
            cout << "��ʼ���ɹ���\n";
            goto again;
        }
        break;
        case 2:
            {
                CreateHuffmanCode(H,HC,n);
                cout << "�����ɹ�\n";
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
                cout << "���룺";
                cin.ignore(1024,'\n');
                getline(cin,char1,'\n');
                CharToCode(HC,char1);

                goto again;
            }
        case 5:
            {
                cout << "���룺";
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
