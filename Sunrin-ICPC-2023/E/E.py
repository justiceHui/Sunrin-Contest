n, m = map(int, input().split())
if n == 1 and m == 1:
    print('1\n1')
elif n == 1 or m == 1:
    print(2)
    print(*[(1,2)[i%2] for i in range(n*m)], sep=(' ' if n == 1 else '\n'))
else:
    print(4)
    for i in range(n):
        if i % 2 == 0: print(*[(1,2,3,4)[j%4] for j in range(m)])
        else: print(*[(3,4,1,2)[j%4] for j in range(m)])