#include<bits/stdc++.h>
using namespace std;

bool __debug__ = false;
int A[11] = {16,4,10,14,7,9,3,2,8,6,1}; 			// O(11)

void heapify(int *A, int size_of_A, int i) {		// O(lg(n))
	int l = 2 * i + 1, r = 2 * i + 2, largest = i;  // O(3)
	if (l < size_of_A)
		if(A[l] > A[i])
			largest = l;							// O(4)

	if (r < size_of_A)
		if(A[r] > A[largest])
			largest = r;							// O(4)

	if (largest != i) {
		swap(A[i], A[largest]);						// O(3)
		heapify(A, size_of_A, largest);
	}
}


void build_heap(int *A, int size_of_A) {			// O(size*lg(n) / 2)
	for (int i = size_of_A / 2;i > 0;i--) 			// O(size / 2)
		heapify(A, size_of_A, i);					// O(lg(n))
}

int main() {
	build_heap(A, sizeof(A) / sizeof(int));			//
	for (int i = sizeof(A) / sizeof(int) - 1; i >= 1;i--) {
		swap(A[i], A[0]);
		heapify(A, i, 0);
		if (__debug__) { 
			cout <<'\n';
			for_each(A,A+11,[](int &a){cout << a << ' ';});
		}
	}
	for_each(A,A+11,[](int &a){cout << a << ' ';});
	return 0;
}