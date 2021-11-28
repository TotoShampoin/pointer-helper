#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "../inc/Vector2.h"

typedef struct _n {
    char name;
    Vector2 * position;
    struct _n * pointer;
    int n_pointed;
} Node;

Node * allocNode(char name, Vector2 * pos, Node * pointer);
void freeNode(Node * node);
void moveNode(Node * node, int x, int y);

void dispNode(SDL_Renderer * ren, Node * node, Node * hold, int h, int m);

Vector2 * testHoverNode(Node * node, Vector2 * pos);
int analyseOffsetNode(Vector2 * offset);