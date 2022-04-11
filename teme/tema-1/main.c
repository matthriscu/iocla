#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"

#define MAX_LEN 256

void append_data(void **dest, int *dest_len, const void *src, const int src_len)
{
	*dest = realloc(*dest, *dest_len + src_len);
	memcpy((char *)(*dest) + *dest_len, src, src_len);
	*dest_len += src_len;
}

data_structure *create_ds()
{
	data_structure *new = malloc(sizeof(data_structure));
	new->header = malloc(sizeof(head));
	new->data = NULL;
	new->header->len = 0;
	char name1[MAX_LEN];
	scanf("%u%s", &new->header->type, name1);
	append_data(&new->data, new->header->len, name1, strlen(name1) + 1);

	if (new->header->type == 1) {
		int8_t bills[2];
		scanf("%%" PRId8 PRId8, bills, bills + 1);
		append_data(&new->data, new->header->len, bills, 2 * sizeof(int8_t));
	} else {
		if (new->header->type == 2) {
			int16_t bill1;
			scanf("%" PRId16, &bill1);
			append_data(&new->data, new->header->len, &bill1, sizeof(int16_t));
		} else {
			int32_t bill1;
			scanf("%" PRId32, &bill1);
			append_data(&new->data, new->header->len, &bill1, sizeof(int32_t));
		}
		int32_t bill2;
		scanf("%" PRId32, &bill2);
		append_data(&new->data, new->header->len, &bill2, sizeof(int32_t));
	}

	char name2[MAX_LEN];
	scanf("%s", name2);
	append_data(&new->data, new->header->len, name2, strlen(name2) + 1);

	return new;
}

int add_last(void **arr, int *len, data_structure *data)
{
	append_data(arr, len, data->header, sizeof(head));
	append_data(arr, len, data->data, data->header->len);
}

int add_at(void **arr, int *len, data_structure *data, int index)
{

}

void find(void *data_block, int len, int index) 
{

}

int delete_at(void **arr, int *len, int index)
{

}

int main() {
	void *arr = NULL;
	int len = 0;

	char command[MAX_LEN + 1];

	do {
		fgets(command, MAX_LEN, stdin);

		if (!strcmp(command, "insert")) {
			data_structure *new = create_ds();
			add_last(&arr, &len, new);
		}
	} while (1);

	return 0;
}
