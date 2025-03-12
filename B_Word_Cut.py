MOD = int(1e8 + 7)

start = input().strip()
end = input().strip()
k = int(input())
n = len(start)

# dp[i][0] 表示分割 i 次变成了 end 的方案数
# dp[i][1] 表示分割 i 次没变成 end 的方案数
dp = [[0, 0] for _ in range(k + 1)]

if start == end:
    dp[0][0] = 1
else:
    dp[0][1] = 1

x = 0
for i in range(n):  # 从 i 这个位置开始分割串
    flag = True
    for j in range(n):  # 判断从 i 位置分割串能否成立
        if start[(i + j) % n] != end[j]:
            flag = False
            break
    x += flag

for i in range(k):
    # 其他串通过一次变换得到 x 个 end，每个原串通过一次变换得到除了自己以外的 x - 1 个其他原串
    dp[i + 1][0] = (x * dp[i][1] + (x - 1) * dp[i][0]) % MOD
    # 其他串通过一次变换得到 n - x 个其他串，每个原串通过一次变换得到除了自己以外的 n - x - 1 个其他串
    dp[i + 1][1] = ((n - x) * dp[i][0] + (n - x - 1) * dp[i][1]) % MOD

print(dp[k][0])
