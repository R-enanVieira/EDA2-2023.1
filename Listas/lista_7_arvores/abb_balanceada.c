#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5000
#define UNBALANCED -1

typedef struct Node {
    int left;
    int right;
} Node;

Node tree[MAX_NODES + 1];

int checkBalancedHeight(int node) {
    if (node == 0)
        return 0;

    int leftHeight = checkBalancedHeight(tree[node].left);
    if (leftHeight == UNBALANCED)
        return UNBALANCED;

    int rightHeight = checkBalancedHeight(tree[node].right);
    if (rightHeight == UNBALANCED)
        return UNBALANCED;

    if (abs(leftHeight - rightHeight) > 1)
        return UNBALANCED;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void addChild(int parent, int child) {
    if (tree[parent].left == 0)
        tree[parent].left = child;
    else
        tree[parent].right = child;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 2; i <= N; i++) {
        int parent;
        scanf("%d", &parent);
        addChild(parent, i);
    }

    int result = checkBalancedHeight(1);
    if (result == UNBALANCED)
        printf("Nao\n");
    else
        printf("Sim\n");

    return 0;
}
