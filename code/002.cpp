/*
 * @date:2021-05-04 23:36:01
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_b
*/
#include <bits/stdc++.h>

using namespace std;

int N;
char s[105];

void dfs(int x, int num) {
    if (x == N) {
        if (num) return ;
        printf("%s\n", s);
        return ;
    }
    s[x] = '(';
    dfs(x + 1, num + 1);
    if (num) {
        s[x] = ')';
        dfs(x + 1, num - 1);
    }
}

int main() {
    scanf("%d", &N);
    if (N & 1) return 0;
    dfs(0, 0);
    return 0;
}