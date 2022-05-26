#include<bits/stdc++.h>
using namespace std;

class UsingDFS {
public:
    int res=0;
    void solve(int i, int j, vector<vector<char>> &g){
        
        // Stretch this one island as much as you can till it get out of bounds.
        if(i>=0 && i<g.size() && j>=0 && j<g[0].size() && g[i][j] == '1')  {
            
            // Mark it as visited so in future u dont use this cell for some other island
            g[i][j] = '2'; 
            
            //Traverse all four directions to check how connected/big this island is.
            solve(i-1, j, g); // Up
            solve(i+1, j, g); // Down 
            solve(i, j-1, g); // Left
            solve(i, j+1, g); // Right
        }
    }

    int numIslands(vector<vector<char>> &g) 
    { // Traversing entire matrix for finding '1' that represent your island
        for(int i=0; i<g.size(); i++) 
            for(int j=0; j<g[0].size(); j++)
                if(g[i][j]=='1') // Valid Candidate
                    solve(i, j, g), res++; // Apply DFS, increment result by 1 as u found one island
        return res;
    }
};