#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define P pair<int,int>
    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(k--){
            int num=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            num*=multiplier;
            pq.push({num,idx});
        }

        while(!pq.empty()){
            int num=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            nums[idx]=num;
        }
        return nums;
    }
};