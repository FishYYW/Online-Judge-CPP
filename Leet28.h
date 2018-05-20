//
// Created by victor on 2018/5/13.
//

#ifndef LEETCODE_LEET28_H
#define LEETCODE_LEET28_H
#include <string>

#define MAX 999999
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        calculate_lps(needle);
        int haystack_len = haystack.size(); int j = 0;
        int needle_len = needle.size(); int i = 0;
        while(j < haystack_len && i < needle_len) {
            if(needle[i] == haystack[j]) {
                i++; j++;
            }
            else {
                if(i == 0)
                    j++;
                else {
                    i = lps[i-1];
                }
            }
        }
        if(i == needle_len)
            return j-i;
        return -1;
    }
private:
    int lps[MAX]; //longest proper prefix, the string ends with i
    // KMP preprocess
    void calculate_lps(string s) {
        int i = 0;
        int len = 0;
        lps[i] = 0;
        i++;
        int S = s.size();
        while(i < S) {
            if(s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len == 0) {
                    lps[i] = 0;
                    i++;
                }
                else {
                    len = lps[len-1]; //tricky one
                }
            }
        }
    }
};
#endif //LEETCODE_LEET28_H
