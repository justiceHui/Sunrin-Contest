n = int(input())
a = [0] + list(map(int, input().split()))

c = [0] * 101
idx = [[0 for col in range(101)] for row in range(n+1)]
lst = [0] * 101

for i in a: c[i] += 1
mx = max(c)

if n >= 100 * 100:
    print(mx)
else:
    for i in range(1, 101): lst[i] = -1
    for i in range(n, 0, -1):
        for j in range(1, 101): idx[i][j] = lst[j]
        lst[a[i]] = i
    for d in range(-100, 101):
        if d == 0: continue
        for i in range(1, n):
            j, len = i, 0
            while j != -1:
                nxt = a[j] + d
                len += 1
                if 1 <= nxt <= 100: j = idx[j][nxt]
                else: break
            mx = max(mx, len)
    print(mx)