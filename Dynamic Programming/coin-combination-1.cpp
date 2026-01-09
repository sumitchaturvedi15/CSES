#include <bits/stdc++.h>
using namespace std;
#define ll int
int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    vector<ll> dp(target + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 1;
    sort(coins.begin(), coins.end());
    for (ll t = 1; t <= target; t++)
    {
        ll take = 0;
        for (ll j = 0; j < n; j++)
        {
            if (t < coins[j])
                break;
            take += dp[t - coins[j]];
            if(take>=MOD) take-=MOD;
        }
        dp[t] = take;
    }
    cout << dp[target]<< endl;
    return 0;
}