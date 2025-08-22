#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0;
        int p2 = 0;
        std::vector<int> res;
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] == nums2[p2]){
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            } else if (nums1[p1] < nums2[p2]){
                p1++;
            } else {
                p2++;
            }
        }
        return res;
    }
};