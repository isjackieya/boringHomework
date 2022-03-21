# include<iostream>
# include<math.h>
using namespace std;
char a[3000][3000];
void f(int n,int x,int y)
{
	int r;
	if(n==1)
	{
		a[x][y]='X';
		return ;
	}
	r=pow(3.0,n-2);
	f(n-1,x,y);                         // 左上 
	f(n-1,x,y+2*r);                    //右上 
	f(n-1,x+r,y+r);                   //中间 
	f(n-1,x+2*r,y);                  //左下 
	f(n-1,x+2*r,y+2*r);             //右下 
}

int main()
{
	int n,i,j;
	while(cin>>n)
	{
		if(n<=0)
		break;
		int s=pow(3.0,n-1);
		for(i=0;i<=s;i++)
		for(j=0;j<=s;j++)
		a[i][j]=' ';
		f(n,1,1);
		for(i=1;i<=s;i++)
		{
		for(j=1;j<=s;j++)
			cout<<a[i][j];
			cout<<endl;
	    }
	    cout<<"-"<<endl;
	}
	return 0;
}
