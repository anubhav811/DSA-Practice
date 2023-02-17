// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int f[], int n)
    {
        // Your code here
         pair<int, int> a[n + 1];
    int i;
    for (i = 0; i < n; i++) {
        a[i].first = f[i];
        a[i].second = i;
    }
    // Sorting of meeting according to their finish time.
    sort(a, a + n);

    // time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = a[0].first;

    // Vector for storing selected meeting.
    vector<int> m;

    // Initially select first meeting.
    m.push_back(a[0].second + 1);

    // Check for all meeting whether it
    // can be selected or not.
    for (i = 1; i < n; i++) {
        if (s[a[i].second] > time_limit) {
            // Push selected meeting to vector
            m.push_back(a[i].second + 1);

            // update time limit
            time_limit = a[i].first;
        }
    }

    // Print final selected meetings.
    // for (int i = 0; i < m.size(); i++) {
    //     cout << m[i] << " ";
    // }
    return m.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends