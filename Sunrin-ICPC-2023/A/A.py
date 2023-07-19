n = int(input())
res, now = 6, 11
while now <= n:
    res *= now
    now += 1
print(res)
