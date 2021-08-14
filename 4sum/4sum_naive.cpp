// O(n3) Time Complexiy, Space Complexity O(1) except for tracking the output O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector <vector<int>> out;
        vector <int> outv;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 3; i++) {
            for(int j = i + 1; j < size - 2; j++) {
                int l = j + 1;
                int r = size - 1;
                
                while(l < r) {
                    long total = nums[i] + nums[j] + nums[l] + nums[r];
                    if(total == target) {
                        outv.push_back(nums[i]);
                        outv.push_back(nums[j]);
                        outv.push_back(nums[l]);
                        outv.push_back(nums[r]);                    
                        bool exists = false;
                        for(auto it = out.begin(); it != out.end(); it++) {
                            if((*it) == outv) {
                                l++;
                                r--;
                                exists = true;
                                break;
                            }
                        }
                        if (exists == false) {
                            out.push_back(outv);     
                            l++;
                            r--;
                        }
                        outv.clear();
                    } else if (total < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return out;
    }
};
