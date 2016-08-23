#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// Main Function
int main() {
    unordered_map <int, int> hmap;
    vector <int> arr = {1, 1, 2, 2, 4, 5, 3, 6, 6};
    int target = 0;
    cin>>target;
/*
// Time Complexity O(n)
// Space Complexity O(n)
    for(int i = 0; i < arr.size(); i++) {
        int diff = target - arr[i];
        // Below handle valuye being 0 by hmap.count(arr[i]) to verify existence of key
        if(hmap[arr[i]]) { 
            cout<<arr[i]<<" , "<<hmap[arr[i]]<<endl;
            hamp.erase(arr[i]);
        } else {
            hmap[diff] = arr[i];
        }
    }
*/
    // Sort in O(nlogn) and then iterate from both sides in O(n)
    // Time Complexity O(nlogn)
    // Space Complexity O(1)
    sort(arr.begin(), arr.end());
    for(int i = 0, j = arr.size() - 1; i < j; ) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            cout<<arr[i]<<" , "<<arr[j]<<endl;
            i++;
            j--;
        } else if (sum < target) {
            i++;    
        } else if (sum > target) {
            j--;
        }
    }
    return 0;
}

