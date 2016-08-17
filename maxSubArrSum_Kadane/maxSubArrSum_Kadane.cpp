#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getMaxSubArr(vector <int> arr) {
    int curr_max = INT_MIN;
    int max_so_far = INT_MIN;
    
    // T O(n)
    // All -ves or 0s
    for(int i = 0; i < arr.size(); i++) {
        max_so_far  = max(max_so_far, arr[i]);
    }    

    // T O(n)
    if(max_so_far > 0) {
        // Else Fall through for regular case
        curr_max = 0;
        max_so_far = 0;
        for(int i = 0; i < arr.size(); i++) {
            curr_max += arr[i];
            curr_max = max(curr_max, 0);
            max_so_far = max(max_so_far, curr_max);
        }
    }
    return max_so_far;
}

// Main Function
int main() {
    vector<int> arr = {3, -2, 5, -1};
    cout<<getMaxSubArr(arr);
    return 0;
}

