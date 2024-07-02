class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> mset1 (nums1.begin(), nums1.end());
        multiset<int> mset2 (nums2.begin(), nums2.end());
        auto it1 = mset1.begin();
        auto it2 = mset2.begin();
        vector<int> ans;   
        while (it1 != mset1.end() && it2 != mset2.end()) {
            if (*it1 == *it2) {
                ans.push_back(*it1);
                ++it1;
                ++it2;
            } else if (*it1 < *it2) {
                ++it1;
            } else {
                ++it2;
            }
        }

        return ans;
    }
};