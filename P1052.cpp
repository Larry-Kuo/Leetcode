class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxUnsatisfied = 0; 
        int unsatisfied = 0;
        int satisfied = 0; // Naturally satisfied customers
        for(int i=0; i<customers.size(); ++i){
            satisfied += customers[i] * (!grumpy[i]);
            unsatisfied += customers[i] * grumpy[i];
            if(i>=minutes){
                unsatisfied -= customers[i - minutes] * grumpy[i - minutes];
            }
            maxUnsatisfied = max(unsatisfied, maxUnsatisfied);
        }
        return satisfied+maxUnsatisfied;
    }
};