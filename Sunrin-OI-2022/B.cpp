#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, Q, A[303030];
multiset<ll> S, D;

bool Check1(){
    return *D.begin() == *D.rbegin() && *D.begin() > 0;
}

bool Check2(){
    if(*S.begin() == *S.rbegin()) return true;
    if(N > 60 || *D.begin() < 0) return false;
    for(int i=2; i<=N; i++) if(A[i] % A[i-1] != 0 || A[i] / A[i-1] != A[2] / A[1]) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) S.insert(A[i]);
    for(int i=2; i<=N; i++) D.insert(A[i] - A[i-1]);
    for(int i=1; i<=Q; i++){
        ll x, v; cin >> x >> v;

        if(x > 1) D.erase(D.find(A[x]-A[x-1]));
        if(x < N) D.erase(D.find(A[x+1]-A[x]));
        S.erase(S.find(A[x]));

        A[x] = v;
        if(x > 1) D.insert(A[x]-A[x-1]);
        if(x < N) D.insert(A[x+1]-A[x]);
        S.insert(A[x]);

        if(Check1()) cout << "+\n";
        else if(Check2()) cout << "*\n";
        else cout << "?\n";
    }
}