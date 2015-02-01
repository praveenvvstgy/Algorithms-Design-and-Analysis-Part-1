#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long swap_count = 0;

long pivot(vector <long long> &numbers, long l, long h) {
	long mid = l + (h - l) / 2;
	if (numbers[l] < numbers[mid])
	{
		if (numbers[mid] < numbers[h])
		{
			return mid;
		} else if (numbers[h] < numbers[l])
		{
			return l;
		} else {
			return h;
		}
	} else {
		if (numbers[l] < numbers[h])
		{
			return l;
		} else if (numbers[h] < numbers[mid])
		{
			return mid;
		} else {
			return h;
		}
	}
}

long partition(vector <long long> &numbers, long l, long h) {
	long i = l + 1;
	swap(numbers[l], numbers[pivot(numbers, l, h)]);
	for(long j = l + 1; j <= h; j++) {
		if (numbers[j] <= numbers[l])
		{
			if (j > i)
			{
				swap(numbers[j], numbers[i]);
			}
			i++;
		}
	}
	swap(numbers[i-1], numbers[l]);
	return i-1;
}

void quicksort(vector <long long> &numbers, long l, long h) {
	if (l < h)
	{
		long p = partition(numbers, l, h);
		swap_count += h - l;
		quicksort(numbers, l, p - 1);
		quicksort(numbers, p + 1, h);
	}
}

int main() {
	// your code goes here
	long n;
	n = 10000;
	vector <long long> numbers(n);
	for(long j = 0; j < n; j++) {
		cin>>numbers[j];
	}
	quicksort(numbers, 0, numbers.size() - 1);
	cout<<"Swap Count: "<<swap_count<<endl;
	return 0;
}