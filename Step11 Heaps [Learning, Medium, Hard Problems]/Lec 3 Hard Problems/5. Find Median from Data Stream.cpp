// We are given the stream of numbers and we have to find the median of the numbers at any point of time.

//* Brute Force Approach
/*
1. We can store the numbers in the array and sort the array.
2. If the size of the array is even then the median will be the average of the middle two elements.
3. If the size of the array is odd then the median will be the middle element.
4. The time complexity of this approach is O(nlogn) for each query.

total time complexity = O(n^2logn)
*/

//* Optimal Approach
/*
1. We can use two heaps to solve this problem.