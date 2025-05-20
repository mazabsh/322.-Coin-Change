#include<iostream> 
#include<vector> 
#include<algorithm>

using namespace std; 

class Solution{
public: 
     int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, amount+1); 
       dp[0]=0; 

       for(auto coin: coins){
         for(int i=coin; i<=amount; ++i){
           dp[i]= min(dp[i], dp[i-coin]+1); 
         }
       }
       return dp[amount] > amount? -1: dp[amount]; 
     }
};
int main(){
  vector<int> coins = {1,2,5}; 
  int amount = 11; 
  Solution sol; 
  cout << sol.coinChange(coins, amount); 
  return 0; 
}
