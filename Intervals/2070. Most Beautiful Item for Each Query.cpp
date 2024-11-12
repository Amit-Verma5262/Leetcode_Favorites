#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bSearch(vector<vector<int>>& items, int query){
        int maxb=0;
        int l=0;
        int r=items.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(items[mid][0]<=query){
                l=mid+1;
                maxb=max(maxb,items[mid][1]);
            }
            else{
                r=mid-1;
            }
        }
        return maxb;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n=items.size();
        int m=queries.size();
        vector<int> ans(m);

        //sorting wrt prices
        sort(items.begin(),items.end());

        //Updating maximum lastseen beauty
        int maxbeauty=items[0][1];
        for(int i=1;i<n;i++){
            maxbeauty=max(maxbeauty,items[i][1]);
            items[i][1]=maxbeauty;
        }
    
        for(int i=0;i<m;i++){
            int query=queries[i];
            ans[i] = bSearch(items,query);
        }
        return ans;
    }
};