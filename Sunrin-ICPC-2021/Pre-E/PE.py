T = int(input())
pw3 = [0] * 40

pw3[0] = 1
for i in range(1, 40):
    pw3[i] = pw3[i-1] * 3

for tc in range(T):
    N = int(input())
    ans = 0
    for i in range(0, 40):
        if (N & (1 << i)) != 0:
            ans += pw3[i]
    print(ans)