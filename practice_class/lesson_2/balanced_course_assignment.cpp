#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define el cout << '\n'
#define ii pair<int, int>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

const int MAX = 100;
int nTeacher, nCourse;
bool conflict[MAX][MAX];
bool prefered[MAX][MAX];
int best = MAX;
vector<int> has[MAX];

bool isConflict(int teacher, int course) {
    for (int c : has[teacher]) {
        if (conflict[c][course]) return true;
    }
    return false;
}

void backtrack(int courseIndex, int maxLoad) {
    if (courseIndex == nCourse + 1) {
        if (maxLoad < best) best = maxLoad;
        return;
    }
    int saveMaxLoad = maxLoad;
    for (int i = 1; i <= nTeacher; i++) {
        if (prefered[i][courseIndex]) {
            if (!isConflict(i, courseIndex) && (int)has[i].size() + 1 < best) {
                has[i].push_back(courseIndex);
                maxLoad = max(maxLoad, (int)has[i].size());
                backtrack(courseIndex + 1, maxLoad);
                maxLoad = saveMaxLoad;
                has[i].pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("inputs/input_1.in", "r", stdin);

    cin >> nTeacher >> nCourse;
    FOR(i, 1, nTeacher) {
        int k, c;
        cin >> k;
        FOR(j, 1, k) {
            cin >> c;
            prefered[i][c] = true;
        }
    }

    int k;
    cin >> k;
    FOR(i, 1, k) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = conflict[b][a] = true;
    }

    backtrack(1, 0);

    cout << (best == MAX ? -1 : best);
    return 0;
}
