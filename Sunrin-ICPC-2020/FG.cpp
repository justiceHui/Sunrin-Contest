#include <bits/stdc++.h>
using namespace std;

int N, M, Q, R[111];
vector<int> A[111];

bool cmp(int t1, int t2){
    return R[t1] < R[t2];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> R[i];
    for(int i=1; i<=N; i++){
        int cnt; cin >> cnt;
        for(int j=1; j<=cnt; j++){
            int now; cin >> now;
            A[now].push_back(i);
        }
    }

    for(int i=1; i<=M; i++) sort(A[i].begin(), A[i].end(), cmp);

    cin >> Q;
    for(int i=1; i<=Q; i++){
        int now; cin >> now;
        for(auto j : A[now]) cout << j << " ";
        if(A[now].empty()) cout << -1;
        cout << "\n";
    }
}