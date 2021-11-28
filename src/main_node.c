#include "../inc/main.h"

void addNode(Node * n[MAX_NODE], Vector2 * m, unsigned char *nn) {
    for(int i=0; i<MAX_NODE; i++) {
        if(n[i] == NULL) {
            n[i] = allocNode((*nn)++, allocVector2(m->x, m->y), NULL);
            break;
        }
    }
}
void deleteNodeIndex(Node * n [MAX_NODE], int i) {
    if( n[i]->n_pointed == 0 && n[i]->pointer == NULL) {
        freeVector2(n[i]->position);
        freeNode(n[i]);
        n[i] = NULL;
    }
}
void deleteNode(Node * n [MAX_NODE], Node * f) {
    deleteNodeIndex( n , findIndexNode(n, f) );
}
void joinNode(Node * n[MAX_NODE], Vector2 * m, Node ** hold) {
    Node * affect = findHover(n, m, NULL);
    if(affect) {
        unjoinNode(*hold);
        (*hold)->pointer = affect;
        affect->n_pointed++;
    }
}
void unjoinNode(Node * f) {
    if(f->pointer) {
        f->pointer->n_pointed--;
        f->pointer = NULL;
    }
}
void resetNodes(Node * n[MAX_NODE]) {
    for(int i=0; i<MAX_NODE; i++) unjoinNode(n[i]);
    for(int i=0; i<MAX_NODE; i++) deleteNodeIndex(n, i);
}

Node * findHover(Node * n[MAX_NODE], Vector2 * p, Vector2 * offset) {
    for(int i=0; i<MAX_NODE; i++) {
        Vector2 * tmp = testHoverNode(n[i], p);
        if(tmp) {
            if(offset) {
                offset->x = tmp->x; offset->y = tmp->y;
            }
            freeVector2(tmp);
            return n[i];
        }
        freeVector2(tmp);
    }
    return NULL;
}

int findIndexNode(Node * n[MAX_NODE], Node * find) {
    for(int i=0; i<MAX_NODE; i++)
        if( n[i] == find )
            return i;
    return -1;
}

Node * findPointingNode(Node * n[MAX_NODE], Node * find) {
    for(int i=0; i<MAX_NODE; i++)
        if( n[i] && n[i]->pointer == find )
            return n[i];
    return NULL;
}

int count_nodes(Node * n[MAX_NODE]) {
    int nc = 0;
    for(int i=0; i<MAX_NODE; i++) if(n[i] != NULL) nc++;
    return nc;
}
