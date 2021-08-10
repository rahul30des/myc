#include<iostream>
#include<array>

using namespace std;

// Main Function
int main() {
    array <int, 8> arr = {1, 1, 2, 2, 4, 5 ,3, 6};
    int sum = INT_MIN;
    cout<<"Enter the sum to check for : "<<endl;
    cin>>sum;
    
    // Sort the array in O(nlogn) using Introspective Sort
    // Another alternative is to use the IntroSelect algorithm 

    sort(arr.begin(), arr.end());
    // Loops over for O(n) with the head and tail ptr moving right and left
    // Overall Time Complexity of the Solution - O(nlogn)
    for(int i = 0, j = arr.size() - 1; i < j;) {
       int local_sum = arr[i] + arr[j];
       if(local_sum == sum) { 
           cout<<endl<<arr[i]<<" , "<<arr[j]<<endl; 
           i++;
           j--;
           continue;
       } else if (local_sum < sum) {
          i++;
          continue;
       } else if (local_sum > sum) {
          j--;
          continue;
       }
    }
    
    return 0;
}

