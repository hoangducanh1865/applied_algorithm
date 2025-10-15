#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define el cout << '\n'
#define ii pair<int, int>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

int n, M;
int a[55];
ll result = 0;

void backtrack(int i, int total) {
    if (i == n + 1) {
        if (total == M) result++;
        return;
    }
    int x = 1;
    while (total + x * a[i] <= M) {
        backtrack(i + 1, total + x * a[i]);
        x++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("inputs/input_3.in", "r", stdin);

    if (!(cin >> n >> M)) return 0;
    FOR(i, 1, n) cin >> a[i];
    backtrack(1, 0);
    cout << result;
    return 0;
}
