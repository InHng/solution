from queue import Queue

n, m = map(int, input().split())
while n or m:
    cnt = 0
    flag = True
    memo = [0 for _ in range(n)]
    g, In = [[] for _ in range(n)], [0 for _ in range(n)]

    def topsort(id, g):
        global flag, cnt
        q = Queue()
        IN = In.copy()
        for i in range(n):
            if not IN[i]:
                q.put(i)
        
        ans = ""
        unique = True
        while q.qsize():
            if q.qsize() > 1:
                unique = False
            u = q.get()
            ans += chr(ord('A') + u)
            for v in g[u]:
                IN[v] -= 1
                if IN[v] == 0:
                    q.put(v)
        
        if len(ans) < cnt:
            flag = False
            print(f"Inconsistency found after {id} relations.")
        elif len(ans) == n and unique:
            flag = False
            print(f"Sorted sequence determined after {id} relations: {ans}.")

    for i in range(1, m + 1):
        s = list(input())
        if not flag:
            continue
        a, b = ord(s[0]) - ord('A'), ord(s[2]) - ord('A')
        if not memo[a]:
            memo[a] = 1
            cnt += 1
        if not memo[b]:
            memo[b] += 1
            cnt += 1
        if a == b:
            flag = False
            print(f"Inconsistency found after {i} relations.")
            continue
        g[a].append(b)
        In[b] += 1
        topsort(i, g)
    if flag:
        print("Sorted sequence cannot be determined.")
    n, m = map(int, input().split())
