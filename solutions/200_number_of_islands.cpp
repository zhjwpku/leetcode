#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
			int i, int j, int M, int N) {
	if (i - 1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j]) {
		visited[i-1][j] = true;
		dfs(grid, visited, i - 1, j, M, N);
	}
	if (i + 1 < M && grid[i+1][j] == '1' && !visited[i+1][j]) {
		visited[i+1][j] = true;
		dfs(grid, visited, i + 1, j, M, N);
	}
	if (j - 1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1]) {
		visited[i][j-1] = true;
		dfs(grid, visited, i, j - 1, M, N);
	}
	if (j + 1 < N && grid[i][j+1] == '1' && !visited[i][j+1]) {
		visited[i][j+1] = true;
		dfs(grid, visited, i, j + 1, M, N);
	}
}

int numIslands(vector<vector<char>> &grid) {
	int M = grid.size();
	if (M == 0) return 0;
	int N = grid[0].size();
	int res = 0;

	vector<vector<bool> > visited(M, vector<bool>(N, false));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == '1' && !visited[i][j]) {
				res++;
				dfs(grid, visited, i, j, M, N);
			}
		}
	}

	return res;
}
