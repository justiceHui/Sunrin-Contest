#include <bits/stdc++.h>
using namespace std;

int N, Q, R = 0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=Q; i++){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) R ^= 1;
        else if((b - a + 1) / 2 % 2 == 1) R ^= 1;
        cout << R << "\n";
    }
}