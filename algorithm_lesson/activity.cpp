#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
 
struct node
{
    int begin;
    int end;
}Num[100009];
bool cmp1(node a, node b)
{
    return a.end < b.end ;      //结束时间从小到大排序
}
int main()
{
    int n;
    int k=1;
    int count=1;
    srand(time(0));
    printf("输入规模：");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {   
        Num[i].begin = rand()%20;
        Num[i].end = rand()%10+Num[i].begin;
        //scanf("%d %d", &Num[i].begin , &Num[i].end );       
    }
     for(int i=1; i<=n; i++){   
        printf("%d %d  ", Num[i].begin , Num[i].end );       
    }
    sort(Num+1, Num+n+1, cmp1);
    for(int i=2; i<=n; i++)
    {
        if(Num[i].begin >= Num[1].end)
        {
            Num[1].end = Num[i].end ; 
            count++;            
        }       
    }
    cout << endl;
    printf("最多能安排多少个活动:%d\n",count);
    return 0;
}