from queue import Queue

n, m = map(int, input().split())
g, IN, ans = [[] for _ in range(n + 1)], [0 for _ in range(n + 1)], []
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    IN[v] += 1

q = Queue()
for i in range(1, n + 1):
    if IN[i] == 0:
        q.put(i)
        ans.append(i)
while q.qsize():
    u = q.get()
    for v in g[u]:
        IN[v] -= 1
        if IN[v] == 0:
            q.put(v)
            ans.append(v)

if len(ans) == n:
    print(*ans)
else:
    print(-1)
