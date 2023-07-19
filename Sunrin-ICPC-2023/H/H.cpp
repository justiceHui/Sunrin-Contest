#include <bits/stdc++.h>
using namespace std;

int N, A[1010], B[1010], C[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    for(int i=1; i<=N; i++) B[i] = C[i] = A[i];
    for(int i=1; i<=N; i++) for(int j=1; j<i; j++) if(A[j] <= A[i]) B[i] = max(B[i], B[j] + A[i]);
    for(int i=1; i<=N; i++) for(int j=1; j<i; j++) if(A[j] >= A[i]) C[i] = max(C[i], C[j] + A[i]);
    cout << *max_element(B+1, B+N+1) + *max_element(C+1, C+N+1) << "\n";
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}