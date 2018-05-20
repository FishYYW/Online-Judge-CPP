//
// Created by victor on 2018/5/17.
//

#ifndef LEETCODE_LINT860_H
#define LEETCODE_LINT860_H
// use string to describe the shape of islands
#include <vector>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    int numberofDistinctIslands(vector<vector<int>> &grid) {
		int rows = grid.size();
        int cols = grid[0].size();
		set<string> islands;
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				string island ="";
				dfs(i, j, i, j, island, grid, rows, cols);
				islands.insert(island);
			}
		}
		return islands.size()-1;
	}
private:
	void dfs(int sx, int sy, int x, int y, string &island, vector<vector<int>> &grid, int rows, int cols) {
		if(x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] <= 0) return;
		island += to_string(x-sx) + "_" + to_string(y-sy) + " ";
		grid[x][y] = -1;
		for(int i = 0; i < 4; i++) {
            dfs(sx, sy, x + dir[i][0], y + dir[i][1], island, grid, rows, cols);
        }
    }
    int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
};
#endif //LEETCODE_LINT860_H
