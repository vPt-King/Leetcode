#include<iostream>
#include<string>
#include<unordered_map>

//Thanh solution
class Solution{
public:
    int contain(std::string str, char c){
        for(int i=0;i<str.size();i++){
            if(str[i] == c){
                return i;
            }
        }
        return -1;
    }
    int lengthOfLongestSubstring(std::string s){
        std::string str;
        int res=0;
        for(int i = 0; i < s.size();i++){
            int index=contain(str,s[i]);
            if(index != -1){
                str.erase(0,index+1);
            }
            str.push_back(s[i]);
            if(str.size() > res){
                res = str.size();
            }
        }
        return res;
    }
};
int main(){
    Solution s = Solution();
    std::string str = "aab";
    std::cout << s.lengthOfLongestSubstring(str) << std::endl;
}