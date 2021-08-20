MOD = 998244353
N = int(input())
A = list(map(int, input().split()))
A.insert(0, 0)
D = [0] * (N+1)
for i in range(1, N+1):
    D[i] = 1
    for j in range(i-1, 0, -1):
        if A[j] < A[i]:
            D[i] += D[j]
    D[i] %= MOD
for i in range(1, N+1):
    print(D[i], end=' ')