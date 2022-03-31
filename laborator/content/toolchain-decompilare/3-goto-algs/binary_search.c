#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = v[2]; /* 15 */
	int start = 0;
	int mid;
	int end = sizeof(v) / sizeof(int) - 1;

if_start:
	if (start < end) {
		mid = start + (end - start) / 2;
		goto compare;
	}
	goto end;

compare:
	if (v[mid] == dest) {
		printf("%d\n", dest);
		goto end;
	}

	if (v[mid] < dest) {
		start = mid + 1;
		goto if_start;
	}

	if (v[mid] > dest) {
		end = mid - 1;
		goto if_start;
	}

end:
	return 0;
}
