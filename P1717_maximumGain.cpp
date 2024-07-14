class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string high, low;
        int hgrade = max(x, y), lgrade = min(x, y);

        if (x > y) {
            high = "ab";
            low = "ba";
        } else {
            high = "ba";
            low = "ab";
        }

        stack<char> first;
        stack<char> second;

        for (char c : s) {
            if (!first.empty() && first.top() == high[0] && c == high[1]) {
                first.pop();
                ans += hgrade;
            } else {
                first.push(c);
            }
        }

        string remaining;
        while (!first.empty()) {
            remaining += first.top();
            first.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char c : remaining) {
            if (!second.empty() && second.top() == low[0] && c == low[1]) {
                second.pop();
                ans += lgrade;
            } else {
                second.push(c);
            }
        }

        return ans;
    }
};