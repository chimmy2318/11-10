#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) 
        return a.second < b.second; 
    return a.first < b.first; 
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    int k, X;
    cin >> k >> X;
    
    vector<pair<int, int> > diffs;
    for (int i = 0; i < N; ++i) {
        if (arr[i] != X) { // Exclude X itself
            diffs.push_back( {abs(arr[i] - X), arr[i]});
        }
    }
    
    sort(diffs.begin(), diffs.end(), compare);

    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(diffs[i].second);
    }

    sort(result.begin(), result.end());
    
    for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}