#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main() {
    vector <int> arr = {1, 2, 3, 4, 5, 6};
    int target = 0;
    cin>>target;

    // Time Complexity O(n2)
    // Space Complexity O(1)
    for (int i = 0; i < arr.size() - 2; i++) {
        int j = i + 1;
        int k = arr.size() - 1;
        while(j < k) {
            if(arr[j] == arr[j - 1]) {
                j++;
                continue;
            }
            if(arr[k] == arr[k - 1]) {
                k--;
                continue;
            }
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == target) {
                cout<<arr[i]<<" , "<<arr[j]<<" , "<<arr[k]<<endl;
                j++;
                k--;
            } else if (sum < target) {
                j++;
            } else if (sum > target) {
                k--;
            }
        }
    }
    return 0;
}

