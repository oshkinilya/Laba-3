#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>


struct node
{
	char inf[256];
	int val;
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы списка

void in(const char* str, int val) {
	node* list = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = list;
		last = list;
		list->val = val;
		strcpy_s(list->inf, str);
	}
	else {
		char flag = 0;
		list->val = val;
		strcpy_s(list->inf, str);
		node* sravn = head, * sravnprev = head;
		while (flag == 0) {
			while (1) {
				if (sravn->val == list->val) {	//если номера равны
					if (sravn == last) {	//если последний элемент равен вводимому
						last = list;
						sravn->prev = list;
						flag = 1;
						break;
					}
					else {
						list->prev = sravn->prev;
						sravn->prev = list;
						flag = 1;
						break;
					}
				}
				else if (sravn->val < list->val) {		//если номер с меньшим приоритетом
					if (sravn == last) {
						last = list;
						sravn->prev = list;
						flag = 1;
						break;
					}
					else {
						sravnprev = sravn;
						sravn = sravn->prev;
						break;
					}
				}
				else if (sravn->val > list->val) {		//если номер с большим приоритетом
					if (sravn == head) {
						list->prev = head;
						head = list;
						flag = 1;
						break;
					}
					else {
						list->prev = sravn;
						sravnprev->prev = list;
						flag = 1;
						break;
					}
				}
			}
		}
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
	int pr;
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
			printf("Введите номер для приоритета в очереди: ");
			scanf_s("%d", &pr);
			printf("\n");
			in(data, pr);
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
