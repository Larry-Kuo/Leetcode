class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> ugly(n);
        ugly[0] = 1;
        for(int i = 1; i < n; ++i){
            int next = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            if(next == ugly[i2] * 2) i2++;
            if(next == ugly[i3] * 3) i3++;
            if(next == ugly[i5] * 5) i5++;
            ugly[i] = next;
        }
        return ugly[n - 1];
    }
};