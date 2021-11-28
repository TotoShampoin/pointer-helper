#include "../inc/Node.h"

Node * allocNode(char name, Vector2 * pos, Node * pointer) {
    Node * new = malloc(sizeof(Node));
    new->name = name;
    new->position = pos;
    new->pointer = pointer;
    new->n_pointed = 0;
    return new;
}
void freeNode(Node * node) {
    free(node);
}

void moveNode(Node * node, int x, int y) {
    updateVector2(node->position, x, y);
}