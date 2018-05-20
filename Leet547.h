//
// Created by victor on 27/04/2018.
//

#ifndef LEETCODE_PROBLEM547_H
#define LEETCODE_PROBLEM547_H
#include <vector>
#include <queue>
using namespace std;
//bfs
class Solution {
public:
    int findCircleNum (vector<vector<int>> &M) {
        int count = 0;

        for (int i = 0 ; i < M.size() ; i++) {
            if (flag[i] == 0) {
                flag[i] = 1;
                bfs(i,M);
                count++;
            }
        }
        return count;
    }

private:
    int flag[201];
    queue<int> vec;
    void bfs (int v,vector<vector<int>> &M) {
        vec.push(v);
        while (!vec.empty()) {
            int k = vec.front();
            vec.pop();
            for (int i = 0; i < M.size(); i++) {
                if (M[i][k] == 1 && flag[i] == 0) {
                    flag[i] = 1;
                    vec.push(i);
                }
            }
        }
    }
};
/*dfs
class Solution {
public:
    int findCircleNum (vector<vector<int>> &M) {
        int count = 0;
        unsigned long int m = M.size();
        if (m == 0) return 0;
        init();
        for (int i = 0 ; i < m ; i++) {
            if (flag[i] == 0) {
                dfs(i,M);
                flag[i] = 1;
                count++;
            }
        }
        return count;
    }
private:
    int flag[201];
    void init () {
        for (int i = 0 ; i < 201 ; i++)
            flag[i] = 0;
    }
    void dfs (int j,vector<vector<int>> &M) {
        for (int i = 0 ; i < M.size() ; i++) {
            if(M[i][j] == 1 && flag[i] == 0) {
                flag[i] = 1;
                dfs(i,M);
            }
        }
    }
};
*/

/*union find (need polishing)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        if (!M.empty()) {
            init_Circle();
            unsigned long int n = M.size();
            for (int i = 0 ; i < n ; i++) {
                for (int j = i+1 ; j < n ; j++) {
                    if (M[i][j] == 1)
                        Make(i,j);
                }
            }

            for (int i = 0 ; i < n ; i++) {
                circle_Head[Find(i,0).first]++;
            }
            for (int i = 0 ; i < n ; i++) {
                if (circle_Head[i] != 0)
                    count ++;
            }
        }
        return count;
    }
private:
    int circle [201];
    int circle_Head [201];
    void init_Circle (){
        for (int i =0 ; i < 201 ; i++) {
            circle[i] = -1;
            circle_Head[i] = 0;
        }
    }
    void Make (int a, int b) {
        pair<int,int> pair_a = Find(a,0);
        pair<int,int> pair_b = Find(b,0);
        if(pair_a.first!=pair_b.first) {
            if (pair_a.second < pair_b.second)
                circle[pair_b.first] = pair_a.first;
            else
                circle[pair_a.first] = pair_b.first;
        }
    }

    pair<int,int> Find (int a, int rank) {
        if(circle[a] == -1) {
            return make_pair(a,rank);
        }
        return Find(circle[a],rank+1);
    }
};
*/

#endif //LEETCODE_PROBLEM547_H
