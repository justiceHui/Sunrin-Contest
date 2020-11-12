#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    
    int time = 1;
    int ans = 5;
    for(auto i : s){
        if(i == 'W'){
            time++; continue;
        }
        if(time == 1) ans = 6 - ans;
        if(time == 2) ans = 6;
    }
    
    if(time < 3) cout << 0;
    else cout << ans;
}