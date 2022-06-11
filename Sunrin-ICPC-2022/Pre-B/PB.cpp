#include <bits/stdc++.h>
using namespace std;

bool IsLeaf(int y){
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int GetMax(int y, int m){
    if(m == 2) return 28 + IsLeaf(y);
    else if(m <= 7 && m % 2 == 1 || m >= 8 && m % 2 == 0) return 31;
    else return 30;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++){
        int y, m; cin >> y >> m;
        if(m > 1) cout << y << " " << m-1 << " " << GetMax(y, m-1) << "\n";
        else cout << y-1 << " " << 12 << " " << 31 << "\n";
    }
}
