#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define el cout << '\n'
#define ii pair<int, int>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

#define MAX 30
#define INF int(2e9)

int n, k, d[MAX][MAX];
bool checked[MAX];
int min_dist = INF;
int res = INF;

int get_best_secenario(int pos, vector<int> cur, int remain, int total) {
    total += (int)cur.size() * min_dist;
    remain -= (int)cur.size();
    total += remain * 2 * min_dist;
    total += min_dist;
    return total;
}

void backtrack(int pos, vector<int> cur, int remain, int total) {
    if (remain == 0) {
        if (total + d[pos][0] < res) res = total + d[pos][0];
        return;
    }
    for (int i = 1; i <= 2 * n; i++) {
        vector<int> save_cur = cur;
        bool checkout = false, checkin = false;
        int save_total = total;
        total += d[pos][i];
        if (i <= n) {
            if (!checked[i] && (int)cur.size() < k) {
                cur.push_back(i);
                checkin = true;
                checked[i] = true;
            }
        } else {
            auto it = find(cur.begin(), cur.end(), i - n);
            if (it != cur.end()) {
                checkout = true;
                cur.erase(it);
                remain -= 1;
            }
        }
        if (checkout || checkin)
            if (get_best_secenario(i, cur, remain, total) < res)
                backtrack(i, cur, remain, total);
        cur = save_cur;
        if (checkout) remain += 1;
        if (checkin) checked[i] = false;
        total = save_total;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("inputs/input_2.in", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++) {
            cin >> d[i][j];
            if (i != j) min_dist = min(min_dist, d[i][j]);
        }
    vector<int> v;
    backtrack(0, v, n, 0);
    cout << res;
}
