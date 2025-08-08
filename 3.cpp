#include<iostream>
#include<string>
#include<unordered_set>
//Thanh solution
// class Solution{
// public:
//     int contain(std::string str, char c){
//         for(int i=0;i<str.size();i++){
//             if(str[i] == c){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     int lengthOfLongestSubstring(std::string s){
//         std::string str;
//         int res=0;
//         for(int i = 0; i < s.size();i++){
//             int index=contain(str,s[i]);
//             if(index != -1){
//                 str.erase(0,index+1);
//             }
//             str.push_back(s[i]);
//             if(str.size() > res){
//                 res = str.size();
//             }
//         }
//         return res;
//     }
// };


class Solution{
public:
    int lengthOfLongestSubstring(std::string s){
        std::unordered_set<char> st;
        int left = 0 , res=0;
        for(int right = 0; right < s.size();right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            if(st.size() > res) res = st.size();
        }
        return res;
    }
};
int main(){
    Solution s = Solution();
    std::string str = "aab";
    //std::cout << s.lengthOfLongestSubstring(str) << std::endl;

    std::unordered_set<int> us = {8,6,7,1};
    for(auto x:us){
        std::cout<< x << std::endl;
    }
}