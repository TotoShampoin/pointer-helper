#include "../inc/main.h"

void on_mdown(Node * n[MAX_NODE], Node ** hold, Vector2 ** offset, Vector2 * m, Uint32 ms, int *holding, int *editMode, Box * box, unsigned char *nn) {
    *holding = 1;
    if(ms & SDL_BUTTON_LMASK) {
        if(box->boxOut) {
            *nn = getCharFromBox(box, m);
            box->boxOut = 0;
        } else {
            *hold = findHover(n, m, *offset);
            if(*offset) {
                *editMode = (analyseOffsetNode(*offset) == 2);
            }
        }
    }
    if(ms & SDL_BUTTON_RMASK) {
        Node * f = findHover(n, m, *offset);
        if(f) {
            if(analyseOffsetNode(*offset) == 2)
                unjoinNode(f);
            else deleteNode(n, f);
        } else addNode(n, m, nn);
        box->boxOut = 0;
    }
    if(ms & SDL_BUTTON_MMASK) {
        updateVector2(box->position, m->x, m->y);
        if(box->boxOut) box->boxOut = 0;
        else box->boxOut = 1;
    }
}
void on_mup(Node * n[MAX_NODE], Node ** hold, Vector2 * m, int *holding, int *editMode) {
    if(*editMode) {
        joinNode(n, m, hold);
        *editMode = 0;
    }
    *hold = NULL;
    *holding = 0;
}

void mouse_event(Node * n[MAX_NODE], Node ** hold, Vector2 ** offset, Vector2 * m, Uint32 ms, int *holding, int *editMode, Box * box, unsigned char *nn) {
    if(!*holding) {
        if(ms) on_mdown(n, hold, offset, m, ms, holding, editMode, box, nn);
    } else {
        if(*hold && !*editMode) {
            moveNode(*hold, m->x - (*offset)->x, m->y - (*offset)->y);
        }
        if( !ms ) on_mup(n, hold, m, holding, editMode);
    }
}