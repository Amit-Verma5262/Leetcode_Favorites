#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool isPrime[1000];
    void seive(){
        fill(isPrime,isPrime+1000,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<1000;i++){
            if(isPrime[i]){
                for(int j=i*i;j<1000;j=j+i){
                    isPrime[j]=false;
                }
            }
        }

    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        seive();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }
            for(int j=2;j<nums[i];j++){
                if(!isPrime[j]){
                    continue;
                }

                if(nums[i]-j<nums[i+1]){
                    nums[i]-=j;
                    break;
                }
            }
            if(nums[i]>=nums[i+1]){
                return false;
            }

        }
        return true;
    }
};