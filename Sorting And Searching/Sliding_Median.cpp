#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> maxHeap, minHeap;
    for (int i = 0; i < k - 1; i++) {
        minHeap.insert(a[i]);
    }

    while (minHeap.size() > maxHeap.size() + 1) {
        maxHeap.insert(*minHeap.begin());
        minHeap.erase(minHeap.begin());
    }

    for (int i = k - 1; i < n; i++) {
        if (!maxHeap.empty() && a[i] <= *maxHeap.rbegin()) {
            maxHeap.insert(a[i]);
        }
        else {
            minHeap.insert(a[i]);
        }

        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
        }

        while (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }

        if (k & 1) {
            if (!maxHeap.empty() && maxHeap.size() > minHeap.size()) {
                cout << *maxHeap.rbegin() << " ";
            }
            else {
                cout << *minHeap.begin() << " ";
            }
        }
        else {
            if (!maxHeap.empty()) {
                cout << *maxHeap.rbegin() << " ";
            }
            else {
                cout << *minHeap.begin() << " ";
            }
        }

        if (!maxHeap.empty() && a[i - k + 1] <= *maxHeap.rbegin()) {
            maxHeap.erase(maxHeap.find(a[i - k + 1]));
        }
        else {
            minHeap.erase(minHeap.find(a[i - k + 1]));
        }
    }
}