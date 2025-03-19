n = int(input())
P = input()
m = int(input())
S = input()

s = P + " " + S
n, m = m, n
pi = [0 for _ in range(n + m + 1)]
for i in range(1, n + m + 1):
    l = pi[i - 1]
    while l and s[i] != s[l]:
        l = pi[l - 1]
    if s[i] == s[l]:
        pi[i] = l + 1
        if pi[i] == m:
            print(i - m * 2, end = " ")
