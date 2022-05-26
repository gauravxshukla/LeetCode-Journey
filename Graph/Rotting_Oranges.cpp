#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int time) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || 1 < grid[i][j] && grid[i][j]<time)
            /*THIS LAST CONDITION DENOTES THAT IF THE ORANGE IS ALREADY ROTTEN BY SOME OTHER ORANGE ALREADY,
            IMAGINE grid[i][j]=3 (WHICH MEANS THAT THIS GRID WAS ALREADY CHANGED BY SOME OTHER ORANGE,OTHERWISE,
            IT WOULD HAVE BEEN 2 )AND TIME IS 4 , NOW  1 < grid[i][j](which is 3) && grid[i][j] < 4  */
            return;

            grid[i][j]=time; // Assign the current time to the grid
    
            dfs(grid,i-1,j,grid[i][j]+1); // Recursive call to all 4 sides one by one and by incrementing tine by +1
            dfs(grid,i+1,j,grid[i][j]+1);
            dfs(grid,i,j-1,grid[i][j]+1);
            dfs(grid,i,j+1,grid[i][j]+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
         for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) dfs(grid, i, j,grid[i][j]);  // We have to proceed on those oranges which are rotten already and start a recursive call AND THE REASON WHY WE ARE SENDING 2 IS BECAUSE WE CANNOT MARK TIME AS 0,1,2 SINCE THEY ARE ALREADY BEING USED BY THE QUESION(empty cell, fresh orange,rotten orange) ITSELF
            }
        }
        int totalTime=2;// WE PICKED ToTAL TIME 2 BECAUSE AFTER THE COMPLETION OF THE DFS CALLS, THE MATRIX WILL BE FILLED WITH VALUES>=2.
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==1) return -1; // AND IF BY ANY MEANS, ANY VALUE IS 1, THAT MEANS WE WERE NOT ABLE TO ROT THAT ORANGE
                totalTime=max(grid[i][j],totalTime);// OTHERWISE, SELECT THE MAX TIME TO ROT
            }
            cout<<endl;
        }
        return totalTime-2;// THIS IS IMPORTANT, REMEMBER HOW WE SET TOTALTIME AS 2 ABOVE, WE ARE GONNA SUBTRACT 2 FROM THE TOTAL TIME, SO IF TOTALTIME WAS 2, ACTUAL TIME WILL BE 2-2=0 THAT MEANS, NO ORANGES TO ROT, similarly IF THE TOTAL TIME WAS 8, THAT MEANS THE ACTUAL TIME WAS 8-2=6 SECS/MINS/HRS TO ROT ALL THE ORANGES
    }
};