#include <bits/stdc++.h>
using namespace std;

int N, M, C[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0,a,b; i<N; i++) cin >> a >> b;
    for(int i=0; i<M; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        C[string("RBG").find(c)] += 1;
    }
    for(int i=0; ; i++){
        if(C[2] > 0) C[2] -= 1;
        else if(C[i%2] > 0) C[i%2] -= 1;
        else{
            if(i % 2 == 0) cout << "jhnan917";
            else cout << "jhnah917";
            break;
        }
    }
}