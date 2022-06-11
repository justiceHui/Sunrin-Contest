#include <bits/stdc++.h>
using namespace std;

bool InRange(double s, double e, double bmi){
    return s <= bmi && bmi < e;
}

int f(int h, int w){
    if(h <= 140) return 6;
    if(h < 146) return 5;
    if(h < 159 || h >= 204) return 4;
    double bmi = w*10000.0 / (h*h);
    if(159 <= h && h < 161){
        if(InRange(16.0, 35.0, bmi)) return 3;
        else return 4;
    }
    if(InRange(20.0, 25.0, bmi)) return 1;
    if(InRange(18.5, 20.0, bmi) || InRange(25.0, 30.0, bmi)) return 2;
    if(InRange(16.0, 18.5, bmi) || InRange(30.0, 35.0, bmi)) return 3;
    return 4;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++){
        int H, W; cin >> H >> W;
        cout << f(H, W) << "\n";
    }
}