#include <stdio.h>
// 연결 리스트 노드 구조체
typedef struct {
	int data;
	struct node_t* next;
} node_t;

// 노드의 모든 데이터를 출력하는 함수
void show_list(node_t* head) {
	node_t* curr = head; // 순회용 포인터.
// head가 NULL이면 출력 불가.
	if (head == NULL) {
		printf("출력할 노드가 없습니다.\n");
	}
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

// 기존 노드의 마지막 부분에 새로운 노드를 추가하는 함수
void append(node_t** phead, int num) {
	node_t* newNode = malloc(sizeof(node_t)); // 새로운 노드
	node_t* curr = *phead; // 순회용 포인터
	
	newNode->data = num;
	newNode->next = NULL;

	// 리스트가 존재하지 않을 경우
	if (phead == NULL) {
		printf("리스트가 없습니다.\n");
		return;
	}
	// 첫 번째 노드를 삽입할 때.(빈 리스트일 경우)
	if (*phead == NULL) {
		*phead = newNode;
	}
	// 두 번째 노드부터 삽입 처리.
	else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

// 모든 노드의 메모리를 해제해주는 함수
void free_list(node_t* head) {
	node_t* curr = head;
	node_t* temp = curr;

	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}

int main() {
	// 머리 노드
	// head 노드에는 데이터를 저장하지 않는다.
	// 이는 메모리 낭비로 보여짐.
	// 이 문제를 해결하기 위해 append 함수에서 첫번째 노드를 head 노드로 설정함.
	node_t* head = NULL;

	// 노드의 끝에 새로운 노드들을 삽입한다.
	append(&head, 12);
	append(&head, 99);
	append(&head, 37);

	// 모든 노드의 데이터값 출력한다.
	show_list(head);

	// 노드 해제
	free_list(head);
	return 0;
}