def is_leaf(y):
    return (y % 4 == 0 and y % 100 != 0) or y % 400 == 0

def get_max_date(y, m):
    if m == 2: return 28 + (1 if is_leaf(y) else 0)
    elif (m <= 7 and m % 2 == 1) or (m >= 8 and m % 2 == 0): return 31
    else: return 30

T = int(input())
for tc in range(T):
    y, m = map(int, input().split())
    if m > 1: print(y, m-1, get_max_date(y, m-1))
    else: print(y-1, 12, 31)