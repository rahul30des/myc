#include<iostream>
#include<string>

using namespace std;

// XOR swap 2 elements
void swap(char *str1, char *str2) {
    *str1 = *str1 ^ *str2;
    *str2 = *str1 ^ *str2;
    *str1 = *str1 ^ *str2;
}

// String Permutation - Time Complexity O(n * n!)
void permute_string(string &str, int low, int high) {
    if(low == high) {
        cout<<"\t"<<str;
    } else {
        for(int i = low; i <= high; i++) {
            swap(str[low], str[i]);
            permute_string(str, low + 1, high);
            swap(str[i], str[low]);
        }
    }
}

// Main Function
int main() {
    string str;
    cin>>str;

    permute_string(str, 0, str.size() - 1);
    return 0;
}
