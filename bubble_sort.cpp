#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i, j, idx, mx;
	bool detect_move = true;
	scanf("%d", &N);
	int my_list[N];
	for (i = 0;i < N;i++) scanf("%d", &my_list[i]);
	if (detect_move) {
		mx = 0;
		for (i = 0;i < N;i++) {
			for (j = i;j < N;j++) {
				if (my_list[i] > my_list[j]) mx++;
			}
		}
		printf("%d", mx);
	}
	for (i = N - 1;i > 0;i--) {
		mx = -2147483;
		for (j = 0;j <= i;j++) {
			if (my_list[j] > mx) {
				mx = my_list[j];
				idx = j;
			}
		}
		swap(my_list[i], my_list[idx]);
	}
	printf("%d", my_list[0]);
	for (i = 1;i < N;i++) printf(" %d", my_list[i]);
	cin >> N;
	return 0;
}