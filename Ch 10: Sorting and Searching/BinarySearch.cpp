#include <bits/stdc++.h>
using namespace std;

// TC: O(logN), SC: O(1)
// SC: O(n) - Recursive implementation

class BinarySearch {
public:

	int helperBinarySearch(vector<int>& arr, int low, int high, const int target) {
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] > target) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return -1;
	}

	int findElementPos(vector<int>& arr, const int target) {
		return helperBinarySearch(arr, 0, arr.size() - 1, target);
	}
};


int main() {
	BinarySearch bs;
	vector<int> arr = {1, 2, 3, 4, 5};
	int target = 8;
	cout << bs.findElementPos(arr, target) << "\n";
	return 0;
}