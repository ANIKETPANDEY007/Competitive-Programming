#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    private:
    int timer;
    vector<int> tin, low;
    vector<bool> is_articulation;
    vector<vector<int>> adj;

    void dfs(int u, int p = -1) {
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && p != -1) {
                    is_articulation[u] = true;
                }
                ++children;
            }
        }
        if (p == -1 && children > 1) {
            is_articulation[u] = true;
        }
    }

public:
    vector<int> solution(int n, string s2, string s3, string s4, string s5, string s6, string s7, string s8, string s9, string s10) {
        adj.assign(n, vector<int>());
        vector<string> strings = {s2, s3, s4, s5, s6, s7, s8, s9, s10};
        
        int row = 0;
        for (const string& s : strings) {
            int col = 0;
            for (char c : s) {
                if (c == '0' || c == '1') {
                    if (row < n && col < n && c == '1') {
                        adj[row].push_back(col);
                    }
                    col++;
                }
            }
            row++;
        }

        tin.assign(n, -1);
        low.assign(n, -1);
        is_articulation.assign(n, false);
        timer = 0;

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i);
            }
        }

        set<int> type_b;
        for (int u = 0; u < n; u++) {
            if (is_articulation[u]) {
                for (int v : adj[u]) {
                    if (!is_articulation[v]) {
                        type_b.insert(v);
                    }
                }
            }
        }

        vector<int> result(type_b.begin(), type_b.end());
        sort(result.begin(), result.end());
        return result;
    }
}

