#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)cin>>a[i];

        long long sum = 1;
        int ans=1;
        for(int i=1;i<n-1;i++) {
            if(sum + a[i] < a[i+1]) {
                sum+=a[i];
                ans++;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
