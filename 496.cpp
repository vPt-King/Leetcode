#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> res2(nums2.size(), -1);
        std::vector<int> res1;
        std::stack<int> st;
        std::unordered_map<int,int> umap;
        for(int i = 0; i < nums2.size();i++){
            umap[nums2[i]] = i;
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                res2[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0 ; i < nums1.size();i++){
            if(umap.count(nums1[i])){
                res1.push_back(res2[umap[nums1[i]]]);
            }
        }
        return res1;
    }
};


int main(){
    Solution s = Solution();
    std::vector<int> v1 = {4,1,2};
    std::vector<int> v2 = {1,3,4,2};
    std::vector<int> res = s.nextGreaterElement(v1,v2);
    for(int i = 0 ;i < res.size() ; i++){
        std::cout << res[i] << " ";
    }
}