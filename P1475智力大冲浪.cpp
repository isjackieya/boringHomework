# include<iostream>
# include<algorithm>
using namespace std;
typedef struct Game
{
    int ti;
    int wi;
}Game;
bool time_played[10001];
Game game[10001];

bool comp_wi(Game a,Game b)
{
    if(a.wi>b.wi)
    return true;
    else return false;

}

int main()
{
    int m,n,i,j;
 
    while(cin>>m>>n)
    {
        for(i=1;i<=n;i++)
        {
            time_played[i]=false;
        }
        for(i=1;i<=n;i++)
        cin>>game[i].ti;
        for(i=1;i<=n;i++)
        cin>>game[i].wi;
        sort(game+1,game+n+1,comp_wi);
        for(i=1;i<=n;i++)
        {
            j=game[i].ti;
            while (time_played[j]==true&&j>0)
            j--;
            if(j==0)  //无法在规定时间段完成，就从后往前找安排一个时间段给它。
            {
                m=m-game[i].wi;
                j=n;
                while(time_played[j]==true)
                j--;
                time_played[j]=true;
            }
            else 
            time_played[j]=true;  
        }
        cout<<m<<endl;
    }
    return 0;
}