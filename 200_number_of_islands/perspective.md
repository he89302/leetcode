```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```
```
row = 0; col = 0; grid[row][col] = 1 => 0;
row = 0; col = 1; grid = 1 => 0;
    row = 0; col = 2; grid = 1 => 0;
    row = 0; col = 0; grid = 0; return;
    row = 1; col = 1; grid = 1 => 0;
    row = -1; col = 1; return;
row = 0; col = -1; return;
row = 1; col = 0;
row = -1; col = 0; return;
```
所以這樣第一次DFS 後的result:
```
grid = [
  ["0","0","0","0","0"],
  ["0","0","0","0","0"],
  ["0","0","0","0","0"],
  ["0","0","0","0","0"]
]
```

count = 1
由於island 都為0 所以for loop 結束後都不會進DFS

這邊DFS 筆記
```
void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row == grid.size() || col == grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    } 
```
