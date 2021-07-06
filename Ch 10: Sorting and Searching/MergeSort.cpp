#include <bits/stdc++.h>
using namespace std;

// Avg & Worst Case: TC: O(NlogN), SC: O(N)
// Space complexity is due to the aux space used to merge
// parts of the array

class MergeSort {
public:

	void display(vector<int>& arr) {
		for (int x : arr) {
			cout << x << " ";
		}
		cout << "\n";
	}

	void merge(vector<int>& arr, vector<int>& helper, int low, int mid, int high) {
		for (int i = low; i <= high; ++i) {
			helper[i] = arr[i];
		}

		int helperLeft = low, helperRight = mid + 1, curr = low;

		while (helperLeft <= mid && helperRight <= high) {
			if (helper[helperLeft] <= helper[helperRight]) {
				arr[curr] = helper[helperLeft++];
			} else {
				arr[curr] = helper[helperRight++];
			}
			++curr;
		}

		while (helperLeft <= mid) {
			arr[curr] = helper[helperLeft++];
			++curr;
		}
	}

	void mergeSort(vector<int>& arr, vector<int>& helper, int low, int high) {
		if (low < high) {
			int mid = low + (high - low) / 2;

			// Sort Left Half
			mergeSort(arr, helper, low, mid);

			// Sort Right Half
			mergeSort(arr, helper, mid + 1, high);

			// Merge
			merge(arr, helper, low, mid, high);
		}
	}

	void mergeSort(vector<int>& arr) {
		vector<int> helper(arr.size());
		mergeSort(arr, helper, 0, arr.size() - 1);
		display(arr);
	}
};


int main() {
	MergeSort ms;
	vector<int> arr = {5, 4, 3, 2, 1};
	cout << "Before Sorting:";
	ms.display(arr);
	cout << "After Sorting:";
	ms.mergeSort(arr);
	return 0;
}