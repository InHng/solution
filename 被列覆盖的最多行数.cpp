class Solution {
public:
	int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int mask[15], suf[15];
		int m = matrix.size(), n = matrix[0].size();
        int ans = m;
        numSelect = n - numSelect;
        function<void(int, int, int)> dfs = [&](int i, int cnt, int cover) -> void {
            if (cnt == numSelect) {
                // __builtin_popcount 函数统计在二进制下 1 的个数
                ans = min(ans, __builtin_popcount(cover));
                return;
            }
            if (cnt + n - i == numSelect) {
                dfs(n, numSelect, cover | suf[i]);
            } else {
                dfs(i + 1, cnt + 1, cover | mask[i]);
                dfs(i + 1, cnt, cover);
            }
        };
        
		for (int j = 0; j < n; ++j) {
			mask[j] = 0;
			for (int i = 0; i < m; ++i) {
                mask[j] |= matrix[i][j] << i;
            }
		}
		suf[n - 1] = mask[n - 1]; 
		for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i+1] | mask[i];
        }
		dfs(0, 0, 0);
		return m - ans;
	}
};
