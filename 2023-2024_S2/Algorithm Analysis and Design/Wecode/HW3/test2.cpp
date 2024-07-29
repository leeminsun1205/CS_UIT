#include <bits/stdc++.h>
using namespace std;

struct Event {
    int x, height;
    bool isStart;
    Event(int x, int height, bool isStart) : x(x), height(height), isStart(isStart) {}
    
    bool operator<(const Event& e) const {
        if (x != e.x) return x < e.x;
        if (isStart != e.isStart) return isStart;
        return isStart ? height > e.height : height < e.height;
    }
};

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<Event> events;
    for (auto& building : buildings) {
        events.emplace_back(building[0], building[2], true);
        events.emplace_back(building[1], building[2], false);
    }
    
    sort(events.begin(), events.end());
    
    multiset<int> heights;
    heights.insert(0);
    vector<pair<int, int>> result;
    int prevMaxHeight = 0;
    
    for (auto& event : events) {
        if (event.isStart) {
            heights.insert(event.height);
        } else {
            heights.erase(heights.find(event.height));
        }
        
        int currentMaxHeight = *heights.rbegin();
        if (currentMaxHeight != prevMaxHeight) {
            result.emplace_back(event.x, currentMaxHeight);
            prevMaxHeight = currentMaxHeight;
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> buildings(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    }
    
    vector<pair<int, int>> skyline = getSkyline(buildings);
    
    for (auto& point : skyline) {
        cout << point.first << " " << point.second << endl;
    }
    
    return 0;
}
