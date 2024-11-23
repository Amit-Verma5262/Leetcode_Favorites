#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>mat(n,vector<char>(m,'.'));

//placing at right position
    for(int i=0;i<m;i++){
        int k=n-1;
        for(int j=n-1;j>=0;j--){

            if(box[i][j]=='*'){
                k=j-1;
            }
            else if(box[i][j]=='#'){
                box[i][j]='.';
                box[i][k]='#';
                k--;
            }
        }
    }
//rotate by 90 degree
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[j][m-1-i]=box[i][j];
        }
    }

    return mat;
    }
};