N = int(input())
A = list(map(int, input().split()))

mx = 0
for i in range(1, 9):
    now = 0
    for j in A:
        if i <= j <= i+2:
            now += 1
            if now > mx:
                mx = now
        else:
            now = 0

print(mx)