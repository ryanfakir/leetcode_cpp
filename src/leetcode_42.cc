#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, res = 0;
        while (l < r) {
            int low = height[height[l]< height[r] ? l++: r--];
            level = max(level, low);
            res += level - low;
        }
        return res;
    }
};