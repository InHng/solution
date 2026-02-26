#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int mod = 1e9 + 7; // 998244353;
using Matrix = vector<vector<int>>;
Matrix mul(const Matrix& A, const Matrix& B) {
    Matrix res(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            for (int k = 0; k < B[0].size(); k++) {
                res[i][k] = (res[i][k] + (A[i][j] * B[j][k] % mod)) % mod;
            }
        }
    }
    return res;
}

Matrix ksm(Matrix a, int b){
    Matrix res(a.size(), std::vector<int>(a.size()));
    for(int i = 0; i < res.size(); i++){
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << 1 << endl;
        return;
    }
    Matrix A(3, vector<int>(1)), B(3, vector<int>(3));
    A = {
        {1},
        {1},
        {1}
    };
    B = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 1}
    };
    vector<vector<int>> ans = mul(ksm(B, n - 1), A);
    cout << ans[0][0] << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
