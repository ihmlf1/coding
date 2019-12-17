#include<stdio.h>
int total[1000001];
int main() {
	int count, ma, a, b, i, ch, j, w;
	scanf("%d", &count);
	for (; count > 0; count--) {
		scanf("%d", &ma);
		for (j = ma + 1; j > 0; j--) {
			total[j] = 0;
		}
		for (i = ma; i > 0; i--) {
			scanf("%d%d", &a, &b);
			if (a + b >= 10) {
				w = 1;
				while (total[i + w] == 9)
					w++;
				total[i + w]++;
				for (; w > 0; w--) {
					total[w + i - 1] = 0;
				}
				total[i] = (a + b) % 10;
			}
			else
				total[i] = a + b;
		}
		if (total[ma + 1] != 0)
			printf("1");
		for (; ma > 0; ma--) {
			printf("%d", total[ma]);
		}
		puts("");
		if (count != 1)
			puts("");
	}
}



