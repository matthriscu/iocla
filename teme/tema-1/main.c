#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "structs.h"

#define MAX_LEN 256

void append_data(void **dest, unsigned int *dest_len, const void *src, const unsigned int src_len)
{
	*dest = realloc(*dest, *dest_len + src_len);
	memcpy((char *)(*dest) + *dest_len, src, src_len);
	*dest_len += src_len;
}

void get_type_1(void **data, unsigned int *data_len)
{
	char name1[MAX_LEN], name2[MAX_LEN];
	int8_t bills[2];
	scanf(" %s%" PRId8 "%" PRId8 " %s", name1, &bills[0], &bills[1], name2);
	printf("%s\n", name1);
	*data = NULL;
	*data_len = 0;
	append_data(data, data_len, name1, strlen(name1) + 1);
	append_data(data, data_len, bills, sizeof(bills));
	append_data(data, data_len, name2, strlen(name2) + 1);
}


void get_type_2(void **data, unsigned int *data_len)
{
	char name1[MAX_LEN], name2[MAX_LEN];
	int16_t bill1;
	int32_t bill2;
	scanf(" %s%" PRId16 "%" PRId32 " %s", name1, &bill1, &bill2, name2);
	*data = NULL;
	*data_len = 0;
	append_data(data, data_len, name1, strlen(name1) + 1);
	append_data(data, data_len, &bill1, sizeof(int16_t));
	append_data(data, data_len, &bill2, sizeof(int32_t));
	append_data(data, data_len, name2, strlen(name2) + 1);
}

void get_type_3(void **data, unsigned int *data_len)
{
	char name1[MAX_LEN], name2[MAX_LEN];
	int32_t bills[2];
	scanf(" %s%" PRId32 "%" PRId32 " %s", name1, &bills[0], &bills[1], name2);
	*data = NULL;
	*data_len = 0;
	append_data(data, data_len, name1, strlen(name1) + 1);
	append_data(data, data_len, bills, sizeof(bills));
	append_data(data, data_len, name2, strlen(name2) + 1);
}

data_structure *create_ds()
{
	data_structure *new = malloc(sizeof(data_structure));
	new->header = malloc(sizeof(head));
	new->data = NULL;
	new->header->len = 0;
	scanf("%hhu", &new->header->type);

	switch (new->header->type) {
		case 1:
			get_type_1(&new->data, &new->header->len);
			break;
		case 2:
			get_type_2(&new->data, &new->header->len);
			break;
		case 3:
			get_type_3(&new->data, &new->header->len);
			break;
		default:
			break;
	}

	return new;
}

void free_ds(data_structure *ds)
{
	free(ds->header);
	free(ds->data);
}

int add_last(void **arr, unsigned int *len, data_structure *data)
{
	append_data(arr, (unsigned int *)len, data->header, sizeof(head));
	append_data(arr, (unsigned int *)len, data->data, data->header->len);
	return 1;
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	return 0;
}

void find(void *data_block, int len, int index) 
{
	return;
}

int delete_at(void **arr, int *len, int index)
{
	return 0;
}

void print_type_1(void *start)
{
	puts("Tipul 1");
	start = (char *)start + sizeof(head);
	char *name1 = start;
	start = (char *)start + strlen(name1) + 1;
	int8_t* bills = start;
	start = (char *)start + sizeof(int8_t) * 2;
	char *name2 = start;

	printf("%s pentru %s\n%" PRId8 "\n%" PRId8 "\n", name1, name2, bills[0], bills[1]);
}

void print_type_2(void *start)
{
	puts("Tipul 2");
	start = (char *)start + sizeof(head);
	char *name1 = start;
	start = (char *)start + strlen(name1) + 1;
	int16_t* bill1 = start;
	start = (char *)start + sizeof(int16_t);
	int32_t* bill2 = start;
	start = (char *)start + sizeof(int32_t);
	char *name2 = start;

	printf("%s pentru %s\n%" PRId16 "\n%" PRId32 "\n", name1, name2, *bill1, *bill2);
}

void print_type_3(void *start)
{
	puts("Tipul 1");
	start = (char *)start + sizeof(head);
	char *name1 = start;
	start = (char *)start + strlen(name1) + 1;
	int32_t* bills = start;
	start = (char *)start + sizeof(int32_t) * 2;
	char *name2 = start;

	printf("%s pentru %s\n%" PRId32 "\n%" PRId32 "\n", name1, name2, bills[0], bills[1]);
}

void print(void *arr, unsigned int len)
{
	void *current = arr;
	while ((char *)current - (char *)arr < len) {
		head header = *(head *)current;
		printf("%u %u\n", header.type, header.len);
		switch (header.type) {
			case 1:
				print_type_1(current);
				break;
			case 2:
				print_type_2(current);
				break;
			case 3:
				print_type_3(current);
				break;
			default:
				break;
		}
		current = (char *)current + header.len + sizeof(head);
	}
}

int main() {
	void *arr = NULL;
	unsigned int len = 0;

	char command[MAX_LEN + 1];

	do {
		scanf(" %s", command);

		if (!strcmp(command, "insert")) {
			data_structure *new = create_ds();
			add_last(&arr, &len, new);
			free_ds(new); // wow am creat un ds ca sa il distrug
		} else if (!strcmp(command, "print")) {
			print(arr, len);
		} else if (!strcmp(command, "exit")) {
			free(arr);
			break;
		}
	} while (1);

	return 0;
}
