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
ans, cnt = 0, 0
dsu = DSU(n + 1)
edges = []
for _ in range(m):
    edges.append(list(map(int, input().split())))
edges.sort(key = lambda x: x[2])
for u, v, w in edges:
    if dsu.merge(u, v):
        ans += w
        cnt += 1

if cnt == n - 1:
    print(ans)
else:
    print("impossible")
