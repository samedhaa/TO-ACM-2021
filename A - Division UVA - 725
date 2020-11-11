//Problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=666

#include<bits/stdc++.h>

using namespace std;

string numbers = "0123456789";
vector<string>nums;
int n;
bool allowed(string s, char c) {
    for(char ch : s) {
        if(ch == c) {
            return false;
        }
    }
    return true;
}
bool allowed(string s) {
    for(int i=0;i<s.size();i++) {
        for(int j=i+1;j<s.size();j++) {
            if(s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

void genStr(string s) {

    if(s.size() == 5) {
        int z = stoi(s) * n;
        string zstr = to_string(z);
        if((zstr.size() == 4 || zstr.size() == 5)) {
            if(zstr.size() == 4) {
                zstr.insert(0,"0");
            }
            if(allowed((zstr + s))) {
                nums.push_back(zstr + " / " + s + " = " + to_string(n));
            }
        }
        return;
    }
    for(int i=0;i<numbers.size();i++) {
        genStr(s + numbers[i]);
    }
}

int main()
{
    cin>>n;
    while(n) {
        genStr("");
        if(nums.size() == 0) {
            cout<<"There are no solutions for "<<n<<'.'<<endl;
        }
        else {
            for(auto u : nums) {
                cout<<u<<endl;
            }
        }
        nums.clear();
        cin>>n;
        if(n)cout<<endl;
    }
    return 0;
}
