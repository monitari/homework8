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
        //printf("화면을 지웁니다 . . .\n");
        //Sleep(2000); // 2초 대기
        //system("cls");
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
        printf("%d ", ptr->key);
        inorderTraversal(ptr->right);
    }
}

void preorderTraversal(Node* ptr) { // 재귀 전위 순회
    if(ptr != NULL) { // 노드가 비어있지 않다면
        printf("%d ", ptr->key);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }

}

void postorderTraversal(Node* ptr) { // 재귀 후위 순회
    if(ptr != NULL) { // 노드가 비어있지 않다면
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf("%d ", ptr->key);
    }

}

int insert(Node* head, int key) {
    // AVT 트리로 구현
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
    Node* temp = head->left; // 루트 노드
    Node* parent = NULL; // 부모 노드
    
}

int deleteLeafNode(Node* head, int key)
{

}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}


int freeBST(Node* head)
{

}