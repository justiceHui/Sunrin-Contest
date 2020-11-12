#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a, b; cin >> a >> b;
    double m = (b - a) / 400.0;
    double x = pow(10, m);
    x = 1 / (1 + x);
    cout << x;
}