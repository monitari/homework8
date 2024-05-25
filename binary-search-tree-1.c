/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // 시스템("cls") 함수 사용을 위한 헤더파일

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

/* 필요한 함수 선언 */
int initializeBST(Node** h);
void inorderTraversal(Node* ptr);      /* 재귀 중위 순회 */
void preorderTraversal(Node* ptr);     /* 재귀 전위 순회 */
void postorderTraversal(Node* ptr);    /* 재귀 후위 순회 */
int insert(Node* head, int key);       /* 트리에 노드 삽입 */
int deleteLeafNode(Node* head, int key); /* 트리에서 노드 삭제 */
Node* searchRecursive(Node* ptr, int key);  /* 키에 대한 노드 검색 (재귀적) */
Node* searchIterative(Node* head, int key);  /* 키에 대한 노드 검색 (반복적) */
int freeBST(Node* head); /* 트리의 모든 노드를 해제 */
/* 필요한 함수 선언 */
void freeNode(Node* ptr); /* 트리 노드 해제 */

int main() {
    char command; // 메뉴 선택을 위한 변수
    int key; // 키값
    Node* head = NULL; // 트리의 루트 노드
    Node* ptr = NULL;    // temp

    do {
        printf("\n----------------------------------------------------------------\n");
        printf("                   Binary Search Tree #1                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize BST       = z                                       \n");
        printf(" Insert Node          = n      Delete Node                  = d \n");
        printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
        printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
        printf(" Postorder Traversal  = t      Quit                         = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command); // 명령어 입력

        switch(command) { // 명령어에 따른 동작
        case 'z': case 'Z':
            initializeBST(&head);
            break;
        case 'q': case 'Q':
            freeBST(head);
            break;
        case 'n': case 'N':
            printf("당신의 키 = ");
            scanf("%d", &key);
            insert(head, key);
            break;
        case 'd': case 'D':
            printf("당신의 키 = ");
            scanf("%d", &key);
            deleteLeafNode(head, key);
            break;
        case 'f': case 'F':
            printf("당신의 키 = ");
            scanf("%d", &key);
            ptr = searchIterative(head, key);
            if(ptr != NULL) printf("\n 노드 [%d]를 %p에서 찾았습니다.\n", ptr->key, ptr);
            else printf("\n 노드 [%d]를 찾을 수 없습니다.\n", key);
            break;
        case 's': case 'S':
            printf("당신의 키 = ");
            scanf("%d", &key);
            ptr = searchRecursive(head->left, key);
            if(ptr != NULL) printf("\n 노드 [%d]를 %p에서 찾았습니다.\n", ptr->key, ptr);
            else printf("\n 노드 [%d]를 찾을 수 없습니다.\n", key);
            break;
        case 'i': case 'I':
            inorderTraversal(head->left);
            break;
        case 'p': case 'P':
            preorderTraversal(head->left);
            break;
        case 't': case 'T':
            postorderTraversal(head->left);
            break;
        default:
            printf("---------------------- 2023041018 김준후 -----------------------\n");
            break;
        }
        printf("화면을 지웁니다 . . .\n");
        Sleep(2000); // 2초 대기
        system("cls");
    } while (command != 'q' && command != 'Q'); // q나 Q를 입력받으면 종료
    return 1;
}

int initializeBST(Node** h) { // 트리 초기화
    if(*h != NULL) freeBST(*h); // 트리가 비어있지 않다면 해제
    *h = (Node*)malloc(sizeof(Node)); // 루트 노드 메모리 할당
    (*h)->left = NULL; // 루트 노드의 왼쪽 자식 노드 초기화
    (*h)->right = NULL; // 루트 노드의 오른쪽 자식 노드 초기화
    (*h)->key = -9999; // 루트 노드의 키값 초기화
    return 1;
}

void inorderTraversal(Node* ptr) { // 재귀 중위 순회
    if(ptr != NULL) { // 노드가 비어있지 않다면
        inorderTraversal(ptr->left);
        printf(" [%d] ", ptr->key);
        inorderTraversal(ptr->right);
    }
}

void preorderTraversal(Node* ptr) { // 재귀 전위 순회
    if(ptr != NULL) { // 노드가 비어있지 않다면
        printf(" [%d] ", ptr->key);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }
}

void postorderTraversal(Node* ptr) { // 재귀 후위 순회
    if(ptr != NULL) { // 노드가 비어있지 않다면
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf(" [%d] ", ptr->key);
    }
}

int insert(Node* head,int key) { // 트리에 노드 삽입
    Node* newnode=(Node*)malloc(sizeof(Node)); // 새로운 노드 메모리 할당
    newnode->left=NULL; // 새로운 노드의 왼쪽 자식 노드 초기화
    newnode->right=NULL; // 새로운 노드의 오른쪽 자식 노드 초기화
    newnode->key=key; // 새로운 노드의 키값 초기화

    if(head->left==NULL) { // 루트 노드의 왼쪽 자식 노드가 비어있다면
        head->left=newnode; // 루트 노드의 왼쪽 자식 노드에 새로운 노드 삽입
        return 0;
    }

    Node* ptr=head->left; // 루트 노드의 왼쪽 자식 노드를 ptr에 저장
    Node* parent=NULL; // 부모 노드 초기화

    while(ptr!=NULL) { // ptr이 NULL이 아닐 때까지 반복
        if(ptr->key==key) return 0; // 키값이 중복되면 종료
        parent=ptr; // 부모 노드에 ptr 저장
        if(ptr->key<key) ptr=ptr->right; // 키값이 더 크면 오른쪽 자식 노드로 이동
        else ptr=ptr->left; // 키값이 더 작으면 왼쪽 자식 노드로 이동
    }
    if(parent->key<key) parent->right=newnode; // 부모 노드의 키값이 더 작으면 오른쪽 자식 노드에 삽입
    else parent->left=newnode; // 부모 노드의 키값이 더 크면 왼쪽 자식 노드에 삽입
    return 0;
}

int deleteLeafNode(Node* head, int key) { // 트리에서 노드 삭제
    if(head == NULL || head->left == NULL) { // 트리가 비어있거나 루트 노드의 왼쪽 자식 노드가 비어있다면
        printf("삭제할 노드가 없습니다\n"); // 삭제할 노드가 없다고 출력, 종료
        return 0;
    }
    Node* ptr = head->left; // 루트 노드의 왼쪽 자식 노드를 ptr에 저장
    Node* parent = head; // 부모 노드 초기화 (루트 노드)
    while(ptr!=NULL) { // ptr이 NULL이 아닐 때까지 반복
        if(ptr->key == key) { // ptr의 키값이 삭제할 키값과 같다면
            if(ptr->left == NULL && ptr->right == NULL) { // ptr의 왼쪽 자식 노드와 오른쪽 자식 노드가 모두 비어있다면
                if(parent == head) head->left = NULL; // 부모 노드가 루트 노드라면 루트 노드의 왼쪽 자식 노드를 NULL로 초기화
                if(parent->left == ptr) parent->left = NULL; // 부모 노드의 왼쪽 자식 노드가 ptr이라면 부모 노드의 왼쪽 자식 노드를 NULL로 초기화
                else parent->right=NULL; // 부모 노드의 오른쪽 자식 노드가 ptr이라면 부모 노드의 오른쪽 자식 노드를 NULL로 초기화
                free(ptr); // ptr 메모리 해제
            }
            else printf(" [%d]는 단말 노드가 아닙니다\n", key); // 단말 노드가 아니라면 출력
            return 0;
        }
        parent = ptr; // 부모 노드에 ptr 저장
        if(parent->key<key) ptr = ptr->right; // 부모 노드의 키값이 더 작으면 오른쪽 자식 노드로 이동
        else ptr = ptr->left; // 부모 노드의 키값이 더 크면 왼쪽 자식 노드로 이동
    }
    printf("노드를 찾을 수 없습니다\n");
    return 0;
}

Node* searchRecursive(Node* ptr, int key) { // 키에 대한 노드 검색 (재귀적)
    if(ptr==NULL) return NULL; // ptr이 NULL이면 종료
    if(ptr->key<key) ptr=searchRecursive(ptr->right,key); // ptr의 키값이 더 작으면 오른쪽 자식 노드로 이동
    else if(ptr->key>key) ptr=searchRecursive(ptr->left,key); // ptr의 키값이 더 크면 왼쪽 자식 노드로 이동
    return ptr;
}

Node* searchIterative(Node* head, int key) { // 키에 대한 노드 검색 (반복적)
    Node* ptr=head->left; // 루트 노드의 왼쪽 자식 노드를 ptr에 저장
    while(ptr!=NULL) { // ptr이 NULL이 아닐 때까지 반복
        if(ptr->key==key) return ptr; // ptr의 키값이 찾는 키값과 같다면 ptr 반환
        if(ptr->key<key) ptr=ptr->right; // ptr의 키값이 더 작으면 오른쪽 자식 노드로 이동
        else ptr=ptr->left; // ptr의 키값이 더 크면 왼쪽 자식 노드로 이동
    }
    return NULL;
}

int freeBST(Node* head) { // 트리의 모든 노드를 해제
	if(head->left == head) { // 루트 노드의 왼쪽 자식 노드가 루트 노드라면
		free(head); // 루트 노드 메모리 해제
		return 1;
	}
	Node* p = head->left; // 루트 노드의 왼쪽 자식 노드를 p에 저장
	freeNode(p); // p 노드 해제
	free(head); // 루트 노드 해제
	return 1;
}

void freeNode(Node* ptr) { // 트리 노드 해제
	if(ptr) { // ptr이 NULL이 아니라면
		freeNode(ptr->left); // 왼쪽 자식 노드 해제
		freeNode(ptr->right); // 오른쪽 자식 노드 해제
		free(ptr); // ptr 노드 해제
	}
}