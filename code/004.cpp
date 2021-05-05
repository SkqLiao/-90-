/*
 * @date:2021-05-05 10:29:09
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_d
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 5;

int N, M;
int A[MAXN][MAXN], C[MAXN], R[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &A[i][j]);
            R[i] += A[i][j];
            C[j] += A[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            printf("%d ", C[j] + R[i] - A[i][j]);
        }
        puts("");
    }
    return 0;
}