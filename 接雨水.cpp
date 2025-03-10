class Solution {
public:
    int trap(vector<int>& h) {
        int ans = 0, left = 0, right = h.size() - 1, mx_left = *h.begin(), mx_right = h.back();
        while (left < right) {
            mx_left = max(mx_left, h[left]);
            mx_right = max(mx_right, h[right]);
            if (mx_left < mx_right) {
                ans += mx_left - h[left++];
            } else {
                ans += mx_right - h[right--];
            }
        }
        return ans;
    }
};
