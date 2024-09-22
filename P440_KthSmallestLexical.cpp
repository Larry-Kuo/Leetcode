class Solution {
public:
    int count(int n, long long curr) {
        long long sum = 0;
        long long next = curr + 1;
        while(curr <= n) {
            sum += min(n - curr + 1, next - curr);
            curr *= 10;
            next *= 10;
        }
        return sum;
    } 
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while(k > 0) {
            long long sum = count(n, curr);
            if(sum <= k) {
                k -= sum;
                // Move to the next subtree
                curr += 1;
            }
            else {
                // Move down the subtree
                curr *= 10;
                k --;
            }
        }
        return (int)curr;
    }
};