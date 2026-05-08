// Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.
// Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMeetingRooms(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms = 0;
    int max_rooms = 0;
    int s_ptr = 0;
    int e_ptr = 0;

    while (s_ptr < n) {
        if (start[s_ptr] < end[e_ptr]) {
            rooms++;
            s_ptr++;
        } else {
            rooms--;
            e_ptr++;
        }
        max_rooms = max(max_rooms, rooms);
    }

    return max_rooms;
}

int main() {
    vector<int> start = {0, 5, 15};
    vector<int> end = {30, 10, 20};

    cout << minMeetingRooms(start, end) << endl;

    return 0;
}