import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

class Comb:
    def __init__(self, n, mod):
        self.mod = mod
        self.fact = [1 for _ in range(n + 1)]
        self.infact = [1 for _ in range(n + 1)]
        for i in range(1, n + 1):
            self.fact[i] = (self.fact[i - 1] * i) % mod
        self.infact[n] = pow(self.fact[n], mod - 2, mod)
        for i in range(n - 1, -1, -1):
            self.infact[i] = (self.infact[i + 1] * (i + 1)) % mod

    def C(self, a, b):
        if a < b or b < 0:
            return 0
        return (self.fact[a] * self.infact[b] % self.mod * self.infact[a - b] % self.mod)

comb = Comb(2 * 10 ** 5 + 2, mod)

for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = 0
    a = list(map(int, input().split()))
    cnt = [a.count(0), a.count(1)]
    for i in range((k + 1) // 2):
        ans = (ans + comb.C(cnt[0], i) * comb.C(cnt[1], k - i) % mod) % mod
    print(ans)
