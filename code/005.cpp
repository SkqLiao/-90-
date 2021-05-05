/*
 * @date:2021-05-05 10:38:49
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_e
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXB = 1000 + 5;
const int MOD = 1e9 + 7;
const int LOG = 70;

long long N;
int B, K;
vector<int> v;
vector<long long> f;
long long P[LOG];

vector<long long> trans(vector<long long> &f, vector<long long> &g, int len) {
    static vector<long long> h(B + 1);
    fill(h.begin(), h.end(), 0);
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < B; ++j) {
            h[(i * P[len] + j) % B] += f[i] * g[j] % MOD;
            h[(i * P[len] + j) % B] %= MOD;
        }
    }
    return h;
}

long long poww(vector<long long> &f, long long t) {
    vector<long long> g(f);
    int ff = 1;
    for (--t; t; t >>= 1) {
        if (t & 1) g = trans(g, f, ff);
        f = trans(f, f, ff++);
    }
    return g[0];
}

int main() {
    scanf("%lld%d%d", &N, &B, &K);
    v.resize(K);
    P[1] = 10 % B;
    for (int i = 2; i < LOG; ++i) P[i] = P[i - 1] * P[i - 1] % B;
    for (auto &x : v) scanf("%d", &x);
    f.resize(B + 1);
    for (auto x : v) f[x % B]++;
    printf("%lld\n", poww(f, N));
    return 0;
}