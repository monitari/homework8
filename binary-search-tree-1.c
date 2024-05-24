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
#include <windows.h> // �ý���("cls") �Լ� ����� ���� �������

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

/* �ʿ��� �Լ� ���� */
int initializeBST(Node** h);
void inorderTraversal(Node* ptr);      /* ��� ���� ��ȸ */
void preorderTraversal(Node* ptr);     /* ��� ���� ��ȸ */
void postorderTraversal(Node* ptr);    /* ��� ���� ��ȸ */
int insert(Node* head, int key);       /* Ʈ���� ��� ���� */
int deleteLeafNode(Node* head, int key); /* Ʈ������ ��� ���� */
Node* searchRecursive(Node* ptr, int key);  /* Ű�� ���� ��� �˻� (�����) */
Node* searchIterative(Node* head, int key);  /* Ű�� ���� ��� �˻� (�ݺ���) */
int freeBST(Node* head); /* Ʈ���� ��� ��带 ���� */
/* �ʿ��� �Լ� ���� */

int main() {
    char command; // �޴� ������ ���� ����
    int key; // Ű��
    Node* head = NULL; // Ʈ���� ��Ʈ ���
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
        scanf(" %c", &command); // ��ɾ� �Է�

        switch(command) { // ��ɾ ���� ����
        case 'z': case 'Z':
            initializeBST(&head);
            break;
        case 'q': case 'Q':
            freeBST(head);
            break;
        case 'n': case 'N':
            printf("����� Ű = ");
            scanf("%d", &key);
            insert(head, key);
            break;
        case 'd': case 'D':
            printf("����� Ű = ");
            scanf("%d", &key);
            deleteLeafNode(head, key);
            break;
        case 'f': case 'F':
            printf("����� Ű = ");
            scanf("%d", &key);
            ptr = searchIterative(head, key);
            if(ptr != NULL) printf("\n ��� [%d]�� %p���� ã�ҽ��ϴ�.\n", ptr->key, ptr);
            else printf("\n ��� [%d]�� ã�� �� �����ϴ�.\n", key);
            break;
        case 's': case 'S':
            printf("����� Ű = ");
            scanf("%d", &key);
            ptr = searchRecursive(head->left, key);
            if(ptr != NULL) printf("\n ��� [%d]�� %p���� ã�ҽ��ϴ�.\n", ptr->key, ptr);
            else printf("\n ��� [%d]�� ã�� �� �����ϴ�.\n", key);
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
            printf("---------------------- 2023041018 ������ -----------------------\n");
            break;
        }
        //printf("ȭ���� ����ϴ� . . .\n");
        //Sleep(2000); // 2�� ���
        //system("cls");
    } while (command != 'q' && command != 'Q'); // q�� Q�� �Է¹����� ����
    return 1;
}

int initializeBST(Node** h) { // Ʈ�� �ʱ�ȭ
    if(*h != NULL) freeBST(*h); // Ʈ���� ������� �ʴٸ� ����
    *h = (Node*)malloc(sizeof(Node)); // ��Ʈ ��� �޸� �Ҵ�
    (*h)->left = NULL; // ��Ʈ ����� ���� �ڽ� ��� �ʱ�ȭ
    (*h)->right = NULL; // ��Ʈ ����� ������ �ڽ� ��� �ʱ�ȭ
    (*h)->key = -9999; // ��Ʈ ����� Ű�� �ʱ�ȭ
    return 1;
}

void inorderTraversal(Node* ptr) { // ��� ���� ��ȸ
    if(ptr != NULL) { // ��尡 ������� �ʴٸ�
        inorderTraversal(ptr->left);
        printf("%d ", ptr->key);
        inorderTraversal(ptr->right);
    }
}

void preorderTraversal(Node* ptr) { // ��� ���� ��ȸ
    if(ptr != NULL) { // ��尡 ������� �ʴٸ�
        printf("%d ", ptr->key);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }

}

void postorderTraversal(Node* ptr) { // ��� ���� ��ȸ
    if(ptr != NULL) { // ��尡 ������� �ʴٸ�
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf("%d ", ptr->key);
    }

}

int insert(Node* head, int key) {
    // AVT Ʈ���� ����
    Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����
    Node* temp = head->left; // ��Ʈ ���
    Node* parent = NULL; // �θ� ���
    
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