#include<iostream>
#include<array>

using namespace std;

// Main Function
int main()  {
    array<int, 6> arr = {1, 2, 3, 4, 5, 6}; 
    int three_sum = INT_MIN;
    cin>>three_sum;

    // Assumption of a sorted array - O(nlogn) using introscpective sort 
    // Time Complexity O(n2)
    for(int i = 0; i < arr.size(); i++) {
        int j = i + 1;
        int k = arr.size() - 1;
        while(j < k) {
            if(arr[j]  == arr[j-1]) {
                j++;
                continue;
            }
            if (arr[k] == arr[k-1]) {
                k--;
                continue;
            }
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == three_sum) {
                cout<<arr[i]<<" , "<<arr[j]<<" , "<<arr[k]<<endl;
                j++;
                k--;
            } else if (sum < three_sum) {
                j++;
            } else if (sum > three_sum) {
                k--;
            }
        }
    }

   return 0;
}
