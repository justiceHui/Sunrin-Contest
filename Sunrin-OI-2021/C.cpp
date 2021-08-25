#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int K; cin >> K;
    vector<int> res;
    for(int i=1; i<=18; i++){
        if((1 << i) - 1 <= K) res.push_back(i);
    }
    K -= (1 << res.size()) - 1;
    for(int i=res.size()-1; i>=0; i--){
        if(K & (1 << i)){
            K -= 1 << i;
            res.push_back(i+1);
        }
    }

    cout << res.size() << "\n";
    for(auto i : res) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) Solve();
}