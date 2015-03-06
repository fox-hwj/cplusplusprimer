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
        char k[n-1][m-1];
        string s;
        vector<char> num;
        vector<int> low,col;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
            {
                k[i][j]=s[j];
            };
        };
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if((i==0)||(j==0)||(k[i][j-1]='*')||(k[i-1][j]))
            {num.push_back(k[i][j]);low.push_back(i);col.push_back(j);}
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
               if((k[i][j]==num[k])&&(i==low[k])&&(j==col[k]))
               {
                   cout<<"  "<<k<<'.';

               }
           }
       }
    return 0;
}

