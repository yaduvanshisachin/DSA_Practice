#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {

        //Difference Array technique
        vector<int> arr(n, 0);

        for(auto &it : bookings) {
            int start = it[0]-1, end = it[1], seats = it[2];

            arr[start] += seats;
            
            if(end < n) {
                arr[end] -= seats;
            }
        }

        for(int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        return arr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;   // n = number of flights, m = number of bookings

    vector<vector<int>> bookings(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }

    Solution sol;
    vector<int> ans = sol.corpFlightBookings(bookings, n);

    cout << endl << "[";
    for(int x : ans) {
        cout << x <<" ";
    }
    cout << "]" << endl;
}