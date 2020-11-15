problem: https://www.spoj.com/problems/KNAPSACK/
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > vp;
int dp[2005][2005];
int s, n;
int knapSack(int i, int items) {
    if(i >= n)return 0;

    if(dp[i][items] != -1)return dp[i][items];
    if(items + vp[i].first > s) return dp[i][items] = knapSack(i+1, items);

    return dp[i][items] = max(vp[i].second + knapSack(i+1,items + vp[i].first), knapSack(i+1, items));

}
int main()
{
    cin>>s>>n;
    int a,b;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        vp.push_back({a,b});
    }
    memset(dp,-1,sizeof dp);
    cout<<knapSack(0, 0);
    return 0;
}
