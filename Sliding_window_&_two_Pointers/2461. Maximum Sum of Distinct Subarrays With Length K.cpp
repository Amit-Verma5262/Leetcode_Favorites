#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long arrsum=0;
        long long maxi=0;

        int l=0;
        int r=0;
        unordered_set<int> st;

        while(r<n){
            //erasing duplicates
            while(st.count(nums[r])){
                arrsum-=nums[l];
                st.erase(nums[l]);
                l++;
            }

            arrsum+=nums[r];
            st.insert(nums[r]);

            //checking window size and updating ans
            if(r-l+1==k){
                maxi=max(maxi,arrsum);
                arrsum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return maxi;
    }
};