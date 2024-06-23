#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int l, int r, int e, vector<int> &vec){
    cout << l <<" " << r << endl;
    if(l>r)
        return -1;
    int mid = l + (r - 1) / 2;
    if(vec[mid] == e)
        return mid;
    else if(vec[mid] > e)
        return binarySearch(l, mid - 1 , e, vec);
    else
        return binarySearch(mid + 1, r, e, vec);
}
int main(int argc, char *argv[]){
    int e = stoi(argv[1]);
    vector<int> vec = {1, 3, 4, 5, 6, 8, 9, 10, 14, 16, 18, 49};
    cout << "Binary Search result: " << to_string(binarySearch(0, vec.size()-1, e, vec)) << endl;
}