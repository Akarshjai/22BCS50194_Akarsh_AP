//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minCost(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) return 0;
        if (n == 2) return abs(heights[1] - heights[0]);
        
        vector<int> dp(n, 0);
        dp[1] = abs(heights[1] - heights[0]);
        
        for (int i = 2; i < n; i++) {
            int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            dp[i] = min(oneStep, twoStep);
        }
        
        return dp[n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends