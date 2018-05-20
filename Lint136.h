//
// Created by victor on 2018/5/13.
//

#ifndef LEETCODE_LINT136_H
#define LEETCODE_LINT136_H
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string &s) {
        create_Dict(s);
        vector<vector<string>> ans;
        vector<string> part;
        backtrack(s,part,ans,0);
        return ans;
    }

private:
    bool** dict;
    void backtrack(string &s, vector<string> &part, vector<vector<string>> &ans, int hd) {
        int len = s.size();
        if(hd >= len) {
            ans.push_back(part);
            return;
        }
        for(int  tl = 0 ; tl < len ; tl++) {
            if(dict[hd][tl]) {
                //backtrack
                part.push_back(s.substr(hd,tl-hd+1));
                backtrack(s, part, ans, tl+1);
                part.pop_back();
            }
        }
    }

    // dict[i][j] returns if s(i,j) is a palindrome (i < j)
    void create_Dict(string &s) {
        int length = s.size();
        dict = new bool* [length];
        for(int i = 0 ; i < length ; i++) {
            dict[i] = new bool [length];
        }
        for(int i = 0 ; i < length ; i++) {
            for (int j = i ; j < length ; j++) {
                if (s[i] == s[j] && (j - i < 2 || dict[i+1][j-1]))
                    dict[i][j] = true;
                else
                    dict[i][j] = false;
            }
        }
    }
};
#endif //LEETCODE_LINT136_H
