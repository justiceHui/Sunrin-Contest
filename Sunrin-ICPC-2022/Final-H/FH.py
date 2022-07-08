def gcd(a, b):
    while b != 0: (a,b) = (b,a%b)
    return a

tc = int(input())

for t in range(tc):
    n = int(input())
    if n % 2: print(n * (n-1) * (n-2))
    elif gcd(n, n-3) == 1: print(n * (n-1) * (n-3))
    else: print((n-1) * (n-2) * (n-3))