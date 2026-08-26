#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coins[n];

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum coins required to make amount i
    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = 1000000;

        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i],
                            1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[amount] == 1000000)
        cout << "Change cannot be made";
    else
        cout << "Minimum number of coins = " << dp[amount];

    return 0;
}
