#include <bits/stdc++.h>
using namespace std;

int n, k, arr[100100];
int sum[100100];
int ans = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            arr[i]--;
        }
        sum[i + 1] = sum[i] + arr[i];
    }

    for (int i = 0; i <= n - k; i++) {
        set<int> s;
        for (int j = i; j < i + k; j++) {
            s.insert(sum[j]);
        }
        if (s.size() == k) {
            ans = max(ans, sum[i + k] - sum[i]);
        }
    }

    cout << ans << endl;
    return 0;
}
