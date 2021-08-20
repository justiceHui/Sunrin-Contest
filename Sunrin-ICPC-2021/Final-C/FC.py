n = int(input())
a = list(map(int,input().split()))
dec = 0

for i in range(1, n):
    if a[i-1] > a[i]:
        dec += 1

if dec == 0:
    print(1)
elif dec == 1 and a[0] > a[n-1]:
    print(2)
else:
    print(3)