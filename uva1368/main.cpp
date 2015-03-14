#include <iostream>

using namespace std;

int main()
{
    int time;
    cin>>time;
    while(time)
    {
    int n,m;
    cin>>n>>m;
    int dna[n][m];
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        for(int j=0;j<m;j++)
            dna[i][j]=t[j];
    }
    string answer;
    for(int j=0;j<m;j++)
    {
        int counta=0,countc=0,countg=0,countt=0;
        for(int i=0;i<n;i++)
        {
            if(dna[i][j]=='A')
                counta++;
            if(dna[i][j]=='C')
                countc++;
            if(dna[i][j]=='G')
                countg++;
            if(dna[i][j]=='T')
                countt++;
        }
        char ans='A';
        if((countc>counta)&&(countc>=countg)&&(countc>=countt))
            ans='C';
        if((countg>counta)&&(countg>countc)&&(countg>=countt))
            ans='G';
        if((countt>counta)&&(countt>countc)&&(countt>countg))
            ans='T';
        answer+=ans;
    }
    cout<<answer<<endl;
    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(dna[i][j]!=answer[j])
                k++;
    cout<<k<<endl;
    time--;
    }
    return 0;
}

