n, m, q = map(int, input().split())
a = [0] * (n+2)
x = [0] * (n+2)
w = [[0 for c in range(n+2)] for r in range(m+1)]

for i in range(1, m+1):
    tmp = list(map(int, input().split()))
    cnt = tmp[0]
    idx = []
    for j in range(cnt): idx.append(tmp[j+1])
    idx.append(n+1)
    for j in range(len(idx)):
        w[i][idx[j]] = tmp[cnt+1+j]

tmp = list(map(int, input().split()))
for i in range(1, m+1):
    t = tmp[i-1]
    for j in range(1, n+2): a[j] += t * w[i][j]
a[n+1] += tmp[m]

for iter in range(q):
    tmp = list(map(int, input().split()))
    for i in range(1, n+1): x[i] = tmp[i-1]
    x[n+1] = 1
    res = 0
    for i in range(1, n+2): res += a[i] * x[i]
    print(res)