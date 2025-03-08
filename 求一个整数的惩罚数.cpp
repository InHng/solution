class Solution {
public:
    int punishmentNumber(int n) {
        vector<int> pre(1001);
        for (int i = 1; i <= 1000; ++i) {
            string s = to_string(i * i);
            int n = s.size();

            function<bool(int, int)> dfs = [&](int p, int sum) -> bool {
                if (p == n) {
                    return sum == i;
                }
                int x = 0;
                for (int j = p; j < n; ++j) {
                    x = x * 10 + s[j] - '0';
                    if (dfs(j + 1, sum + x)) {
                        return true;
                    }
                }
                return false;
            };

            pre[i] = pre[i - 1] + (dfs(0, 0) ? i * i : 0);
        }

        return pre[n];
    }
};
