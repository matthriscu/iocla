#include <stdio.h>

int main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 2};
	int max = v[0], i = -1, size = sizeof(v) / sizeof(*v);

if_start:
	if (++i < size)
		goto compare;
	goto end;

compare:
	if (v[i] > max)
		max = v[i];
	goto if_start;

end:
	printf("%d\n", max);
	return 0;	
}
