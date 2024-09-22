class Solution {
public:
    unordered_map<string, vector<int>> M;
    
    int op(int x, int y, char op) {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            default: return 0;
        }
    }
    
    vector<int> diffWaysToCompute(string expression) {
        if (M.find(expression) != M.end()) {
            return M[expression];
        } 

        vector<int> ans;
        bool isNumber = true;
        for (char c : expression) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        
        if (isNumber) {
            return {stoi(expression)};
        }

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (!isdigit(c)) {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        ans.push_back(op(l, r, c));
                    }
                }
            }
        }

        M[expression] = ans;
        return ans;
    }
};
