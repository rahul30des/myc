#include<iostream>
#include<unordered_map>
#include<array>

using namespace std;

// Main Function
int main() {
    array <int, 9> arr = {1, 1, 2, 2, 4, 5, 3, 6, 6};
    // HashMap key would be diff, value to hold the frequency of the (possibly) repeated keys
    unordered_map<int, int> hmap;
    int sum = INT_MIN;
    cout<<"Enter sum to check for : ";
    cin>>sum;

    for(int i = 0; i < arr.size(); i++) {
        int diff = sum - arr[i];
        if(hmap.find(arr[i]) != hmap.end()) {
            cout<<endl<<"Found pair ("<<arr[i]<<" , "<<diff<<")"<<" for target "<<sum<<endl;
            if (hmap[arr[i]] == 1) {
                hmap.erase(arr[i]);
            } else {
                hmap[arr[i]]--;
            }
        } else {
            if(hmap.find(diff) != hmap.end()) {
                hmap[diff]++;
            } else {
                hmap[diff] = 1;
            }
        }
    }

    return 0;
}
