// Qn link - https://leetcode.com/problems/minimum-cost-for-tickets/

/*

class Solution {
public:
    int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
        //Base Case
        if(index >= n)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        //1Day Pass
        int opt1 = cost[0] + solveMem(n, days, cost, index + 1, dp);
        
        //7Day Pass
        int i;
        for(i = index; i < n && days[i] < days[index] + 7; i++);
        int opt2 = cost[1] + solveMem(n, days, cost, i, dp);
        
        //30Day Pass
        for(i = index; i < n && days[i] < days[index] + 30; i++);
        int opt3 = cost[2] + solveMem(n, days, cost, i, dp);
        
        dp[index] = min(opt1, min(opt2, opt3));
        
        return dp[index];
    }

    int solveTab(int n, vector<int> &days, vector<int> &cost){
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        
        for(int temp = n-1; temp >= 0; temp--){
            //1Day Pass
            int opt1 = cost[0] + dp[temp+1];

            //7Day Pass
            int i;
            for(i = temp; i < n && days[i] < days[temp] + 7; i++);
            int opt2 = cost[1] + dp[i];

            //30Day Pass
            for(i = temp; i < n && days[i] < days[temp] + 30; i++);
            int opt3 = cost[2] + dp[i];

            dp[temp] = min(opt1, min(opt2, opt3));
        }
        return dp[0];
    }

    int solveSpaceOpt(vector<int>& days, vector<int>& costs){
        int ans = 0;
        
        queue<pair<int, int>> month; // At MAX entries will be 30
        queue<pair<int, int>> week; // At MAX entries will be 30

        for(int day : days){
            //step1: remove expired days
            while(!month.empty() && month.front().first + 30 <= day)
                month.pop();
            
            while(!week.empty() && week.front().first + 7 <= day)
                week.pop();

            //step2: Add cost for current day;
            week.push({day, ans+costs[1]});
            month.push({day, ans+costs[2]});

            //step3: update ans
            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // vector<int> dp(n+1, -1);
        // return solveMem(n, days, costs, 0, dp);

        // return solveTab(n, days, costs);

        return solveSpaceOpt(days, costs);
    }
};

*/