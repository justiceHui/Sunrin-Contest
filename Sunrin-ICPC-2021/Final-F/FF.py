D = [0] * 44
D[0] = 0
D[1] = 1
D[2] = 2
for i in range(3, 44):
    D[i] = D[i-1] + D[i-2] + 1

def binary_search(v):
    l, r = 0, 43
    while l < r:
        m = (l + r + 1) // 2
        if D[m] <= v:
            l = m
        else:
            r = m - 1
    return l

T = int(input())
for i in range(T):
    v = int(input())
    print(binary_search(v))