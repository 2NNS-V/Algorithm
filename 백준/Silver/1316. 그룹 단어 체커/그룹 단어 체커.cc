#include <stdio.h>
#include <string.h>
#define MAX 100

int Count(char a[], int len) {
	int key = 0;;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (a[i] == a[j]) {
				key = j - i;
				if (key > 1)
					if (a[j - 1] != a[j])
						return 0;
			}
		}
	}
	return 1;
}

int main() {
	char words[MAX];
	int n, cnt=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", words);
		cnt += Count(words, strlen(words));
	}
	printf("%d", cnt);
	
}
