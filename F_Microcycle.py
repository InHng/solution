class DSU: # 并查集
    def __init__(self, n):
        self.pre = list(range(n + 1))
    
    def find(self, x):
        x = self.pre[x]
        xcopy = x
        while x != self.pre[x]:
            x = self.pre[x]
        while xcopy != x:
            self.pre[xcopy], xcopy = x, self.pre[xcopy]
        return x
    
    def same(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y

    def merge(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        self.pre[y] = x
        return True
    
def solve():
    n, m = map(int, input().split())
    ans, start, end = 0x3f3f3f3f3f3f3f3f, None, None
    dsu = DSU(n + 1)
    g, edges = [[] for _ in range(n + 1)], []
    for _ in range(m):
        edges.append(list(map(int, input().split())))
    edges.sort(reverse = True, key = lambda x: x[2])
    for i in sorted(range(m), key = lambda x: -edges[x][2]):
        u, v, w = edges[i]
        if dsu.merge(u, v):
            g[u].append(v)
            g[v].append(u)
        elif start is None or w < ans:
            ans, start, end = w, u, v

    pre = [-1 for _ in range(n + 1)]
    stack = [start]
    while stack:
        u = stack.pop()
        for v in g[u]:
            if pre[u] != v:
                pre[v] = u
                stack.append(v)
    ans_path = [end]
    while pre[ans_path[-1]] != -1:
        ans_path.append(pre[ans_path[-1]])
    print(ans, len(ans_path))
    print(*ans_path)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
