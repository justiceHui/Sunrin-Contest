def f(h, w):
    if h <= 140: return 6
    if h < 146: return 5
    if h < 159 or h >= 204: return 4
    bmi = w * 10000 / (h*h)
    if 159 <= h < 161:
        if 16.0 <= bmi < 35.0: return 3
        else: return 4
    if 20.0 <= bmi < 25.0: return 1
    if 18.5 <= bmi < 20.0 or 25.0 <= bmi < 30.0: return 2
    if 16.0 <= bmi < 18.5 or 30.0 <= bmi < 35.0: return 3
    return 4

T = int(input())
for tc in range(T):
    h, w = map(int, input().split())
    print(f(h, w))
