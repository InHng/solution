import sys
input = lambda: sys.stdin.readline().strip()
mod = 998244353

class DSU: # 并查集
    def __init__(self, n):
        self.pre = list(range(n + 1))
        self.siz = [1 for _ in range(n + 1)]
    
    def find(self, x):
        x, xcopy = self.pre[x], x
        while x != self.pre[x]:
            x = self.pre[x]
        while xcopy != x:
            self.pre[xcopy], xcopy = x, self.pre[xcopy]
        return x
    
    def same(self, x, y):
        return self.find(x) == self.find(y)

    def merge(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.siz[x] += self.siz[y]
        self.pre[y] = x
        return True
    
    def size(self, x):
        return self.siz[self.find(x)]

for _ in range(int(input())):
    n = int(input())
    s = list(input())
    dsu = DSU(n)
    idx = [0 for _ in range(n)]
    st = []
    cnt = 0
    for i in range(n):
        if s[i] == '(':
            idx[i] = cnt
            st.append(cnt)
            cnt += 1
        else:
            idx[i] = st.pop()
    cnt = 0
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            cnt += dsu.merge(idx[i], idx[i + 1])
    print(pow(2, n // 2 - cnt, mod))
