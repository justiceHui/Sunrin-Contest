n = int(input())
a = list(map(int, input().split()))
a.insert(0, 0)

inf = 1000000000

dp = [[inf for col in range(4)] for row in range(n+1)]
prv = [[0 for col in range(4)] for row in range(n+1)]

dp[0][0] = 1
for i in range(1, n+1):
    for j in range(0, 4):
        if dp[i-1][j] <= a[i] and dp[i][j] > a[i]:
            dp[i][j] = a[i]
            prv[i][j] = j
        if j > 0 and dp[i][j] > dp[i-1][j-1]:
            dp[i][j] = dp[i-1][j-1]
            prv[i][j] = j-1

isFinished = False
for ti in range(0, 4):
    if dp[n][ti] == inf:
        continue
    print("YES")
    print(ti)
    i, j = n, ti
    while i > 0:
        if prv[i][j] == j-1:
            print(i, dp[i][j])
        j = prv[i][j]
        i -= 1
    isFinished = True
    break

if not isFinished:
    print("NO")