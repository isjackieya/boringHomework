# include<iostream>
# include<algorithm>
# include<iomanip>
using namespace std;
typedef struct Coins
{
    double m;
    double v;
    double cost_performance;//金币
}Coins;
Coins c[1001];
bool cmp_v(Coins a,Coins b)
{
    if(a.cost_performance>b.cost_performance)
    return true;
    else return false;
}
int main()
{
    int n,t,i;
    double harvest=0;
    cin>>n>>t;
    for(i=1;i<=n;i++)
    {
        cin>>c[i].m>>c[i].v;
        c[i].cost_performance=c[i].v/c[i].m;
    }
    sort(c+1,c+1+n,cmp_v);
    for(i=1;i<=n;i++)
    {
        if(c[i].m<=t)
        {
            harvest+=c[i].v;
            t=t-c[i].m;
        }
        else
        {
            harvest+=c[i].cost_performance*t;
            break;
        }
    } 
    cout<<fixed<<setprecision(2)<<harvest<<endl;
    return 0;
}