#include<iostream>
#include<vector>
#include<iomanip>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i=0,j=0;
        std::vector<int> vec;
        while(i < size1 && j < size2){
            if(nums1[i] <= nums2[j]){
                vec.push_back(nums1[i]);
                i++;
            }else{
                vec.push_back(nums2[j]);
                j++;
            }
        }
        while(i < size1){
            vec.push_back(nums1[i]);
            i++;
        }
        while(j < size2){
            vec.push_back(nums2[j]);
            j++;
        }
        if(vec.size() % 2 != 0){
            return vec[vec.size()/2];
        } else {
            int sec = vec.size() / 2;
            int fir = sec - 1;
            double res = (vec[sec] + vec[fir])/(double)2;
            return res;
        }
    }
};

int main(){
    Solution s = Solution();
    std::vector<int> vec1 = {1,2};
    std::vector<int> vec2 = {3,4};
    double x = s.findMedianSortedArrays(vec1,vec2);
    printf("%.5f\n", x);
}