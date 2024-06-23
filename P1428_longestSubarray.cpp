#include <vector>
#include <set>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& vec, int limit) {
        deque<int> subarray;
        multiset<int> mset;
        int l = 0, r = 0, n = vec.size();
        int length= 0, maxLength = 0;
        for (r = 0; r < n; ++r){
            while(!subarray.empty()&&!mset.empty()){
                if(!mset.empty()){
                    if(abs(vec[r]-*mset.begin()) > limit){
                        while(subarray.front()!=*mset.begin()){
                            auto it = mset.find(subarray.front());
                            if (it != mset.end()) {
                                mset.erase(it);
                            }
                            subarray.pop_front();
                            if(subarray.empty())
                                break;
                        }
                        subarray.pop_front();
                        mset.erase(mset.begin());
                    }
                }
                if(!mset.empty()){
                    if(abs(vec[r]-*mset.rbegin()) > limit){
                        while(subarray.front()!=*mset.rbegin()){
                            auto it = mset.find(subarray.front());
                            if (it != mset.end()) {
                                mset.erase(it);
                            }
                            subarray.pop_front();
                            if(subarray.empty())
                                break;
                        }
                        subarray.pop_front();
                        auto end = mset.end();
                        --end;
                        mset.erase(end);
                    }
                }
                if(!mset.empty()){
                    if(abs(vec[r]-*mset.begin()) <= limit && abs(vec[r]-*mset.rbegin()) <= limit)
                        break;
                }
            }
            mset.insert(vec[r]);
            subarray.push_back(vec[r]);
            length = subarray.size();
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};

int main(){
    Solution S;
    vector<int> vec{2,2,2,4,4,2,5,5,5,5,5,2};
    cout << "result: " << S.longestSubarray(vec, 2) << endl;
}