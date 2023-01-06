// Qn link - https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
// Check Same question on Leetcode named Maximal Sqaure
/*

class Solution{
public:

    int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
          
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }
    
    int solveTab(vector<vector<int>> &mat, int &maxi){
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n +1 , vector<int>(m + 1, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[0][0];
        
    }
    
    // Space Optimized
    int solveSpaceOpt(vector<vector<int>> &mat, int &maxi){
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            next = curr;
        }
        return next[0];
    }
    
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        // Call of Memoization Function
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solveMem(mat, 0, 0, maxi, dp);
        return maxi;
        
        
        // Tabulation Function Call
        int maxi = 0;
        solveTab(mat, maxi);
        return maxi;
        
        //Space Optimized Function Call
        int maxi = 0;
        solveSpaceOpt(mat, maxi);
        return maxi;
    }
};

*/