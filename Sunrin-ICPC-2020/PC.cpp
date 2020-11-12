#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        ans += s.size();
    }
    cout << ans;
}