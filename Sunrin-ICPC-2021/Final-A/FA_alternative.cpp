#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;
constexpr int SZ = 1 << 18;

int N, A[SZ], D[SZ], P[SZ], U[SZ];
PII T[SZ << 1]; // Segment Tree
void Update(int x, PII v){
    x |= SZ; T[x] = max(T[x], v);
    while(x >>= 1) T[x] = max(T[x<<1], T[x<<1|1]);
}
PII Query(int l, int r){
    PII ret(0,0);
    for(l|=SZ, r|=SZ; l<=r; l>>=1, r>>=1){
        if(l & 1) ret = max(ret, T[l++]);
        if(~r & 1) ret = max(ret, T[r--]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    // Compress A[i] to 1...N
    vector<int> C(A+1, A+N+1);
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
    for(int i=1; i<=N; i++) A[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin() + 1;

    // Calculate DP
    for(int i=1; i<=N; i++){
        auto [v,p] = Query(0, A[i]);
        D[i] = v + 1;
        P[i] = p;
        Update(A[i], {D[i], i});
    }

    // Get LIS
    vector<int> lis;
    int ed = max_element(D+1, D+N+1) - D;
    for(int i=ed; i; i=P[i]) lis.push_back(i);
    reverse(lis.begin(), lis.end());
    for(auto i : lis) U[i] = 1;

    if(N - (int)lis.size() <= 3){
        cout << "YES\n";
        cout << N - (int)lis.size() << "\n";
        for(int i=1,lst=1; i<=N; i++){
            if(U[i]) lst = C[A[i]-1];
            else cout << i << " " << lst << "\n";
        }
    }
    else{
        cout << "NO";
    }
}