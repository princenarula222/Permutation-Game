#include <bits/stdc++.h>
using namespace std;

int dp(int i, int s, vector<vector<int>> &res, vector<int> &pos, vector<int> &a, int n)
{
    if(res[i][s]!=-1)
     return res[i][s];
    int j,k;
    j=1;
    while(pos[i]-j*i>=1)
    {
        k=pos[i]-j*i;
        if(a[k]>i)
        {
            if(dp(a[k],(s+1)%2,res,pos,a,n)==s)
            {
                res[i][s]=s;
                break;
            }
        }
        j++;
    }
    if(res[i][s]==-1)
    {
            j=1;
    while(pos[i]+j*i<=n)
    {
        k=pos[i]+j*i;
        if(a[k]>i)
        {
            if(dp(a[k],(s+1)%2,res,pos,a,n)==s)
            {
                res[i][s]=s;
                break;
            }
        }
        j++;
    }
    }
    if(res[i][s]==-1)
     res[i][s]=(s+1)%2;
    return res[i][s];
}

int main() {
    int n;
     cin>>n;
    vector<int> a(n+1,0);
    vector<int> pos(n+1,0);
    for(int i=1; i<=n; i++)
    {
     cin>>a[i];
     pos[a[i]]=i;
    }
    vector<vector<int>> res(n+1,vector<int> (2,-1));
    res[n][0]=1;
    res[n][1]=0;
    for(int i=n-1; i>=1; i--)
     dp(i,0,res,pos,a,n);
    for(int i=1; i<=n; i++)
    {
        if(res[a[i]][0]==0)
         cout<<"A";
        else
         cout<<"B";
    }
	return 0;
}