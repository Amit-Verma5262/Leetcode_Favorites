#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   int maxsum=INT_MIN;
   int cursum=0;
   for(int i=0;i<nums.size();i++){
        cursum+=nums[i];
        if(cursum>maxsum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
   }
   return maxsum;
   }
};