#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define el cout << '\n'
#define ii pair<int, int>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define maxn 1005


queue<ii> q;
int n, m, r, c;
int a[maxn][maxn], dist[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input_3.in", "r", stdin);

    cin >> n >> m >> r >> c;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    q.push({r, c});
    dist[r][c] = 0;
    a[r][c] = 1;

    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        FOR(i, 0, 3) {
            int x = u.fi + dx[i];
            int y = u.se + dy[i];
            if(x == 0 || y == 0 || x == n + 1 || y == m + 1) {
                cout << dist[u.fi][u.se] + 1;
                return 0;
            }
            if(a[x][y] == 0) {
                dist[x][y] = dist[u.fi][u.se] + 1;
                a[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    cout << -1;
    return 0;
}
