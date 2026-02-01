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

n = int(input())
now, need = n // 3, n // 2
left = need - now
comb = Comb(n, mod)
print(comb.C(now, left) * comb.C(n - now, left) % mod * comb.fact[n - now] % mod * comb.fact[now] % mod)
