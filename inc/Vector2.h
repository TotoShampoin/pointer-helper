#ifndef _VEC
#define _VEC
typedef struct {
    int x, y;
} Vector2;

Vector2 * allocVector2(int x, int y);
void updateVector2(Vector2 * vec, int x, int y);
void freeVector2(Vector2 * vec);
#endif