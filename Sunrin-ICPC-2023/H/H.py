n = int(input())
a = list(map(int, input().split()))
a.sort()

res = 0

x = [0] * n
for i in range(n):
    x[i] = a[i]
    for j in range(i):
        if a[j] <= a[i]: x[i] = max(x[i], x[j] + a[i])

y = [0] * n
for i in range(n):
    y[i] = a[i]
    for j in range(i):
        if a[j] >= a[i]: y[i] = max(y[i], y[j] + a[i])

print(max(x) + max(y))
print(*a)