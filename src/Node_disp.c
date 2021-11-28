#include "../inc/Node.h"

#define PAD 2

void dispNode(SDL_Renderer * ren, Node * node, Node * hold, int h, int m) {
    int c = (node == hold) ? 0xFFFFFF00 : 0xFFFFFFFF;
    int c1 = m ? 0xFF555555 : 0xFFFFFFFF;
    int c2 = m ? 0xFF555555 : c;
    int nx = node->position->x,
        ny = node->position->y;
    boxColor      (ren, nx+16, ny-16, nx+80, ny+16, 0xFF000000);
    lineColor     (ren, nx+48, ny-16, nx+48, ny+16, c2);
    rectangleColor(ren, nx+16, ny-16, nx+80, ny+16, c);
    characterColor(ren, nx+28, ny-4, node->name, c1);
    circleColor   (ren, nx+64, ny, 6, c1);
    if(node->pointer) {
        if( node->pointer == node ) {
            lineColor(ren, nx+64, ny   , nx+88, ny, h==2 ? 0xFFFFFF00 : c1);
            lineColor(ren, nx+88, ny   , nx+88, ny-24, h==2 ? 0xFFFFFF00 : c1);
            lineColor(ren, nx+88, ny-24, nx   , ny-24, h==2 ? 0xFFFFFF00 : c1);
            lineColor(ren, nx   , ny-24, nx   , ny   , h==2 ? 0xFFFFFF00 : c1);
        } else {
            int px = node->pointer->position->x,
                py = node->pointer->position->y;
            lineColor(ren, nx+64, ny, px, py, h==2 ? 0xFFFFFF00 : c1);
        }
    }
    if(node->n_pointed) {
        filledCircleColor(ren, nx, ny, 6, 0xFFFFFFFF);
        lineColor        (ren, nx, ny, nx+16, ny, 0xFFFFFFFF);
    }
    switch (h) {
    case 1:
        rectangleColor(ren, nx+16-PAD, ny-16-PAD, nx+80+PAD, ny+16+PAD, 0xFFFFFF00);
        if(m) {
            filledCircleColor(ren, nx, ny, 6, 0xFFFFFF00);
            lineColor        (ren, nx, ny, nx+16-PAD, ny, 0xFFFFFF00);
        }
        break;
    case 2:
        circleColor      (ren, nx+64, ny, 6+PAD, 0xFFFFFF00);
        break;
    default: case 0:
        break;
    }
    if(node == hold) rectangleColor(ren, nx+16-PAD, ny-16-PAD, nx+80+PAD, ny+16+PAD, 0xFFFF0000);
}

Vector2 * testHoverNode(Node * node, Vector2 * pos) {
    if(node) {
        int px = node->position->x,
            py = node->position->y;
        if(
            pos->x > px + 16 && pos->x < px + 80 &&
            pos->y > py - 16 && pos->y < py + 16
        ) {
            return allocVector2( pos->x - px, pos->y - py );
        }
    }
    return NULL;
}

int analyseOffsetNode(Vector2 * offset) {
    int dx = (64 - offset->x), dy = (0 - offset->y);
    if(
        dx*dx + dy*dy < 8*8
    ) return 2;
    if(
        offset->x >=  16 && offset->x < 80 &&
        offset->y >= -16 && offset->y < 16
    ) return 1;
    return 0;
}