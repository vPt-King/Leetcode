#include<iostream>
#include<vector>
#include <cmath>
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < k;i++){
            res += nums[i];
        }    
        int sum = res;
        int l = 0;
        int r = l+k-1;
        while(r < nums.size()){
            if(l != 0){
                sum -= nums[l-1];
                sum += nums[r];
            }
            if(sum > res){
                res = sum;
            }
            l++;
            r++;
        }
        std::cout << res << std::endl;
        double y = std::round(((double)res/k) * 100000.0) / 100000.0;
        return y;
    }
};
int main(){
    Solution a = Solution();
    std::vector<int> k = {1,12,-5,-6,50,3};
    std::cout << a.findMaxAverage(k,4);
}