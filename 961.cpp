#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        std::unordered_map<int,int> umap;
        int res = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(umap.count(nums[i])) {
                res = nums[i];
                break;
            }
            else {
                umap.insert({nums[i],1});
            }
        }
        return res;
    }
};