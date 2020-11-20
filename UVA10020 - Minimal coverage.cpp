#include<bits/stdc++.h>

using namespace std;


bool check(vector<pair<int,int> > ans, int m) {
    if(ans.size() == 0)return 0;
    if(ans[0].first > 0 || ans.back().second < m)return 0;
    for(int i=0;i<ans.size()-1;i++) {
        if(ans[i].second < ans[i+1].first)return 0;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int a,b,m;
        vector<pair<int,int> >vp,ans;

        cin>>m;
        while(cin>>a>>b && (a || b)) {
            if(a > b)swap(a,b);
            vp.push_back({a,b});
        }
        sort(vp.begin(),vp.end());

        pair<int,int>df,cr;
        df = vp[0];
        int edge = 0;
        for(int i=1;i<vp.size() && (ans.empty() || ans.back().second < m);i++) {
            cr = vp[i];
            if(df.second < cr.second) {
                if(ans.size() == 0) {
                    if(0 < cr.first)ans.push_back(df);
                }
                else {
                    if(ans.back().second < cr.first)ans.push_back(df);
                }

                df = cr;
            }
            if(vp.size() - 1 == i &&(ans.size() == 0 || ans.back().second < m))ans.push_back(df);
        }
        if(vp.size() == 1)ans.push_back(vp[0]);
        bool answer = check(ans,m);
        if(answer) {
            cout<<ans.size()<<endl;
            for(auto u : ans)cout<<u.first<<" "<<u.second<<endl;
        }
        else {
            cout<<0<<endl;
        }
        if(t)cout<<endl;
    }
    return 0;
}
