#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int solve(vector<int>& nums,int i,int currsum, int target,unordered_map<string,int> &mp){
        n=nums.size();
        if(i>=n){
            if(currsum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        string key=to_string(i)+"_" +to_string(currsum);
        if(mp.count(key)){
            return mp[key];
        }
        
        int posi=solve(nums,i+1,currsum+nums[i],target,mp);
        int neg=solve(nums,i+1,currsum-nums[i],target,mp);

        return mp[key]=posi+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return solve(nums,0,0,target,mp);
    }
};