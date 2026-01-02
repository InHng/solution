#include <bits/stdc++.h>
using namespace std;

struct Node { // 树节点数据结构
    int left = 0;
    int right = 0;
};

int main() {
    int n, start;
    cin >> n;
    vector<Node> node(n + 1);
    vector<int> in(n + 1);
    for (int i = 1; i < n; ++i) { // 建树
        int a, b;
        cin >> a >> b;
        in[b]++;
        if (node[a].left == 0 and node[a].right == 0) { // 若当前节点 a 没孩子，则当作“父节点仅有一个孩子”
            if (a < b) {
                node[a].left = b;
            } else {
                node[a].right = b;
            }
        } else if (node[a].left) { // 若当前节点 a 有一个左孩子，做出相对应的调整
            if (node[a].left > b) {
                node[a].right = node[a].left;
                node[a].left = b;
            } else {
                node[a].right = b;
            }
        } else { // 若当前节点 a 有一个右孩子，做出相对应的调整
            if (node[a].right < b) {
                node[a].left = node[a].right;
                node[a].right = b;
            } else {
                node[a].left = b;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            start = i;
            break;
        }
    }

    function<void(int)> pre_search = [&](int now) {
        cout << now << " ";
        if (node[now].left) {
            pre_search(node[now].left);
        }
        if (node[now].right) {
            pre_search(node[now].right);
        }
    };

    function<void(int)> mid_search = [&](int now) {
        if (node[now].left) {
            mid_search(node[now].left);
        }
        cout << now << " ";
        if (node[now].right) {
            mid_search(node[now].right);
        }
    };

    function<void(int)> rear_search = [&](int now) {
        if (node[now].left) {
            rear_search(node[now].left);
        }
        if (node[now].right) {
            rear_search(node[now].right);
        }
        cout << now << " ";
    };

    pre_search(start);
    cout << endl;
    mid_search(start);
    cout << endl;
    rear_search(start);
}
