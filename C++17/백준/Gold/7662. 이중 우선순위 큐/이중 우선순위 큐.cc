#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void sync(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, unordered_map<int, int>& map) {
    while (!maxHeap.empty() && map[maxHeap.top()] == 0) {
        maxHeap.pop();
    }
    while (!minHeap.empty() && map[minHeap.top()] == 0) {
        minHeap.pop();
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> map;

        while (k--) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                maxHeap.push(num);
                minHeap.push(num);
                map[num]++;
            } else if (op == 'D') {
                if (num == 1) {
                    sync(maxHeap, minHeap, map);
                    if (!maxHeap.empty()) {
                        int maxVal = maxHeap.top();
                        maxHeap.pop();
                        map[maxVal]--;
                    }
                } else if (num == -1) {
                    sync(maxHeap, minHeap, map);
                    if (!minHeap.empty()) {
                        int minVal = minHeap.top();
                        minHeap.pop();
                        map[minVal]--;
                    }
                }
            }
        }

        sync(maxHeap, minHeap, map);

        if (maxHeap.empty()) {
            cout << "EMPTY" << endl;
        } else {
            cout << maxHeap.top() << " " << minHeap.top() << endl;
        }
    }

    return 0;
}
