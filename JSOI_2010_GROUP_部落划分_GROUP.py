import sys
input = lambda: sys.stdin.readline().strip()
from math import sqrt

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

n, k = map(int, input().split())
dsu = DSU(n)
cnt = 0
points, dis = [], []
points = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    x, y = points[i]
    for j in range(i):
        xx, yy = points[j]
        dx, dy = x - xx, y - yy
        dist = sqrt(dx * dx + dy * dy)
        dis.append((dist, i, j))
dis.sort()
for l, x, y in dis:
    if dsu.merge(x, y):
        cnt += 1
        if cnt == n - k + 1:
            print(f"{l:.2f}")
