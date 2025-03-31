from sys import stdin
input = lambda: stdin.readline()

class DSU: # 并查集
    def __init__(self, dict):
        self.pre = dict
    
    def find(self, x):
        x, xcopy = self.pre[x], x
        while x != self.pre[x]:
            x = self.pre[x]
        while xcopy != x:
            self.pre[xcopy], xcopy = x, self.pre[xcopy]
        return x
    
    def same(self, x, y):
        return self.find(x) == self.find(y)

    def merge(self, x, y, z):
        x, y, z = self.find(x), self.find(y), self.find(z)
        self.pre[y] = x
        self.pre[z] = x

mp = {}
s = [list(input().split()) for _ in range(int(input()))]
ns = [list(input().split()) for _ in range(int(input()))]
group = [list(input().split()) for _ in range(int(input()))]
for g in group:
    mp[g[0]] = g[0]
    mp[g[1]] = g[1]
    mp[g[2]] = g[2]
# --- 先全部存起来, 从这里开始进行判断 ---
dsu = DSU(mp)
for name1, name2, name3 in group:
    dsu.merge(name1, name2, name3)
ans = 0
for name1, name2 in s:
    ans += (0 if dsu.same(mp[name1], mp[name2]) else 1)
for name1, name2 in ns:
    ans += (1 if dsu.same(mp[name1], mp[name2]) else 0)
print(ans)
