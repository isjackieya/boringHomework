# include<iostream>
using namespace std;
int a[1000]={0};
int main()
{
    int n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int max=0,sum=0;
    for(i=0;i<n;i++)
    for(j=i;j<n;j++)
    {
        for(k=i;k<=j;k++)
            sum+=a[k];
        if(sum>max)
        max=sum;
        sum=0;
    }
    cout<<max<<endl;
    return 0;
}