#include <bits/stdc++.h>
using namespace std;

bool isPal(string &s, int l, int r){
    while(1){
        if(l >= r) return 1;
        if(s[l] != s[r]) return 0;
        l++; r--;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    if(!isPal(s, 0, s.size()-1)){
        cout << s.size();
    }else if(!isPal(s, 0, s.size()-2)){
        cout << s.size() - 1;
    }else{
        cout << -1;
    }
}