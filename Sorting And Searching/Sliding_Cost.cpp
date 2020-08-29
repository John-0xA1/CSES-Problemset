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

    multiset<int> minHeap, maxHeap;
    ll minHeapSum = 0, maxHeapSum = 0;
    for (int i = 0; i < k - 1; i++) {
        minHeap.insert(a[i]);
        minHeapSum += a[i];
    }

    while (minHeap.size() > maxHeap.size()+ 1) {
        maxHeap.insert(*minHeap.begin());
        maxHeapSum += *minHeap.begin();
        minHeapSum -= *minHeap.begin();
        minHeap.erase(minHeap.begin());
    }

    int cur_median;
    for (int i = k - 1; i < n; i++) {

        if (!maxHeap.empty() && a[i] <= *maxHeap.rbegin()) {
            maxHeap.insert(a[i]);
            maxHeapSum += a[i];
        }
        else {
            minHeap.insert(a[i]);
            minHeapSum += a[i];
        }

        while (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.insert(*minHeap.begin());
            maxHeapSum += *minHeap.begin();
            minHeapSum -= *minHeap.begin();
            minHeap.erase(minHeap.begin());
        }

        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(*maxHeap.rbegin());
            minHeapSum += *maxHeap.rbegin();
            maxHeapSum -= *maxHeap.rbegin();
            maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
        }

        if (k & 1) {
            if (!maxHeap.empty() && maxHeap.size() > minHeap.size()) {
                cur_median = *maxHeap.rbegin();
            }
            else {
                cur_median = *minHeap.begin();
            }
        }
        else {
            if (!maxHeap.empty()) {
                cur_median = *maxHeap.rbegin();
            }
            else {
                cur_median = *minHeap.begin();
            }
        }

        cout << ((cur_median * maxHeap.size()) - maxHeapSum) + (minHeapSum - (cur_median * minHeap.size())) << " ";
       // cout << "\n" <<cur_median << " ";
        if (!maxHeap.empty() && a[i - k + 1] <= *maxHeap.rbegin()) {
            maxHeap.erase(maxHeap.find(a[i - k + 1]));
            maxHeapSum -= a[i - k + 1];
        }
        else {
            minHeap.erase(minHeap.find(a[i - k + 1]));
            minHeapSum -= a[i - k + 1];
        }
    }
}