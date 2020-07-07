/* QUESTION: You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 
Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/

class Solution {
public:
    vector<vector<int> > g;
    int n,m;
    int ans=0;
    
    void dfs(int x,int y){
        
        if(x<0 || y<0 || x>=n || y>=m || g[x][y]==0){
            ans++;
            return;
        }
        
        if(g[x][y]==-1) return ;
        
        g[x][y]=-1;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
    
    void traverse(){
         for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]){
            dfs(i,j);
            return;
        } 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        g=grid;
        traverse();
        return ans;
       
    }
};
