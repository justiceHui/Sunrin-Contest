def solve():
    n, t = map(int, input().split())
    a, b, c, d = [0]*(n+1), [0]*(n+1), [0]*(n+1), [0]*(n+1)
    for i in range(1, n+1):
        a[i],b[i],c[i],d[i] = map(int, input().split())
    e = list(map(int, input().split()))

    l, r = 0, t
    while l < r:
        m = (l + r) // 2
        now = m + e[0]
        for i in range(1, n+1):
            now = max(now, c[i])
            x = (now - c[i]) // a[i]
            if c[i]+a[i]*x <= now and now+d[i] <= c[i]+a[i]*x+b[i]:
                now += d[i] + e[i];
            else:
                now = c[i] + a[i]*(x+1) + d[i] + e[i];
        if now == t:
            print("YES")
            return
        if now > t: r = m
        else: l = m + 1
    print("NO")

T = int(input())
for tc in range(T): solve()