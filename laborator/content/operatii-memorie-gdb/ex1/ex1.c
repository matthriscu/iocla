#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
	int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};

	int n = sizeof(v) / sizeof(v[0]);

	for (int i = 0; i < n; ++i) {
		char *p = (char *)(v + i);
		for (int j = 0; j < sizeof(int) / sizeof(char); ++j) {
			printf("%p: 0x%X\n", p, p[j]);
			++p;
		}
	}

	printf("\n");

	for (int i = 0; i < n; ++i) {
		short *p = (short *)(v + i);
		for (int j = 0; j < sizeof(int) / sizeof(short); ++j) {
			printf("%p: 0x%X\n", p, p[j]);
			++p;
		}
	}

	printf("\n");

	for (int i = 0; i < n; ++i)
		printf("%p: 0x%X\n", v + i, v[i]);

	return 0;
}
