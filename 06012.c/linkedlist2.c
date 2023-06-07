#include<stdio.h>
#include<stdlib.h>


typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}
ListNode* delete_first(ListNode* head)
{

	if (head == NULL)
	{
		printf("First Node has been");
		return head;
	}
	ListNode* cur = head->link;
	if (cur == head)
	{
		free(cur);
		head = NULL;
	}
	else
	{
		head->link = cur->link;
		free(cur);
	}
	printf("First Node has been deleted");
	return head;
}
ListNode* delete_last(ListNode* head)
{
	if (head == NULL) {
		printf("List is empty. Cannot delete.\n");
		return head;
	}

	ListNode* cur = head->link;
	ListNode* prev = NULL;

	if (cur == head) {
		// ����Ʈ�� ��尡 �� ���� �����ϴ� ���
		free(cur);
		head = NULL;
	}
	else {
		while (cur->link != head) {
			prev = cur;
			cur = cur->link;
		}
		prev->link = cur->link; // ���� ����� ��ũ�� ������ ����� ���� ���� ����
		free(cur);
	}

	printf("Last node has been deleted.\n");
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->link = NULL; // ���ο� ����� ��ũ�� NULL�� �ʱ�ȭ

	if (head == NULL) {
		head = node;
		head->link = node; // ��� �ڽ��� ����Ű���� ����
	}
	else {
		node->link = head->link; // ���ο� ����� ��ũ�� ���� ������ ����� ���� ���� ����
		head->link = node; // ���� ������ ����� ��ũ�� ���ο� ���� ����
		head = node; // head�� ���ο� ���� ������Ʈ
	}

	return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	int selected;
	int num;
	while (1)
	{
		printf("(1) insert First\n(2)Insert Last\n(3)Delete First\n(4)Delete Last\n(5)Print List\n(0)Exit\nEnter the Menu :");
		scanf("%d", &selected);

		if (selected == 1)
		{
			printf("Input a number :");
			scanf("%d", &num);
			head = insert_first(head,num);
		}
		else if (selected == 2)
		{
			printf("Input a number :");
			scanf("%d", &num);
			head = insert_last(head,num);
		}
		else if (selected == 3)
		{
			head = delete_first(head);
		}
		else if (selected == 4)
		{
			head = delete_last(head);
		}
		else if (selected == 5)
		{
			print_list(head);
			printf("\n");
		}
		else if (selected == 0)
		{
			printf("program exit");
			break;
		}
	}

	head = insert_first(head, 10);
	print_list(head);
	return 0;
}
