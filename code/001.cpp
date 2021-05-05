/*
 * @date:2021-05-04 23:19:28
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_a
*/
#include <bits/stdc++.h>

using namespace std;

int N, L, K;
vector<int> v;

bool check(int l) {
    int lst = 0, num = 0;
    for (int i = 0; i <= N; ++i) {
        if (v[i] - lst >= l) {
            ++num;
            lst = v[i];
        }
    }
    return num >= K + 1;
}

int main() {
    scanf("%d%d%d", &N, &L, &K);
    v.resize(N);
    for (auto &x : v) scanf("%d", &x);
    v.push_back(L);
    int l = 0, r = L, ans;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}