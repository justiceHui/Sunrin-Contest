#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, R=6; cin >> N;
    for(int i=11; i<=N; i++) R *= i;
    cout << R;
}