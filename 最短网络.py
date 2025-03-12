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
    
n = int(input())
dsu = DSU(n)
edges = []
ans = 0
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(n):
        if a[j]:
            edges.append([a[j], i + 1, j + 1])

edges.sort()
for w, x, y in edges:
    if dsu.merge(x, y):
        ans += w
print(ans)
