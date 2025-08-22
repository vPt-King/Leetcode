#include<iostream>
#include<string>
#include<stack>
class Solution{
public:
    std::string reverseVowels(std::string s){
        std::stack<char> st;
        for(size_t i = 0; i < s.size();i++){
            if(s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'a' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'A' ){
                st.push(s[i]);
            }
        }
        std::string res = "";
        for(size_t i = 0; i < s.size();i++){
            if(s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'a' || s[i] == 'I' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'A' ){
                res.push_back(st.top());
                st.pop();
            }
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};