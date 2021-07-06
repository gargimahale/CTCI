/*
Bucket sort is mainly useful when input is uniformly distributed
over a range. For example, consider the following problem.

Sort a large set of floating point numbers which are in range
from 0.0 to 1.0 and are uniformly distributed across the range.

Algo:----------------------------------------------
bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.


Worst Case Complexity: O(n2)
	- When there are elements of close range in the array, they are likely to
	  be placed in the same bucket. This may result in some buckets having more
	  number of elements than others.
	- It makes the complexity depend on the sorting algorithm used to sort the
	  elements of the bucket.
	- The complexity becomes even worse when the elements are in reverse order.
	- If insertion sort is used to sort elements of the bucket, then the time
	  complexity becomes O(n2).


Best Case Complexity: O(n+k)
	- It occurs when the elements are uniformly distributed in the buckets with a nearly equal
	number of elements in each bucket.
	- The complexity becomes even better if the elements inside the buckets are already sorted.
	- If insertion sort is used to sort elements of a bucket then the overall complexity in the
	best case will be linear ie. O(n+k).
	- O(n) is the complexity for making the buckets and O(k) is the complexity for sorting the
	elements of the bucket using algorithms having linear time complexity at the best case.


Average Case Complexity: O(n)
	- It occurs when the elements are distributed randomly in the array. Even if the elements are not
	distributed uniformly, bucket sort runs in linear time. It holds true until the sum of the squares
	of the bucket sizes is linear in the total number of elements.
 */