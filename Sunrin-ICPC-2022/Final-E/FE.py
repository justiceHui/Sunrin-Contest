n, q = map(int, input().split())
res = 0
for i in range(q):
    t, a, b = map(int, input().split())
    if t == 1: res = 1 - res
    elif (b - a + 1) // 2 % 2 == 1: res = 1 - res
    print(res)