from collections import deque

n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))
q = deque()
for i in range(1, n + 1):
    while q and q[-1] > a[i]:
        q.pop()
    q.append(a[i])
    if i - k >= 1 and q[0] == a[i - k]:
        q.popleft()
    if i >= k:
        print(q[0], end = " ")
print()
q = deque()
for i in range(1, n + 1):
    while q and q[-1] < a[i]:
        q.pop()
    q.append(a[i])
    if i - k >= 1 and a[i - k] == q[0]:
        q.popleft()
    if i >= k:
        print(q[0], end = " ")
