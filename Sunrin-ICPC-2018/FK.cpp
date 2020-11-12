#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

string s;
stack<int> stk;

int main(){
    int n; cin >> n >> s;
    stk.push(-1);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') stk.push(i);
        else{
            stk.pop();
            if(stk.empty()) stk.push(i);
            else ans = max(ans, i - stk.top());
        }
    }
    
    cout << ans;
}