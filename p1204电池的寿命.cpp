# include<iostream>
# include<iomanip>
using namespace std;
int a[1001];
int main()
{
    int n,i,sum,max;
    double result;
    while(cin>>n)
    {
        sum=0;
        max=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(max<a[i])
            max=a[i];
        }
        if(sum-max<max)
        result=(sum-max)*1.0;
        else 
        result=((sum-max-max)*1.0/2+max)*1.0;
        cout<<fixed<<setprecision(1)<<result<<endl;
    }
    return 0;
}