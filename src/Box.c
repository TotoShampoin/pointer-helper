#include "../inc/Box.h"

void dispBox(SDL_Renderer * ren, Box * box, unsigned char chr) {
    Vector2 * p = box->position;
    boxColor      (ren, p->x, p->y, p->x+(16*12)   , p->y+(16*12)   , 0xFF000000);
    rectangleColor(ren, p->x, p->y, p->x+(16*12)+12, p->y+(16*12)+12, 0xFFFFFFFF);
    int cx = chr%16, cy = chr/16;
    boxColor(ren, 
        cx*12 +  4+2 + p->x, cy*12 +  4+2 + p->y,
        cx*12 + 16+1 + p->x, cy*12 + 16+1 + p->y,
        0xFFFF0000);
    for(int i=0; i<256; i++) {
        int x = i%16, y = i/16;
        characterColor(ren, x*12 + 8 + p->x, y*12 + 8 + p->y, i, (i==chr)?0xFFFFFF00:0xFFFFFFFF);
    }
}

unsigned char getCharFromBox(Box * box, Vector2 * m) {
    Vector2 * p = box->position;
    int px = (m->x - p->x - 6)/12, py = (m->y - p->y - 6)/12;
    if( px >= 0 && px < 16 && py >= 0 && py < 16 )
        return (px + py * 16);
    return 0;
}
