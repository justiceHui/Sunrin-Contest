#include <bits/stdc++.h>
using namespace std;

int N;
multiset<int> S, R;

void Solve(){
    if(R.size() == N){
        for(auto i : R) cout << i << " ";
        exit(0);
    }
    for(auto nxt : { *S.rbegin(), *R.rbegin() - *S.rbegin() }){
        if(nxt < 0 || R.count(nxt)) continue;

        auto st = S;
        bool valid = true;
        for(auto i : R){
            auto it = st.find(abs(i - nxt));
            if(it != st.end()) st.erase(it);
            else{ valid = false; break; }
        }
        if(!valid) continue;

        R.insert(nxt);
        swap(st, S);
        Solve();
        R.erase(R.find(nxt));
        swap(st, S);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0, t; i<N*(N-1)/2; i++) cin >> t, S.insert(S.end(), t);

    R.insert(0);
    Solve();
}