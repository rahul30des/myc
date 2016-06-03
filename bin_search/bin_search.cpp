#include<iostream>
#include<vector>

using namespace std;

// Main Function
int main() {
    vector <int> arr;
    int value;
    cin>>value;
    arr = {1, 4, 5, 6, 8};
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            cout<<"Value Found"<<endl;
            return 0;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        }

    }
    cout<<"Value Not Found"<<endl;
    return 0;
}
