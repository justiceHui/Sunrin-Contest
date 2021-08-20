N, K, X = map(int,input().split())
M = 998244353

Res = pow(X, N+K-2, M) * pow(X*(X+1)//2, 2, M) * K % M
for i in range(N-K+1):
    print(Res, end=' ')