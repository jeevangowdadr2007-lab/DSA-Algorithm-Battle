
#include <stdio.h>
#include <stdlib.h>

#define N 40
#define SIZE 53

int bookIDs[N] = {
    2001, 2002, 2003, 2004, 2005,
    2006, 2007, 2008, 2009, 2010,
    2011, 2012, 2013, 2014, 2015,
    2016, 2017, 2018, 2019, 2020,
    2021, 2022, 2023, 2024, 2025,
    2026, 2027, 2028, 2029, 2030,
    2031, 2032, 2033, 2034, 2035,
    2036, 2037, 2038, 2039, 2040
};



typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* bstInsert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = bstInsert(root->left, key);
    else if (key > root->key)
        root->right = bstInsert(root->right, key);

    return root;
}

int bstSearch(Node* root, int key) {
    int comparisons = 0;

    while (root != NULL) {
        comparisons++;

        if (root->key == key)
            return comparisons;

        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return comparisons;
}

int bstHeight(Node* root) {
    if (root == NULL)
        return 0;

    int left = bstHeight(root->left);
    int right = bstHeight(root->right);

    return 1 + (left > right ? left : right);
}

void bstInorder(Node* root) {
    if (root == NULL) return;
    bstInorder(root->left);
    printf("%d ", root->key);
    bstInorder(root->right);
}

void bstPreorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    bstPreorder(root->left);
    bstPreorder(root->right);
}

void bstPostorder(Node* root) {
    if (root == NULL) return;
    bstPostorder(root->left);
    bstPostorder(root->right);
    printf("%d ", root->key);
}



typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int getHeight(AVLNode* node) {
    return node == NULL ? 0 : node->height;
}

AVLNode* createAVLNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int balanceFactor(AVLNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(AVLNode* node) {
    node->height = 1 + maxValue(
        getHeight(node->left),
        getHeight(node->right)
    );
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* temp = x->right;

    x->right = y;
    y->left = temp;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* temp = y->left;

    y->left = x;
    x->right = temp;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode* avlInsert(AVLNode* root, int key) {
    if (root == NULL)
        return createAVLNode(key);

    if (key < root->key)
        root->left = avlInsert(root->left, key);
    else if (key > root->key)
        root->right = avlInsert(root->right, key);
    else
        return root;

    updateHeight(root);

    int balance = balanceFactor(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int avlSearch(AVLNode* root, int key) {
    int comparisons = 0;

    while (root != NULL) {
        comparisons++;

        if (root->key == key)
            return comparisons;

        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return comparisons;
}

void avlInorder(AVLNode* root) {
    if (root == NULL) return;
    avlInorder(root->left);
    printf("%d ", root->key);
    avlInorder(root->right);
}

void avlPreorder(AVLNode* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    avlPreorder(root->left);
    avlPreorder(root->right);
}

void avlPostorder(AVLNode* root) {
    if (root == NULL) return;
    avlPostorder(root->left);
    avlPostorder(root->right);
    printf("%d ", root->key);
}



int hashTable[SIZE];
int occupied[SIZE] = {0};
int collisions = 0;

int hashFunction(int key) {
    return key % SIZE;
}

void hashInsert(int key) {
    int index = hashFunction(key);

    while (occupied[index]) {
        collisions++;
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
    occupied[index] = 1;
}

int hashSearch(int key) {
    int index = hashFunction(key);
    int comparisons = 0;

    for (int i = 0; i < SIZE; i++) {
        comparisons++;

        if (!occupied[index])
            return comparisons;

        if (hashTable[index] == key)
            return comparisons;

        index = (index + 1) % SIZE;
    }

    return comparisons;
}


int main() {
    Node* bstRoot = NULL;
    AVLNode* avlRoot = NULL;

    printf("LIBRARY BOOK MANAGEMENT SYSTEM\n");
    printf("================================\n");

    for (int i = 0; i < N; i++) {
        bstRoot = bstInsert(bstRoot, bookIDs[i]);
        avlRoot = avlInsert(avlRoot, bookIDs[i]);
        hashInsert(bookIDs[i]);
    }

    printf("\nTotal books inserted: %d\n", N);

    printf("\nBST INORDER: ");
    bstInorder(bstRoot);

    printf("\nBST PREORDER: ");
    bstPreorder(bstRoot);

    printf("\nBST POSTORDER: ");
    bstPostorder(bstRoot);

    printf("\n\nAVL INORDER: ");
    avlInorder(avlRoot);

    printf("\nAVL PREORDER: ");
    avlPreorder(avlRoot);

    printf("\nAVL POSTORDER: ");
    avlPostorder(avlRoot);

    int successfulKey = 2020;

    printf("\n\nSUCCESSFUL SEARCH: %d\n", successfulKey);
    printf("BST comparisons: %d\n",
           bstSearch(bstRoot, successfulKey));
    printf("AVL comparisons: %d\n",
           avlSearch(avlRoot, successfulKey));
    printf("Hash comparisons: %d\n",
           hashSearch(successfulKey));

    int unsuccessfulKey = 9999;

    printf("\nUNSUCCESSFUL SEARCH: %d\n", unsuccessfulKey);
    printf("BST comparisons: %d\n",
           bstSearch(bstRoot, unsuccessfulKey));
    printf("AVL comparisons: %d\n",
           avlSearch(avlRoot, unsuccessfulKey));
    printf("Hash comparisons: %d\n",
           hashSearch(unsuccessfulKey));

    printf("\nEXPERIMENTAL RESULTS\n");
    printf("BST Height: %d\n", bstHeight(bstRoot));
    printf("AVL Height: %d\n", getHeight(avlRoot));
    printf("Hashing Collisions: %d\n", collisions);

    printf("\nINSERTING NEW BOOK ID: 2050\n");

    bstRoot = bstInsert(bstRoot, 2050);
    avlRoot = avlInsert(avlRoot, 2050);
    hashInsert(2050);

    printf("New book inserted successfully!\n");

    printf("BST search comparisons: %d\n",
           bstSearch(bstRoot, 2050));
    printf("AVL search comparisons: %d\n",
           avlSearch(avlRoot, 2050));
    printf("Hash search comparisons: %d\n",
           hashSearch(2050));

    printf("Hash collisions after new insertion: %d\n", collisions);

    printf("\nPROGRAM COMPLETED SUCCESSFULLY!\n");

    return 0;
}
