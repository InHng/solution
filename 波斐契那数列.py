import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353
def mul(A, B):
    res = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(A[0])):
            for k in range(len(B[0])):
                res[i][k] = (res[i][k] + A[i][j] * B[j][k]) % mod
    return res

def ksm(a, b):
    res = [[0 for _ in range(len(a))] for _ in range(len(a))]
    for i in range(len(res)):
        res[i][i] = 1
    while b:
        if b & 1:
            res = mul(res, a)
        a = mul(a, a)
        b >>= 1
    return res

for _ in range(int(input())):
    n = int(input())
    A = [
        [1],
        [1],
        [1]
    ]
    B = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 1]
    ]
    print(mul(ksm(B, n - 1), A)[0][0])
