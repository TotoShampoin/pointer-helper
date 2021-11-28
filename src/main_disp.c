#include "../inc/main.h"

void init(int width, int height, Uint32 rate, int scale) {
    SDL_CreateWindowAndRenderer(width*scale, height*scale, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &win, &ren);
    SDL_SetWindowTitle(win, "Pointer Helper");
    SDL_initFramerate(&man);
    SDL_setFramerate(&man, rate);
    SDL_RenderSetScale(ren, scale, scale);
    SDL_Surface * icon = SDL_LoadBMP("assets/icon.bmp");
    SDL_SetWindowIcon(win, icon);
    SDL_FreeSurface(icon);
    SDL_Cursor * curs = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
    SDL_SetCursor(curs);
}

int get_quit() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) if(event.type == SDL_QUIT) return 1;
    return 0;
}

void disp(Node * n[MAX_NODE], Node * hold, Vector2 * mouse, int edit, Box * box, unsigned char nn) {
    int w, h; SDL_GetRendererOutputSize(ren, &w, &h);
    boxColor(ren, 0, 0, w, h, 0xFF000000);
    dispNodes(n, hold, mouse, edit);
    disp_count_nodes(n);
    characterColor(ren, 96, 0, nn, 0xFFFFFFFF);
    if(box->boxOut) {
        dispBox(ren, box, getCharFromBox(box, mouse));
    }
    SDL_RenderPresent(ren);
}

void dispNodes(Node * n[MAX_NODE], Node * hold, Vector2 * mouse, int edit) {
    int hoverItself = 0;
    Vector2 e = { .x = mouse->x, .y = mouse->y };
    for(int i=0; i<MAX_NODE; i++)
        if(n[i] != NULL) {
            Vector2 * offset = testHoverNode(n[i], mouse);
            dispNode(ren, n[i], hold, offset ? (edit ? 1 : analyseOffsetNode(offset)) : 0, edit);
            if( offset ) {
                if( hold == findHover(n, &e, NULL) ) hoverItself = 1;
                e.x = n[i]->position->x; e.y = n[i]->position->y;
            }
            freeVector2(offset);
        }
    if(hold && edit) {
        Vector2 * hp = hold->position;
        if( hoverItself ) {
            lineColor(ren, hp->x+64, hp->y   , hp->x+88, hp->y   , 0xFFFFFF00);
            lineColor(ren, hp->x+88, hp->y   , hp->x+88, hp->y-24, 0xFFFFFF00);
            lineColor(ren, hp->x+88, hp->y-24, hp->x   , hp->y-24, 0xFFFFFF00);
            lineColor(ren, hp->x   , hp->y-24, hp->x   , hp->y   , 0xFFFFFF00);
        } else {
            lineColor(ren, hp->x+64, hp->y, e.x, e.y, 0xFFFFFF00);
        }
    }
}

void disp_count_nodes(Node * n[MAX_NODE]) {
    char str[10];
    sprintf(str, "%3d /%d", count_nodes(n), MAX_NODE);
    stringColor(ren, 0, 0, str, 0xFFFFFFFF);
}
