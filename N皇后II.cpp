class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> col(n * 2 + 1, false), dig(n * 2 + 1, false), back_dig(n * 2 + 1, false);
        vector<string> g(n);

        function<void(int)> dfs = [&](int deep) -> void {
            if (deep == n) {
                ans++;
                return;
            }
            for (int i = 0; i < n; ++i) {
                if(!(col[i] || dig[n + deep - i] || back_dig[deep + i])) {
                    col[i] = dig[n + deep - i] = back_dig[deep + i] = true;
                    dfs(deep + 1);
                    col[i] = dig[n + deep - i] = back_dig[deep + i] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};
