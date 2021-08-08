#include<iostream>
#include<array>

using namespace std;

int main() {
    array<int,5> arr = {1, 3, 5, 7, 9};
    // Assumption of a sorted array - Intro Sort costs O(nlogn) in the worst case and O(n) in the best case
    // IntroSelect could also be assumed for O(n) worst case performance
    
    int search_term = -1;
    cin>>search_term;

    int low_idx = 0;
    int high_idx = arr.size() - 1;

    // Time Complexity O(log(n))
    while(low_idx <= high_idx) {
        int mid_idx = (low_idx + high_idx)/2;
        if(arr[mid_idx] == search_term) {
            cout<<endl<<"Search Term found"<<endl;
            return 0;
        } else if(arr[mid_idx] < search_term) {
            low_idx = mid_idx + 1;
        } else if(arr[mid_idx] > search_term) {
            high_idx = mid_idx - 1;
        }
    }
    cout<<endl<<"Search Term not found"<<endl;
    return 0;
}
