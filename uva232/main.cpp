#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n,m,count=1;
    cin>>n;
    while(n)
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
          }
        }
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
         {
            if(((i==0)||(j==0)||(puzzle[i][j-1]=='*')||(puzzle[i-1][j]=='*'))&&(puzzle[i][j]!='*'))
            {num.push_back(puzzle[i][j]);low.push_back(i);col.push_back(j);}
         }
       }
       cout<<"puzzle #"<<count<<":"<<endl;
       cout<<"Across"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int break1=0;
               for(int k=0;k<(int)num.size();k++)
               {
                   if(break1==1)
                       break;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   if(k+1>9)
                       cout<<' ';
                   else
                       cout<<"  ";
                   cout<<k+1<<'.';
                   cout<<puzzle[i][j];
                   for(int x=j+1;x<=m;x++)
                   {
                       if((x!=m)&&(puzzle[i][x]!='*'))
                       {
                           cout<<puzzle[i][x];
                       }
                       else
                       {
                           cout<<endl;
                           j+=(x-j);
                           break1=1;
                           break;
                       }
                   }
               }
              }
           }
       }
       cout<<"Down"<<endl;
       vector<char> pass;
       vector<int> passrow,passcol;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               int break2=0;
               for(int k=0;k<(int)num.size();k++)
               {
                   for(int p=0;p<(int)pass.size();p++)
                   {
                       if((puzzle[i][j]==pass[p])&&(i==passrow[p])&&(j==passcol[p]))
                       {break2=1;break;};
                   }
                       if(break2==1)
                           break;
               if((puzzle[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   if(k+1>9)
                       cout<<' ';
                   else
                       cout<<"  ";
                   cout<<k+1<<'.';
                   cout<<puzzle[i][j];
                   for(int x=i+1;x<=n;x++)
                   {
                       if((x!=n)&&(puzzle[x][j]!='*'))
                       {
                           cout<<puzzle[x][j];
                           pass.push_back(puzzle[x][j]);
                           passrow.push_back(x);
                           passcol.push_back(j);
                       }
                       else
                       {
                           cout<<endl;
                           break2=1;
                           break;
                       }
                   }
               }
               }
           }
       }
       cin>>n;
       count++;
       if(n!=0)
           cout<<endl;
    }
    return 0;
}

