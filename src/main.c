#include "../inc/main.h"

#define WIDTH  640
#define HEIGHT 480
#define SCALE  1

void all_events( Node * nodes[MAX_NODE], Node ** hold, Vector2 ** offset, Vector2 * mouse, Uint32 m_state, int *holding, int *editMode, Box * box, unsigned char *newname, int * nkeys, Uint8 * k_state ) {
    mouse_event( nodes, hold, offset, mouse, m_state, holding , editMode, box, newname);
}

int main(int argc, char const *argv[]) {
    int holding, editMode, nkeys;
    unsigned char newname;
    Uint32 m_state; Uint8 * k_state;
    Vector2 mouse, * offset;
    Node * nodes[MAX_NODE], * hold;
    Box box;
    
    holding = 0; editMode = 0; newname = '0';
    m_state = 0; k_state = NULL;
    for(int i=0; i<MAX_NODE; i++) nodes[i] = NULL;
    hold = NULL; offset = allocVector2(0, 0);
    box.boxOut = 0; box.position = allocVector2(0,0);
    
    init(WIDTH, HEIGHT, 60, SCALE);
    
    while( !get_quit() ) {
        SDL_PumpEvents();
        m_state = SDL_GetMouseState(&mouse.x, &mouse.y);
        k_state = SDL_GetKeyboardState(&nkeys);
        mouse.x /= SCALE; mouse.y /= SCALE;
        all_events( nodes, &hold, &offset, &mouse, m_state, &holding , &editMode, &box, &newname, &nkeys, k_state);
        disp(nodes, hold, &mouse, editMode, &box, newname);
        SDL_framerateDelay(&man);
    }
    
    freeVector2(offset); freeVector2(box.position);
    for(int i=0; i<MAX_NODE; i++)
        freeNode(nodes[i]);
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    
    return 0;
}
