class Solution {
public:
    void merge(vector<int> &vec, int l, int mid, int r){
        if(l >= r){
            return;
        }
        int len = r - l + 1;
        vector<int> tmp (len, -1);
        int i = l;
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= r){
            if(vec[i] < vec[j]){
                tmp[k++] = vec[i++];
            }
            else{
                tmp[k++] = vec[j++];
            }
        }
        while(i <= mid){
            tmp[k++] = vec[i++];
        }
        while(j <= r){
            tmp[k++] = vec[j++];
        }
        for(k = 0; k < len; k++){
            vec[k + l] = tmp[k];
        }

    }
    void mergeSort(vector<int> &vec, int l, int r){
        if(l >=r){
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid+1, r);
        merge(vec, l, mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        mergeSort(nums, l, r);
        return nums;
    }
};