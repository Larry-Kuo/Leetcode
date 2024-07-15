class Solution {
public:
    int binarySearch(int l, int r, int e, vector<int> vec){
        if(l>r){
            if(e<vec[0]){
                return 0;
            }
            else if(e>vec[vec.size()-1]){
                return vec.size();
            }
            return -1;
        }
        int mid = l + (r-l)/2;
        if(vec[mid]==e){
            return mid;
        }
        else if(vec[mid]>e){
            if(mid>=1&&vec[mid-1]<e){
                return mid;
            }
            else{
                return binarySearch(l, mid-1, e, vec);
            }
        }
        else{
            return binarySearch(mid+1, r, e, vec);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, target, nums);
    }
};