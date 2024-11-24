#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        long long sum=0;
        int cnt=0;
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);

                if(matrix[i][j]<0) cnt++;

                mini=min(mini,abs(matrix[i][j]));
            }
        }
        //if even canbe converted to positives 
        if(cnt%2==0) return sum;
        //if odd then one negative will be there and transfer it to mini
        return sum-2*mini;
    }
};