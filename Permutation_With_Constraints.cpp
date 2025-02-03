#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void permu(int n, int len, vector<int> &sols, vector<bool> &used, vector<pair<int, int>> &cond) {
    if (len == n) {
        for (auto &e : sols) {
            cout << e << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            bool valid = true;
            for (auto &e : cond) {
                int x = e.first, y = e.second;
                auto it_x = find(sols.begin(), sols.begin() + len, x);
                auto it_y = find(sols.begin(), sols.begin() + len, y);
                if (it_y != sols.begin() + len && it_x == sols.begin() + len) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                used[i] = true;
                sols[len] = i;
                permu(n, len + 1, sols, used, cond);
                used[i] = false;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> sols(n);
    vector<pair<int, int>> conditions;
    vector<bool> used(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        conditions.push_back({x, y});
    }

    permu(n, 0, sols, used, conditions);

    return 0;
}