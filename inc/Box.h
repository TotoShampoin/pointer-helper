#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "../inc/Vector2.h"

typedef struct {
    Vector2 * position;
    int boxOut;
} Box;

void openBox(Box * box);
void closeBox(Box * box);

void dispBox(SDL_Renderer * ren, Box * box, unsigned char chr);
unsigned char getCharFromBox(Box * box, Vector2 * m);