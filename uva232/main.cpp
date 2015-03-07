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
        char puzzle[n-1][m-1];
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
            if((i==0)||(j==0)||(puzzle[i][j-1]='*')||(puzzle[i-1][j]))
            {num.push_back(puzzle[i][j]);low.push_back(i);col.push_back(j);}
        }
       }
       int countlow=1,count=1;
       cout<<"puzzle #"<<count<<":"<<endl;
       cout<<"Across"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int k=0;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   cout<<"  "<<k<<'.';
                   int low1=1;
                   for(int x=j+low1;x<m;x++)
                   {
                       if((puzzle[i][x]==num[x])&&(i==low[x])&&(x==col[x]))
                       {
                           cout<<puzzle[i][x];
                       }
                       else
                       {
                           break;
                           cout<<endl;
                       }
                   }
               }
           }
       };
       cout<<"Down"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int k=0;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   cout<<"  "<<k<<'.';
                   int col1=1;
                   for(int x=i+col1;x<n;x++)
                   {
                       if((puzzle[x][j]==num[x])&&(x==low[x])&&(j==col[x]))
                       {
                           cout<<puzzle[x][j];
                       }
                       else
                       {
                           break;
                           cout<<endl;
                       }
                   }
               }
           }
       }
    }
    return 0;
}

