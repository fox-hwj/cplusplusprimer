#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    if(n)
    {
        cin>>m;
        char puzzle[n][m];
        string s;
        vector<char> num;
        vector<int> low,col;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                puzzle[i][j]=s[j];
            };
        };
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(((i==0)||(j==0)||(puzzle[i][j-1]='*')||(puzzle[i-1][j]='&'))&&(puzzle[i][j]!='*'))
            {num.push_back(puzzle[i][j]);low.push_back(i);col.push_back(j);}
        }
       }
       int count=1;
       cout<<"puzzle #"<<count<<":"<<endl;
       cout<<"Across"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int break1=0;
               for(int k=0;k<=(int)num.size();k++)
               {
                   if(break1==1)
                       break;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   cout<<"  "<<k+1<<'.';
                   cout<<puzzle[i][j];
                   for(int x=j+1;x<m;x++)
                   {
                       if((puzzle[i][x]==num[k+x-j])&&(i==low[k+x-j])&&(x==col[k+x-j]))
                       {
                           cout<<puzzle[i][x];
                       }
                       else
                       {
                           cout<<endl;
                           j+=(x-j+1);
                           break1=1;
                           break;
                       }
                   }
                   k++;
               }
               }
           }
       }
       cout<<endl;
       cout<<"Down"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int break2=0;
               for(int k=0;k<=(int)num.size();k++)
               {
                   if(break2==1)
                       break;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   cout<<"  "<<k+1<<'.';
                   cout<<puzzle[i][j];
                   for(int x=i+1;x<n;x++)
                   {
                       if((puzzle[x][j]==num[k+x-i])&&(x==low[k+x-i])&&(j==col[k+x-i]))
                       {
                           cout<<puzzle[x][j];
                       }
                       else
                       {
                           cout<<endl;
                           i+=(x-i+1);
                           break2=1;
                           break;
                       }
                   }
                   k++;
               }
               }
           }
       }
    }
    return 0;
}

