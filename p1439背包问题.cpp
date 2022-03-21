#include<iostream>
#include <algorithm>
using namespace std;
int max(int x,int y)
{
	return (x>y?x:y);
}
int main()
{ 
	int v,n,i,j,dp[31][2000]={0};
	int value[100]={0};
	int volume[100]={0};
	while(cin>>v)
	{
		dp[31][2000]={0};
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>volume[i]>>value[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= v; j++) {
				if (j < volume[i])	
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - volume[i]] + value[i]);
			}
		}
		cout<<dp[n][v]<<endl;
	}
	return 0;
}
