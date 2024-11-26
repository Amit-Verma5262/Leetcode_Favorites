#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string str="";

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                str=str+to_string(board[i][j]);
            }
        }
        map<int ,vector<int>> mpp;

        mpp[0]={1,3};
        mpp[1]={0,2,4};
        mpp[2]={1,5};
        mpp[3]={0,4};
        mpp[4]={1,3,5};
        mpp[5]={2,4};

        int mini=INT_MAX;
        queue<pair<string,int>> q;
        set<string> vis;

        q.push(make_pair(str,0));
        vis.insert(str);

        while(!q.empty()){
            string curr= q.front().first;
            int moves=q.front().second;
            q.pop();

            if(curr==target){
                return moves;
            }

            int idx=-1;
            for(int i=0;i<6;i++){
                if(curr[i]=='0'){
                    idx=i;
                }
            }

            vector<int> swapidx=mpp[idx];

            for(auto it:swapidx){
                string next=curr;
                swap(next[idx],next[it]);

                if(vis.find(next)==vis.end()){
                    q.push({next,moves+1});
                    vis.insert(next);
                }
            }
        }

        return -1;
    }
};