#include <bits/stdc++.h>
using namespace std;

// TC: (n), SC: O()

class SparseSearch {
public:

	int search(vector<string>& arr, string target, int left, int right) {
		if (left > right) return -1;

		int mid = left + (right - left) / 2;

		if (arr[mid] == "") {
			int low = mid - 1;
			int high = mid + 1;
			while (1) {
				if (low < left &&  high > right) return -1;

				if (low >= left && arr[left] != "") {
					mid = left;
					break;
				}

				else if (high <= right && arr[right] != "") {
					mid = right;
					break;
				}

			}
			--low, ++high;
		}

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			return search(arr, target, left, mid - 1);
		}
		else {
			return search(arr, target, mid + 1, right);
		}

	}

	int search(vector<string>& arr, string& target) {
		if (arr.size() == 0 || target == "" || target.size() == 0) {
			return -1;
		}
		return search(arr, target, 0, arr.size() - 1);
	}
};

int main() {
	SparseSearch ss;
	vector<string> arr = {"for", "geeks", "", "", "", "", "ide",
	                      "practice", "", "", "", "quiz"
	                     };
	string target = "practice";
	cout << ss.search(arr, target);
	return 0;
}