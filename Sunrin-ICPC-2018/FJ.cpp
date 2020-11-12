#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[40][40];

void rev(){
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) arr[i][j] = !arr[i][j];
}

bool f(){
    bool flag = 1;
    int t;
    for(int i=0; i<n; i++){
        t = 0;
        for(int j=0; j<n; j++) if(arr[i][j]) t++;
        if(t > n/2) for(int j=0; j<n; j++) arr[i][j] = 1;
        
        t = 0;
        for(int j=0; j<n; j++) if(arr[j][i]) t++;
        if(t > n/2) for(int j=0; j<n; j++) arr[j][i] = 1;
    }
    
    for(int i=0; i<n; i++) for(int j=0; j<n; j++){
            if(!arr[i][j]) flag = 0;
        }
    
    return flag;
}

int main() {
    cin >> n >> s;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)	cin >> arr[i][j];
    if(!s) rev();
    
    bool value = f();
    value = f();
    
    if (value) printf("1");
    else printf("0");
}