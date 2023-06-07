#include<stdio.h>
#include<stdlib.h>


typedef int element;
typedef struct ListNode { 	// 노드 타입
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
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
		// 리스트에 노드가 한 개만 존재하는 경우
		free(cur);
		head = NULL;
	}
	else {
		while (cur->link != head) {
			prev = cur;
			cur = cur->link;
		}
		prev->link = cur->link; // 이전 노드의 링크를 삭제된 노드의 다음 노드로 연결
		free(cur);
	}

	printf("Last node has been deleted.\n");
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->link = NULL; // 새로운 노드의 링크를 NULL로 초기화

	if (head == NULL) {
		head = node;
		head->link = node; // 노드 자신을 가리키도록 설정
	}
	else {
		node->link = head->link; // 새로운 노드의 링크를 현재 마지막 노드의 다음 노드로 설정
		head->link = node; // 이전 마지막 노드의 링크를 새로운 노드로 설정
		head = node; // head를 새로운 노드로 업데이트
	}

	return head; // 변경된 헤드 포인터를 반환한다.
}

// 리스트의 항목 출력
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
