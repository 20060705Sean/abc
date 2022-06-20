#include <bits/stdc++.h>
using namespace std;

int main() {
	// Variables Declaration and Inputs
	int i, N;
	scanf("%d", &N);
	vector<int> not_sorted(N);
	for (i = 0;i < N;i++) scanf("%d", &not_sorted[i]);
	list<int> sorted{not_sorted[--N]};
	list<int>::iterator accesser, last = sorted.end();
	// Computation
	while (N--) {
		accesser = sorted.begin();
		while (true) {
			if (accesser == last) break;
			if (not_sorted[N] < *accesser) break;
			accesser++;
		} 
		sorted.insert(accesser, not_sorted[N]);
	}
	for (accesser = sorted.begin();accesser != sorted.end();accesser++) printf("%d ", *accesser);
	cin >> N;
}