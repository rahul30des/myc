#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Comparator function to sort the array by length instead of lexographic sort
struct compare
{
    bool operator()(const string& s1,const string& s2)
    {  
        return s1.length()<s2.length();
    }   
};

int longestChain(vector <string> strArr) {
    unsigned int arrSize = strArr.size();
    // Validate againt empty input or only one input
    if (arrSize <= 1) {
        return 0;
    }
    // Sort strings by length instead of lexographic sort
    sort(strArr.begin(), strArr.end(), compare());
    
    // Result array thats used to build on top of earlier computed solution
    int *dp = new int[arrSize];
    for(int i = 0; i < arrSize; i++) {
        dp[i] = 1;
    }

    int answer = dp[0];
    // Iterate over all the strings
    for(int i = 1; i < arrSize; i++) { 
        int size = strArr[i].size();
        // Iterate over all chars of current string
        for (int j = 0; j < size; j++) {
            string tmpStr = strArr[i];
            char c = tmpStr[j];
            tmpStr.erase(tmpStr.begin() + j);
            for(int k = 0; k < i; k++) {
                if(tmpStr.compare(strArr[k]) == 0) {
                    dp[i] = max (dp[i],dp[k]+1);
                }   
            }   
            tmpStr.insert(j, 1, c);
        }   
        answer = max(answer, dp[i]);
    }   

    return answer;
}

// Main Function
int main() {
    unsigned int n = 0;
    cin>>n;
    vector <string> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<longestChain(arr); 
    return 0;
}
