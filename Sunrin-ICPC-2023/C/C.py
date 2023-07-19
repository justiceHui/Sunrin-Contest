from heapq import *

n, m, k, q = map(int, input().split())
edge = {}
g = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = map(int, input().split())
    edge[(u,v)] = 0

a = list(map(int, input().split()))

for _ in range(q):
    t, u, v = map(int, input().split())
    if (u,v) not in edge:
        edge[(u,v)] = t
    else:
        st, ed = edge[(u,v)], t - 1
        g[u].append((v, st, ed))
        g[v].append((u, st, ed))
        del edge[(u,v)]

for e, st in edge.items():
    u, v = e[0], e[1]
    ed = 400000
    g[u].append((v, st, ed))
    g[v].append((u, st, ed))

res = [10**9 for _ in range(n+1)]
pq = []

for i in range(k):
    res[a[i]] = 0
    heappush(pq, (0, a[i]))

while pq:
    c, v = heappop(pq)
    if c != res[v]: continue
    for i, s, e in g[v]:
        if c <= e and res[i] > max(s,c) + 1:
            res[i] = max(s,c) + 1
            heappush(pq, (res[i], i))

print(*[res[i] if res[i] < 10**9 else -1 for i in range(1, n+1)])