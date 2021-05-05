/*
 * @date:2021-05-05 12:35:00
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_i
*/
#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))

const int MAXN = 2000 + 5;
const double PI = 3.141592653589;

int N;
vector<pair<int, int>> v, f[MAXN];

int main() {
    scanf("%d", &N);
    v.resize(N);
    for (auto &x : v) scanf("%d%d", &x.first, &x.second);
    double ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            f[i].push_back({v[j].first - v[i].first, v[j].second - v[i].second});
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double a = v[i].first * v[j].first + v[i].second * v[j].second;
            double b = sqrt(sqr(v[i].first) + sqr(v[i].second)) * sqrt(sqr(v[j].first) + sqr(v[j].second));
            double c = a / b;
            if (!a || !b) c = 0;
            double angle = acos(c) * 180 / PI;
            ans = max(ans, angle);
            printf("%lf %lf %lf : %lf\n", a, b, c, angle);
        }
    }
    printf("%lf\n", ans);
    return 0;
}