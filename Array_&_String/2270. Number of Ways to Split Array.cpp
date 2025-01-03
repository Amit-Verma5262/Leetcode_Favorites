#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        long long leftsum=0;
        long long rightsum=0;
        int cnt=0;

        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            rightsum=sum-leftsum;

            if(leftsum>=rightsum){
                cnt++;
            }
        }
        return cnt;
    }
};