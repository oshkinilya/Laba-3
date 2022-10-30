#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>

struct node
{
	char inf[256];
	struct node* prev; // ссылка на предыдущий элемент 
	struct node* next;
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы списка

void in(const char* str) {
	node* list = (node*)malloc(sizeof(node));
	if (last == NULL) {
		last = list;
		strcpy_s(list->inf, str);
		last->next = NULL;
	}
	else {
		list->next = last;
		strcpy_s(list->inf, str);
		last = list;
	}
}

void out() {
	if (last == NULL) {
		("Стек пуст\n");
		return;
	}
	else if (last->next == NULL) {
		printf("Извлечённый элемент: %s\n", last->inf);
		free(last);
		last = NULL;
	}
	else {
		printf("Извлечённый элемент: %s\n", last->inf);
		node* tmp = last;
		last = last->next;
		free(tmp);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char data[256];
	int buf;
	while (1) {
		if (last != NULL) {
			node* list = last;
			printf("Стек: ");
			while (1) {
				printf("%s ", list->inf);
				if (list->next == NULL) {
					printf("\n");
					break;
				}
				list = list->next;
			}
		}
		printf("Введите: 1 для помещения в стек, 2 для извлечения из стека, 0 для выхода ");
		scanf("%d", &buf);
		printf("\n");
		if (buf == 1) {
			printf("Введите данные для помещения в стек: ");
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
