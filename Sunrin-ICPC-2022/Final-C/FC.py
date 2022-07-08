n = int(input())

s, e, c, p, rnk = [0]*(n-1), [0]*(n-1), [0]*(n-1), [0]*(n-1), [0]*(n-1)
group, vertex = [0]*(n+1), [0]*(n+1)
g = [[] for i in range(n+1)]
for i in range(0, n-1): p[i] = i

def find(v):
    if v == p[v]: return v
    p[v] = find(p[v])
    return p[v]

def merge(u, v):
    u = find(u)
    v = find(v)
    if u == v: return
    if rnk[u] > rnk[v]: (u,v) = (v,u)
    p[u] = v
    if rnk[u] == rnk[v]: rnk[v] += 1

for i in range(n-1):
    s[i], e[i], c[i] = map(int, input().split())
    g[s[i]].append((e[i], i))
    g[e[i]].append((s[i], i))

a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))

for i in range(1, n+1): g[i].sort(key=lambda x: c[x[1]])

for i in range(1, n+1):
    for j in range(1, len(g[i])):
        if c[g[i][j-1][1]] == c[g[i][j][1]]: merge(g[i][j-1][1], g[i][j][1])

for i in range(1, n+1): g[i].sort(key=lambda x: find(x[1]))

for i in range(1, n+1):
    for j in range(0, len(g[i])):
        if j == 0 or find(g[i][j-1][1]) != find(g[i][j][1]): group[find(g[i][j][1])] += a[i]

for i in range(1, n+1):
    for j in range(0, len(g[i])):
        if j == 0 or find(g[i][j-1][1]) != find(g[i][j][1]): vertex[i] += group[find(g[i][j][1])]

mn, mx = 0, 0
vertex = vertex[1:]
b = b[1:]
vertex.sort()
b.sort()
for i in range(n):
    mn += vertex[i] * b[n-i-1]
    mx += vertex[i] * b[i]

print(mn)
print(mx)