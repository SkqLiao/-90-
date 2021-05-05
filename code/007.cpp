/*
 * @date:2021-05-05 11:54:57
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_g
*/
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

int main() {
    scanf("%d", &N);
    v.resize(N);
    for (auto &x : v) scanf("%d", &x);
    sort(v.begin(), v.end());
    scanf("%d", &M);
    for (int i = 1, x; i <= M; ++i) {
        scanf("%d", &x);
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end()) printf("%d\n", x - *--it);
        else if (it == v.begin()) printf("%d\n", *it - x);
        else {
            int ans = *it - x;
            printf("%d\n", min(ans, x - *--it));
        }
    }
    return 0;
}