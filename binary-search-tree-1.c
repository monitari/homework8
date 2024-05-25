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
void freeNode(Node* ptr); /* Ʈ�� ��� ���� */

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
        printf("ȭ���� ����ϴ� . . .\n");
        Sleep(2000); // 2�� ���
        system("cls");
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
        printf(" [%d] ", ptr->key);
        inorderTraversal(ptr->right);
    }
}

void preorderTraversal(Node* ptr) { // ��� ���� ��ȸ
    if(ptr != NULL) { // ��尡 ������� �ʴٸ�
        printf(" [%d] ", ptr->key);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }
}

void postorderTraversal(Node* ptr) { // ��� ���� ��ȸ
    if(ptr != NULL) { // ��尡 ������� �ʴٸ�
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf(" [%d] ", ptr->key);
    }
}

int insert(Node* head,int key) { // Ʈ���� ��� ����
    Node* newnode=(Node*)malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
    newnode->left=NULL; // ���ο� ����� ���� �ڽ� ��� �ʱ�ȭ
    newnode->right=NULL; // ���ο� ����� ������ �ڽ� ��� �ʱ�ȭ
    newnode->key=key; // ���ο� ����� Ű�� �ʱ�ȭ

    if(head->left==NULL) { // ��Ʈ ����� ���� �ڽ� ��尡 ����ִٸ�
        head->left=newnode; // ��Ʈ ����� ���� �ڽ� ��忡 ���ο� ��� ����
        return 0;
    }

    Node* ptr=head->left; // ��Ʈ ����� ���� �ڽ� ��带 ptr�� ����
    Node* parent=NULL; // �θ� ��� �ʱ�ȭ

    while(ptr!=NULL) { // ptr�� NULL�� �ƴ� ������ �ݺ�
        if(ptr->key==key) return 0; // Ű���� �ߺ��Ǹ� ����
        parent=ptr; // �θ� ��忡 ptr ����
        if(ptr->key<key) ptr=ptr->right; // Ű���� �� ũ�� ������ �ڽ� ���� �̵�
        else ptr=ptr->left; // Ű���� �� ������ ���� �ڽ� ���� �̵�
    }
    if(parent->key<key) parent->right=newnode; // �θ� ����� Ű���� �� ������ ������ �ڽ� ��忡 ����
    else parent->left=newnode; // �θ� ����� Ű���� �� ũ�� ���� �ڽ� ��忡 ����
    return 0;
}

int deleteLeafNode(Node* head, int key) { // Ʈ������ ��� ����
    if(head == NULL || head->left == NULL) { // Ʈ���� ����ְų� ��Ʈ ����� ���� �ڽ� ��尡 ����ִٸ�
        printf("������ ��尡 �����ϴ�\n"); // ������ ��尡 ���ٰ� ���, ����
        return 0;
    }
    Node* ptr = head->left; // ��Ʈ ����� ���� �ڽ� ��带 ptr�� ����
    Node* parent = head; // �θ� ��� �ʱ�ȭ (��Ʈ ���)
    while(ptr!=NULL) { // ptr�� NULL�� �ƴ� ������ �ݺ�
        if(ptr->key == key) { // ptr�� Ű���� ������ Ű���� ���ٸ�
            if(ptr->left == NULL && ptr->right == NULL) { // ptr�� ���� �ڽ� ���� ������ �ڽ� ��尡 ��� ����ִٸ�
                if(parent == head) head->left = NULL; // �θ� ��尡 ��Ʈ ����� ��Ʈ ����� ���� �ڽ� ��带 NULL�� �ʱ�ȭ
                if(parent->left == ptr) parent->left = NULL; // �θ� ����� ���� �ڽ� ��尡 ptr�̶�� �θ� ����� ���� �ڽ� ��带 NULL�� �ʱ�ȭ
                else parent->right=NULL; // �θ� ����� ������ �ڽ� ��尡 ptr�̶�� �θ� ����� ������ �ڽ� ��带 NULL�� �ʱ�ȭ
                free(ptr); // ptr �޸� ����
            }
            else printf(" [%d]�� �ܸ� ��尡 �ƴմϴ�\n", key); // �ܸ� ��尡 �ƴ϶�� ���
            return 0;
        }
        parent = ptr; // �θ� ��忡 ptr ����
        if(parent->key<key) ptr = ptr->right; // �θ� ����� Ű���� �� ������ ������ �ڽ� ���� �̵�
        else ptr = ptr->left; // �θ� ����� Ű���� �� ũ�� ���� �ڽ� ���� �̵�
    }
    printf("��带 ã�� �� �����ϴ�\n");
    return 0;
}

Node* searchRecursive(Node* ptr, int key) { // Ű�� ���� ��� �˻� (�����)
    if(ptr==NULL) return NULL; // ptr�� NULL�̸� ����
    if(ptr->key<key) ptr=searchRecursive(ptr->right,key); // ptr�� Ű���� �� ������ ������ �ڽ� ���� �̵�
    else if(ptr->key>key) ptr=searchRecursive(ptr->left,key); // ptr�� Ű���� �� ũ�� ���� �ڽ� ���� �̵�
    return ptr;
}

Node* searchIterative(Node* head, int key) { // Ű�� ���� ��� �˻� (�ݺ���)
    Node* ptr=head->left; // ��Ʈ ����� ���� �ڽ� ��带 ptr�� ����
    while(ptr!=NULL) { // ptr�� NULL�� �ƴ� ������ �ݺ�
        if(ptr->key==key) return ptr; // ptr�� Ű���� ã�� Ű���� ���ٸ� ptr ��ȯ
        if(ptr->key<key) ptr=ptr->right; // ptr�� Ű���� �� ������ ������ �ڽ� ���� �̵�
        else ptr=ptr->left; // ptr�� Ű���� �� ũ�� ���� �ڽ� ���� �̵�
    }
    return NULL;
}

int freeBST(Node* head) { // Ʈ���� ��� ��带 ����
	if(head->left == head) { // ��Ʈ ����� ���� �ڽ� ��尡 ��Ʈ �����
		free(head); // ��Ʈ ��� �޸� ����
		return 1;
	}
	Node* p = head->left; // ��Ʈ ����� ���� �ڽ� ��带 p�� ����
	freeNode(p); // p ��� ����
	free(head); // ��Ʈ ��� ����
	return 1;
}

void freeNode(Node* ptr) { // Ʈ�� ��� ����
	if(ptr) { // ptr�� NULL�� �ƴ϶��
		freeNode(ptr->left); // ���� �ڽ� ��� ����
		freeNode(ptr->right); // ������ �ڽ� ��� ����
		free(ptr); // ptr ��� ����
	}
}