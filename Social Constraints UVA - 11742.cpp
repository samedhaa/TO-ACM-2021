//problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
#include<bits/stdc++.h>

using namespace std;

vector<int>v;
vector<pair<int,pair<int,int> > >vp;
bool vis[10];
int n,m,ans;

bool check(vector<int>v) {
    map<int,int>mp;
    for(int i=0;i<v.size();i++) {
        mp[v[i]] = i;
    }
    for(auto u : vp) {
        int a = u.first;
        int b = u.second.first;
        int c = u.second.second;

        if(c < 0) {
            if(abs(mp[a] - mp[b]) < abs(c)) {
                return false;
            }
        }
        else {
            if(abs(mp[a] - mp[b]) > abs(c)) {
                return false;
            }
        }
    }
    return true;
}
void permut() {
    if(v.size() == n) {
        if(check(v)) {
            ans++;
        }
        return;
    }
    for(int i=0;i<n;i++) {
        if(vis[i])continue;
        v.push_back(i);
        vis[i] = 1;
        permut();
        v.pop_back();
        vis[i] = 0;
    }
}
int main()
{
    while(cin>>n && cin>>m && (n || m)) {
        int a,b,c;
        while(m--) {
        cin>>a>>b>>c;
        vp.push_back({a,{b,c}});
        }
        permut();
        cout<<ans<<endl;
        ans=0;
        vp.clear();
    }
    return 0;
}
