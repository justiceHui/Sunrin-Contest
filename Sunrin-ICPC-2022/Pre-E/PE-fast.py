n = int(input())
a = [0] + list(map(int, input().split()))

c = [0] * 101
dp = [[0 for col in range(101)] for row in range(101)]

for i in a: c[i] += 1
mx = max(c)

if n >= 100 * 100:
    print(mx)
else:
    for d in range(1, 101):
        for i in range(1, n+1):
            if a[i] - d >= 1: dp[d][a[i]] = max(dp[d][a[i]], dp[d][a[i]-d] + 1)
            else: dp[d][a[i]] = max(dp[d][a[i]], 1)
            mx = max(mx, dp[d][a[i]])

    a = a[1:]
    a.reverse()
    a = [0] + a
    dp = [[0 for col in range(101)] for row in range(101)]

    for d in range(1, 101):
        for i in range(1, n+1):
            if a[i] - d >= 1: dp[d][a[i]] = max(dp[d][a[i]], dp[d][a[i]-d] + 1)
            else: dp[d][a[i]] = max(dp[d][a[i]], 1)
            mx = max(mx, dp[d][a[i]])

    print(mx)