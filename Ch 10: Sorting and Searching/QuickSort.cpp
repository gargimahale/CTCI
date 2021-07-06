#include <bits/stdc++.h>
using namespace std;

// Avg Case: TC: O(NlogN), SC: O(logN)
// Worst Case TC: O(N^2)

class QuickSort {
public:

	void display(vector<int>& arr) {
		for (int x : arr) {
			cout << x << " ";
		}
		cout << "\n";
	}

	int partition(vector<int>& arr, int low, int high) {
		int pivot = arr[(low + high) / 2];
		while (low <= high) {

			// Find element on left that should be on right
			while (arr[low] < pivot) ++low;

			// Find element on right that should be on left
			while (arr[high] > pivot) --high;

			if (low <= high) {
				swap(arr[low], arr[high]);
				++low;
				--high;
			}
		}
		return low;
	}

	void quickSort(vector<int>& arr, int low, int high) {
		int idx = partition(arr, low, high);
		if (low < idx - 1) {
			// sort left half
			quickSort(arr, low, idx - 1);
		}
		if (idx < high) {
			quickSort(arr, idx, high);
		}
	}

	void quickSort(vector<int>& arr) {
		quickSort(arr, 0, arr.size() - 1);
		display(arr);
	}
};


int main() {
	QuickSort qs;
	vector<int> arr = {5, 4, 3, 2, 1};
	cout << "Before Sorting: ";
	qs.display(arr);
	cout << "After Sorting: ";
	qs.quickSort(arr);
	return 0;
}