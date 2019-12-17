#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char a[250] = { 0 }, b[250] = { 0 };
	int an[500] = { 0 }, ai, bi, i, j, k;
	while (scanf("%s%s", &a, &b) != EOF) {
		for (k = strlen(a); k > 0; k--) {
			j = 0;
			if (a[k - 1] != '\0')
				ai = a[k - 1] - '0';
			else
				ai = 0;
			for (i = strlen(b); i > 0; i--) {
				if (b[i - 1] != '\0')
					bi = b[i - 1] - '0';
				else
					bi = 0;
				while (1) {
					an[j + strlen(a) - k] += ai * bi;
					if (an[j + strlen(a) - k] >= 10) {
						an[j + strlen(a) - k + 1] += an[j + strlen(a) - k] / 10;
						an[j + strlen(a) - k] %= 10;
					}
					j++;
					break;
				}
			}
		}
		if (an[strlen(b) + strlen(a) - 1] != 0)
			printf("%d", an[strlen(b) + strlen(a) - 1]);
		for (i = strlen(b) + strlen(a) - 2; i >= 0; i--) {
			printf("%d", an[i]);
		}
		for (i = 0; i < strlen(b) + strlen(a); i++)
			an[i] = 0;
		puts("");
	}
}

