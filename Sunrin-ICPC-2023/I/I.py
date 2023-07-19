n, m = map(int, input().split())
d = [0] * (n+1)
g = [[] for _ in range(n+1)]

d[1] = 100
for _ in range(m):
    s, e = map(int, input().split())
    g[s].append(e)

for i in range(1, n+1):
    if len(g[i]) == 0: continue
    nxt = d[i] / len(g[i])
    for j in g[i]: d[j] += nxt
    d[i] = 0

print(max(d))