#include "vector"

using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int cnt = 0;
        vector<int> roots(m*n, -1);
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& a: positions) {
            int id = n * a.first + a.second;
            if (roots[id] == -1) {
                roots[id] = id;
                cnt++;
            }
            for (const auto& dir: dirs) {
                int x = a.first + dir[0], y = a.second + dir[1], cur = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur] == -1) continue;
                int p = findRoots(roots, cur), q = findRoots(roots, id);
                if (p != q) {
                    roots[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    int findRoots(vector<int>& roots, int id) {
        return (roots[id] == id)? id: findRoots(roots, roots[id]);
    }
};