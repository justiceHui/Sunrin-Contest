#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, q;
int arr[1001];

void op1(int a, int b){
    ll ret = 0;
    for(int i=a; i<=b; i++) ret += arr[i];
    swap(arr[a], arr[b]);
    printf("%lld\n", ret);
}

void op2(int a, int b, int c, int d){
    ll sum1 = 0, sum2 = 0;
    for(int i=a; i<=b; i++) sum1 += arr[i];
    for(int i=c; i<=d; i++) sum2 += arr[i];
    printf("%lld\n", sum1 - sum2);
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) scanf("%d", arr+i);
    while(q--){
        int op; scanf("%d", &op);
        if(op == 1){
            int a, b; cin>>a>>b;
            op1(a, b);
        }
        else{
            int a, b, c, d; cin>>a>>b>>c>>d;
            op2(a, b, c, d);
        }
    }
}