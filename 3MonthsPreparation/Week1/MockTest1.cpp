/*
* Complete the 'findMedian' function below.
*
* The function is expected to return an INTEGER.
* The function accepts INTEGER_ARRAY arr as parameter.
*/
int findMedian(vector<int> arr) {
	long int sum = arr[0];
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	int medianIndex = size % 2 == 0 ? size / 2 : size / 2 + 1;

	return arr[medianIndex - 1];
}