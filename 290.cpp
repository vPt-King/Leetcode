#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
#include<vector>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        std::unordered_map<char,std::string> ps;
        std::unordered_map<std::string , char> sp;
        while(ss >> word){
            words.push_back(word);
        }
        if(words.size() != pattern.size()) return false;

        for(std::size_t i = 0 ; i < pattern.size();i++){
            if(ps.count(pattern[i])){
                if(ps.at(pattern[i]) != words[i]) return false;
            } else {
                ps.insert({pattern[i], words[i]});
            }

            if(sp.count(words[i])){
                if(sp.at(words[i]) != pattern[i]) return false; 
            } else {
                sp.insert({words[i] , pattern[i]});
            }
        }
        return true;
    }
};
int main(){
    Solution s = Solution();
    std::string pattern = "abba";
    std::string e = "dog cat cat fish";
    std::cout << s.wordPattern(pattern, e); 
}