# include<iostream>
# include<algorithm>
using namespace std;

int h[1000][1000]={0};  //记录每点的高度
int maxlen[1000][1000]={0}; //记录每点的最长长度
int DP(int i,int j,int row,int col)  
{
    int max=0;
    if(j-1>=0&&h[i][j]>h[i][j-1]&&max<DP(i,j-1,row,col))
    max=DP(i,j-1,row,col);
    if(j+1<=col&&h[i][j]>h[i][j+1]&&max<DP(i,j+1,row,col))
    max=DP(i,j+1,row,col);
    if(i-1>=0&&h[i][j]>h[i-1][j]&&max<DP(i-1,j,row,col))
    max=DP(i-1,j,row,col);
    if(i+1<=row&&h[i][j]>h[i+1][j]&&max<DP(i+1,j,row,col))
    max=DP(i+1,j,row,col);
    return maxlen[i][j]=max+1;
}

int main()
{
    int r,c,i,j,max=0;
    cin>>r>>c;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    cin>>h[i][j];

    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        DP(i,j,r,c);
        if(max<maxlen[i][j])
        max=maxlen[i][j];

    }
    cout<<max<<endl;
    return 0;
}
