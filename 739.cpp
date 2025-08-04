#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
// struct TempInfo
// {
//     int temp;
//     int index;
// };

// class Solution
// {
// public:
//     std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
//     {
//         int count = temperatures.size() - 1;
//         std::vector<int> ans;
//         std::stack<TempInfo> st;
//         for (int i = temperatures.size() - 1; i >= 0; i--)
//         {

//             while (!st.empty() && temperatures[i] >= st.top().temp)
//             {
//                 st.pop();
//             }
//             if (st.empty())
//             {
//                 TempInfo t = {temperatures[i], i};
//                 st.push(t);
//                 ans.push_back(0);
//             }
//             else
//             {
//                 TempInfo t = {temperatures[i], i};
//                 ans.push_back(st.top().index - i);
//                 st.push(t);
//             }
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temps) {
        std::vector<int> res;
        std::stack<int> st;
        for(int i = 0; i < temps.size();i++){
            while(!st.empty() && temps[st.top()] < temps[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();
    std::vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> ans = s.dailyTemperatures(arr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << std::endl;
    }
}