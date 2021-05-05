/*
 * @date:2021-05-05 11:42:53
 * @source:https://atcoder.jp/contests/typical90/tasks/typical90_f
*/
#include <bits/stdc++.h>

using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;
    int cur = K, mn = 0;
    for (int i = 0; i < N; ++i) {
        if (N - i < cur) {
            cout << S[mn];
            i = mn;
            mn = i + 1;
            --cur;
        } else if (S[mn] > S[i]) mn = i;
    }
    cout << S[mn] << endl;
    return 0;
}