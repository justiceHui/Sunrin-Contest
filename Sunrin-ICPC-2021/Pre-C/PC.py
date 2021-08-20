N = int(input())
S = input()
Ans = ""

if len(S) <= 25:
    Ans = S
elif '.' not in S[11:-12]:
    Ans = S[:11] + "..." + S[-11:]
else:
    Ans = S[:9] + "......" + S[-10:]

print(Ans)