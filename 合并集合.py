class DSU: # 并查集
    def __init__(self, n):
        self.pre = [i for i in range(n + 1)]
        self.siz = [1 for _ in range(n + 1)]
    
    def find(self, x):
        if self.pre[x] == x:
            return x
        self.pre[x] = self.find(self.pre[x])
        return self.pre[x]
    
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
    
n, m = map(int, input().split())
dsu = DSU(n)
for _ in range(m):
    op, a, b = map(str, input().split())
    a, b = int(a), int(b)
    if op == 'M':
        dsu.merge(a, b)
    else:
        print("Yes" if dsu.same(a, b) else "No")
