#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::string str="";
        for(size_t i = 0; i < s.size();i++){
            if(str.empty()) str.push_back(s[i]);
            else if(str.back() == s[i]){
                str.pop_back();
            } else if(str.back() != s[i]) str.push_back(s[i]);
        }
        return str;
    }
};