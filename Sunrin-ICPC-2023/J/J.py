n = int(input())
a = [0] * (n+10)

if n % 3 == 0:
    for i in range(1, n+1, 3):
        a[i] = -1
        a[i+1] = 2
        a[i+2] = 2

if n % 3 == 1:
    for i in range(1, n+1, 3):
        a[i] = 2
        a[i+1] = -1
        a[i+2] = 2

if n % 3 == 2:
    a[1] = 1
    for i in range(2, n+1, 3):
        a[i] = 2
        a[i+1] = -1
        a[i+2] = 2

for i in range(1, n+1): a[i] += a[i-1]

print(n)
print(*[a[i] % n + 1 for i in range(n)], 1)