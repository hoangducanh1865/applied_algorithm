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


int n, m;
int ans = 0;
int a[maxn][maxn], h[maxn];
int rmq[maxn][maxn];


void buildRMQ() {
    FOR(i, 1, m) rmq[i][0] = i;

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            int lIdx = rmq[i][j - 1];
            int rIdx = rmq[i + (1 << (j - 1))][j - 1];
            rmq[i][j] = (h[lIdx] < h[rIdx] ? lIdx : rIdx);
        }
    }
}


int queryMinIdx(int l, int r) {
    int k = log2(r - l + 1);
    int minLeftIdx = rmq[l][k];
    int minRightIdx = rmq[r - (1 << k) + 1][k];
    return (h[minLeftIdx] < h[minRightIdx] ? minLeftIdx : minRightIdx);
}


int getMaxArea(int l, int r) {
    if(l > r) return 0;

    int minIdx = queryMinIdx(l, r);
    int fullArea = h[minIdx] * (r - l + 1);
    int lArea = getMaxArea(l, minIdx - 1);
    int rArea = getMaxArea(minIdx + 1, r);

    return max({fullArea, lArea, rArea});
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input_4.in", "r", stdin);

    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if(a[i][j] == 1) h[j]++;
            else h[j] = 0;
        }
        buildRMQ();
        ans = max(ans, getMaxArea(1, m));
    }

    cout << ans;
    return 0;
}
