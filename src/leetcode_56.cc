#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {return a.start < b.start;});
        vector<Interval> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (i == 0) {res.emplace_back(intervals[i]);continue;}
            if (intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.emplace_back(intervals[i]);
            }
        }
        return res;
    }
};