#define ll long long
class Solution {
public:
    ll getGCD(ll a,ll b){
        if(a%b == 0) return b;

        return getGCD(b,a%b);
    }

    ll getLCM(ll a, ll b) {
    return (a / getGCD(a, b)) * b; 
}
    
    void generatePossibleBitsets(ll i,ll bitset,ll lcm, vector<int> &target, unordered_map<ll,ll> &mp){
        ll n = target.size();
        if(i == n){
            if(bitset != 0){
                mp[bitset] = lcm;
            }
            return;
        }
        ll newLCM = getLCM(lcm,target[i]);
        generatePossibleBitsets(i + 1, bitset, lcm, target, mp);
        generatePossibleBitsets(i + 1, bitset|(1<<i), newLCM, target, mp);
        
    }
    

    ll solve(ll i, ll bitset, ll target, unordered_map<ll,ll> &mp, vector<int> &nums,vector<vector<ll>> &dp){
        ll n = nums.size();
        ll sol = INT_MAX;
        if(i == n){
            if(bitset == target){
                return 0;
            }
            else{
                return INT_MAX;
            }
        }
        if(dp[i][bitset] != -1) return dp[i][bitset];
        
        sol = min(sol,solve(i + 1,bitset,target,mp,nums,dp));
        for(auto it: mp){
            ll currBitset = it.first;
            ll lcm = it.second; 
            ll div = nums[i]/lcm;
            ll sum = ((lcm * (div + 1)) - nums[i])%lcm; 
            ll take = sum + solve(i + 1, (bitset|currBitset), target, mp, nums,dp);
            sol = min(sol,take);
        }

        return dp[i][bitset] = sol;
    }

    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        ll m = target.size();
        ll n = nums.size();
        ll sol = 0;
        unordered_map<ll,ll> mp;
        ll finalBitset = ((1<<m) - 1);
        generatePossibleBitsets(0,0,1,target,mp);
        vector<vector<ll>> dp(n,vector<ll>(finalBitset + 1,-1));
        sol = solve(0,0,finalBitset,mp,nums,dp);
        
        return sol;
    }
};