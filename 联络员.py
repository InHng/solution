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
    
n, m = map(int, input().split())
ans = 0
dsu = DSU(n)
edges = []
for _ in range(m):
    state, u, v, w = map(int, input().split())
    if state == 1:
        dsu.merge(u, v)
        ans += w
    else:
        edges.append([w, u, v])
for w, u, v in sorted(edges):
    if dsu.merge(u, v):
        ans += w
print(ans)
