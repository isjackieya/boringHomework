#include<iostream>
using namespace std;
char maze[10][10];

void print_solve()
{
    int i,j;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        cout<<maze[i][j];
        cout<<endl;
    }
}
void find_path(int i,int j) //以当前位置为起点，查看能否走到终点
{
    int dir,xi,yj;
    if(i==8&&j==8&&maze[i][j]=='O')
    {
        maze[i][j] =' ';
        print_solve();
        maze[i][j] = 'X';
        return;
    }
    else
    for(dir=0;dir<4;dir++)
    {
        switch(dir)
        {
            case 0:
            xi=i;yj=j-1;break;
            case 1:
            xi=i;yj=j+1;break;
            case 2:
            xi=i-1;yj=j;break;
            case 3:
            xi=i+1;yj=j;break;
        }
        if(maze[i][j]=='O')
        {
            maze[i][j]=' ';
            find_path(xi,yj);
            maze[i][j]='O';
        }
    }
}

int main()
{
    int i,j;
    for(i=1;i<=8;i++)
    for(j=1;j<=8;j++)
    cin>>maze[i][j];
    for(i=0;i<=9;i++)  
    {
        maze[i][0] = 'X';
        maze[0][i] = 'X';
        maze[9][i] = 'X';
        maze[i][9] = 'X';
    }

    find_path(1,1);
    return 0;
}