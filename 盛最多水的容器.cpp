class Solution {
public:
    int maxArea(vector<int>& a) {
        int left = 0, right = a.size() - 1, ans = 0;
        while (left <= right) {
            ans = max(ans, min(a[left], a[right]) * (right - left));
            if (a[left] < a[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
