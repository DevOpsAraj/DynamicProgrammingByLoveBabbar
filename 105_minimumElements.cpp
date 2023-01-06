//Qn Link - https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

/*
#include <bits/stdc++.h> 
int solveMem(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    if(dp[n] != -1)
        return dp[n];
    
    int include = solveMem(nums, n-2, dp) + nums[n];
    int exclude = solveMem(nums, n-1, dp);
    
    dp[n] = max(include, exclude);
    return dp[n];
}

int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for(int i = 1; i <n; i++){
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n -1];
}

int solveSpaceOpt(vector<int> &nums){
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    
    for(int i = 1; i < n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
//   Mem
    
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solveMem(nums, n-1, dp);
    
//  Tab
//  return solveTab(nums);
//  Space Opti..
    return solveSpaceOpt(nums);
}
*/