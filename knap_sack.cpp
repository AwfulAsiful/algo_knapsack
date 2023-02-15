#include <bits/stdc++.h>
using namespace std;

int weight[110];
int val[110];

int knapsack(int idx, int weightleft[])
{
    if (weightleft == 0)
        return 0;
    if (idx < 0)
        return 0;

    int ans = knapsack(idx - 1, weightleft);

    if (weightleft - weight[idx] >= 0)
    {
        ans = max(ans, knapsack(idx - 1, weightleft - weight[idx])) + val[idx];
    }
    return ans;
}

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << knapsack(n - 1, weight) << endl;

    return 0;
}