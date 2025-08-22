#include<iostream>
class Solution{
public:
    int firstBadVersion(int n){
        int left = 1 ;
        int right = n;
        int res = 0;
        while(l<=r){
            int mid = (left+right)/2;
            if(isBadVersion(mid)){
                right = mid - 1;
                res = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};