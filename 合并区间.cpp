class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        ranges::sort(a);
        int start = a[0][0], end = a[0][1];
        for (int i = 1; i < a.size(); ++i) {
            if (a[i][0] <= end) {
                end = max(end, a[i][1]);
            } else {
                ans.push_back({start, end});
                start = a[i][0], end = a[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
