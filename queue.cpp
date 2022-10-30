#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>

struct node
{
	char inf[256];
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы списка

void in(const char* str) {
	node* list = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = list;
		last = list;
		strcpy_s(list->inf, str);
	}
	else {
		last->prev = list;
		strcpy_s(list->inf, str);
		last = list;
	}
}

void out() {
	if (head == NULL) {
		("Очередь пустая\n");
		return;
	}
	else if (head == last) {
		printf("Извлечённый элемент: %s\n", head->inf);
		free(head);
		head = NULL;
		last = NULL;
	}
	else {
		printf("Извлечённый элемент: %s\n", head->inf);
		node* tmp = head;
		head = head->prev;
		free(tmp);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char data[256];
	int buf;
	while (1) {
		if (head != NULL) {
			node* list = head;
			printf("Очередь: ");
			while (1) {
				printf("%s ", list->inf);
				if (list == last) {
					printf("\n");
					break;
				}
				list = list->prev;
			}
		}
		printf("Введите: 1 для помещения в очередь, 2 для извлечения из очереди, 0 для выхода ");
		scanf("%d", &buf);
		printf("\n");
		if (buf == 1) {
			printf("Введите данные для помещения в очередь: ");
			scanf("%s", data);
			printf("\n");
			in(data);
		}
		else if (buf == 2) {
			out();
		}
		else if (buf == 0) {
			exit(0);
		}
		else {
			printf("Вы ввели команду неверно\n");
		}
	}
}
