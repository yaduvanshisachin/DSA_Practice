#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    map<int, int> mp; //events
    // int count = 0;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int count = 0;
        for(auto &it : mp) {
            count += it.second;

            if(count > 2) {
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */