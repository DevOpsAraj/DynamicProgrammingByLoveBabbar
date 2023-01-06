// Qn link - https://leetcode.com/problems/longest-increasing-subsequence/

/*

class Solution {
public:
    //Memoization; tc: O(n^2) && sc : O(n^2)
    int solveMem(int n, vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr == n)
            return 0;

        if(dp[curr][prev +1] != -1)
            return dp[curr][prev + 1];

        int incl = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            incl = 1 + solveMem(n, nums, curr+1, curr, dp);

        int excl = solveMem(n, nums, curr+1, prev, dp);

        return dp[curr][prev + 1] = max(incl, excl);
    }

    int solveTab(int n, vector<int> &nums){
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int curr = n -1; curr >= 0; curr--){
            for(int prev = curr -1; prev >= -1; prev--){
                int incl = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    incl = 1 + dp[curr+1][curr + 1];

                int excl = dp[curr +1][prev +1];

                dp[curr][prev + 1] = max(incl, excl);
            }
        }
        return dp[0][0];
    }

    int solveSpaceOpt(int n, vector<int> &nums){
        vector<int> currR(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr = n -1; curr >= 0; curr--){
            for(int prev = curr -1; prev >= -1; prev--){
                int incl = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    incl = 1 + next[curr + 1];

                int excl = next[prev +1];

                currR[prev + 1] = max(incl, excl);
            }
            next = currR;
        }
        return next[0];
    }

    // DP With BINARY SEARCH
    int dpWithBS(int n, vector<int> &nums){
        if(n == 0)
            return 0;
        
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solveMem(n, nums, 0, -1, dp);

        // return solveTab(n, nums);

        // return solveSpaceOpt(n, nums);

        return dpWithBS(n, nums);
    }
};

*/