#include<iostream>
#include<vector>
#include<stack>
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(nums.size(), -1);
        std::stack<int> st;
        for(int i = 2*n - 1; i >= 0 ;i--){
            while(!st.empty() && nums[i%n] >= nums[st.top()]){
                st.pop();
            }
            res[i%n] = st.empty() ? -1 : nums[st.top()];
            st.push(i%n);
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();
    std::vector<int> arr = {1,2,3,4,3};
    std::vector<int> ans = s.nextGreaterElements(arr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
}