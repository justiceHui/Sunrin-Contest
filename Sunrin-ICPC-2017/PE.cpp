#include <bits/stdc++.h>
using namespace std;

int p, n;
int arr[101] = {0};

int main(){
    cin>>p>>n;
    for(int i=0; i<n; i++){
        int pos; char c; scanf("%d %c", &pos, &c);
        if(c == 'R'){
            for(int j=pos+1; j<=100; j++) arr[j]++;
        }else{
            for(int j=1; j<pos; j++) arr[j]++;
        }
    }
    
    int cnt[3] = {0};
    for(int i=1; i<=100; i++){
        cnt[arr[i]%3]++;
    }
    printf("%.2lf\n", (double)cnt[0]/100.0*p);
    printf("%.2lf\n", (double)cnt[1]/100.0*p);
    printf("%.2lf", (double)cnt[2]/100.0*p);
}