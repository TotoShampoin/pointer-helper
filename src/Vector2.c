#include <stdlib.h>
#include <stdio.h>

#include "../inc/Vector2.h"

Vector2 * allocVector2(int x, int y) {
    Vector2 * pos = (Vector2 *)malloc(sizeof(Vector2));
    pos->x = x; pos->y = y;
    return pos;
}
void updateVector2(Vector2 * vec, int x, int y) {
    vec->x = x;
    vec->y = y;
}
void freeVector2(Vector2 * vec) {
    free(vec);
}