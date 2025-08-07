#include<iostream>
#include<vector>
#include<stack>
class Solution{
public:
    std::vector<int> make_vec(int n){
        std::vector<int> vec;
        std::stack<int> st;
        while(n > 0){
            st.push(n%10);
            n/=10;
        }
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
    int nextGreaterElement(int n){
        std::vector<int> vec = make_vec(n);
        
    }
}