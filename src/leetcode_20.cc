#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string p) {
        stack<char> s;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '(' || p[i] == '[' || p[i] == '{') {
                s.push(p[i]);
            } else {
                if (s.empty()) return false;
                if (p[i] == ')' && s.top() != '(') return false;
                if (p[i] == ']' && s.top() != '[') return false;
                if (p[i] == '}' && s.top() != '{') return false;
                s.pop();
            }
        }
        return s.empty();
    }
};