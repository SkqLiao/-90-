/*
 * @date:2021-05-05 09:56:51
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_c
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 5;

int N;
vector<int> E[MAXN];
int Depth[MAXN];

void dfs(int x, int fa) {
    for (auto v : E[x]) {
        if (v == fa) continue;
        Depth[v] = Depth[x] + 1;
        dfs(v, x);
    }
    return ;
}

int main() {
    scanf("%d", &N);
    for (int i = 1, x, y; i < N; ++i) {
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs(1, 0);
    int mx = 1;
    for (int i = 1; i <= N; ++i) if (Depth[i] > Depth[mx]) mx = i;
    Depth[mx] = 0;
    dfs(mx, 0);
    mx = 0;
    for (int i = 1; i <= N; ++i) mx = max(mx, Depth[i]);
    printf("%d\n", mx + 1);
    return 0;
}