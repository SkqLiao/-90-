/*
 * @date:2021-05-05 12:08:36
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_h
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
char s[MAXN], *t = "atcoder";
int F[10];

int main() {
    scanf("%d%s", &N, s);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (s[i] == t[j]) {
                if (j) F[j] = (F[j] + F[j - 1]) % MOD;
                else F[j]++;
            }
        }
    }
    printf("%d\n", F[6]);
    return 0;
}