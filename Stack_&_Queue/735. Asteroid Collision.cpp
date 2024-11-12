#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &arr) {
        stack<int> st;
        int N=arr.size();
        for(int i=0;i<N;i++){
            if(arr[i]>0){
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(arr[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && st.top()==abs(arr[i])){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(arr[i]);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
