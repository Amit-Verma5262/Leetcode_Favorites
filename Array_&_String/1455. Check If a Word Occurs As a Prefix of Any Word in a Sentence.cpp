#include <biuts/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.size();

        stringstream ss(sentence);
        string word;
        int cnt=0;
        while(ss>>word){
            cnt++;
            int k=word.size();
            if(k<n) continue;
            else{
                string part=word.substr(0,n);
                if(part==searchWord){
                    return cnt;
                }
            }
        }
        return -1;
    }
};