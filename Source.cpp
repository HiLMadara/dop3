#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double func(double x) {
	
	double eps = 0.0001;
	double lb = 0;
	double ub = x;
	double diff = x;
	double middle = x;
	while (diff > eps) {
		middle = lb + diff / 2;
		if ((middle * middle) > x) {
			ub = middle;
		}
		else {
			lb = middle;
		}
		diff = ub - lb;
		middle = (ub + lb) / 2;
	}
	return middle;
}



int main() {
	int N = 0, Num = 0, index, j = 0;
	double sum = 0;
	printf("N ");
	if (scanf("%d", &N) != 1 || N <= 1) {
		printf("Incorrect input");
		return 1;
	}

	double mas[256];
	for (int i = 0; i < N; i++) {
		printf("num %d ", i + 1);
		if (scanf("%l", &Num) != 1) {
			printf("Incorrect input");
			return 1;
		}
		//printf("%d\n", Num);
		mas[i] = Num;
		sum = sum + mas[i];
		j = j + 1;
	}
	sum = sum / j;
	if (sum > 0) {
		sum = func(sum);
		printf("RMS is %l", &sum);
	}
	else {
		printf("square root of a negative number");
		return 1;
	}
	return 0;
}