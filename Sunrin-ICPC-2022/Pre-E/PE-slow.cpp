#include <bits/stdc++.h>
using namespace std;

int N, A[101010], C[111], X[101010][111], L[111], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], C[A[i]] += 1;
    R = *max_element(C, C+111);

    memset(L, -1, sizeof L);
    for(int i=N; i>=1; i--){
        memcpy(X[i], L, sizeof L);
        L[A[i]] = i;
    }

    for(int d=-100; d<=100; d++){
        if(d == 0) continue;
        for(int i=1; i<=N; i++){
            int len = 0;
            for(int j=i; j!=-1; ){
                len += 1;
                int nxt = A[j] + d;
                if(nxt < 1 || nxt > 100) break;
                j = X[j][nxt];
            }
            R = max(R, len);
        }
    }

    cout << R;
}
