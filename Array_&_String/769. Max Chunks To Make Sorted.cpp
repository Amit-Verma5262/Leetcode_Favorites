#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> premax(n);
        vector<int>postmin(n);
        int maxi=INT_MIN;
        int mini=INT_MAX;

        premax[0]=arr[0];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],arr[i]);
        }

        postmin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            postmin[i]=min(postmin[i+1],arr[i]);
        }
        int chunks=0;

        for(int i=0;i<n-1;i++){
            if(premax[i]<=postmin[i+1]){
                chunks++;
            }
        }

        return chunks+1;
    }
};