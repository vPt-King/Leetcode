#include<iostream>
class Solution{
public:
    bool check(int n){
        if (n%2 != 0 && n%3 != 0 && n%5 != 0 && n != 1) return false;
        return true;
    }
    bool isUgly(int n){
        if(n == 1 ) return true;
        if (n <= 0) return false;
        else {
            while(n % 2 == 0){
                n /= 2;
                if(!check(n)) return false;
            }
            while(n % 3 == 0){
                n /= 3;
                if(!check(n)) return false;
            }
            while(n % 5 == 0) {
                n /= 5;
                if(!check(n)) return false;
            }
            if(n != 1) return false;
            else return true;
        }
    }
};
