//Problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382
#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>ans,v;
void comb(int i) {
    if(ans.size() == 6) {
        cout<<ans[0];
        for(int j=1;j<6;j++)cout<<" "<<ans[j];
        cout<<endl;
        return;
    }
    for(int j=i;j<v.size();j++) {
        ans.push_back(v[j]);
        comb(j+1);
        ans.pop_back();
    }
}

int main()
{
    int a;
    bool f = false;
    while(cin>>n && n) {
        if(f)cout<<endl;
        f=true;
        v.clear();
        for(int i=0;i<n;i++) {
            cin>>a;
            v.push_back(a);
        }
        comb(0);
    }
    return 0;
}
