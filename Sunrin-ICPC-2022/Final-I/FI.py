n = int(input())
a = []
for i in range(n): a.append(list(map(int, input().split())))
d = [[0 for c in range(n)] for r in range(n)]
res = 0

for i in range(n):
    for j in range(n):
        mx = 0
        for r in range(i+1):
            for c in range(j+1):
                if a[r][c] < a[i][j]: mx = max(mx, d[r][c])
        d[i][j] = mx + 1
        res = max(res, d[i][j])
print(res)