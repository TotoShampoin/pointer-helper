#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL2_framerate.h>

#include "../inc/Node.h"
#include "../inc/Box.h"

#define MAX_NODE 256

SDL_Window * win; SDL_Renderer * ren; FPSmanager man;

void init(int width, int height, Uint32 rate, int scale);
int get_quit();


void addNode(Node * n[MAX_NODE], Vector2 * m, unsigned char *nn);
void deleteNodeIndex(Node * n [MAX_NODE], int i);
void deleteNode(Node * n [MAX_NODE], Node * f);
void joinNode(Node * n[MAX_NODE], Vector2 * m, Node ** hold);
void unjoinNode(Node * f);
void resetNodes(Node * n[MAX_NODE]);

Node * findHover(Node * n[MAX_NODE], Vector2 * p, Vector2 * offset);
int findIndexNode(Node * n[MAX_NODE], Node * find);
Node * findPointingNode(Node * n[MAX_NODE], Node * find);


void disp(Node * n[MAX_NODE], Node * hold, Vector2 * mouse, int edit, Box * box, unsigned char nn);
void dispNodes(Node * n[MAX_NODE], Node * hold, Vector2 * mouse, int edit);
void disp_count_nodes(Node * n[MAX_NODE]);
int count_nodes(Node * n[MAX_NODE]);


void on_mdown(Node * n[MAX_NODE], Node ** hold, Vector2 ** offset, Vector2 * m, Uint32 ms, int *holding, int *editMode, Box * box, unsigned char *nn);
void on_mup(Node * n[MAX_NODE], Node ** hold, Vector2 * m, int *holding, int *editMode);
void mouse_event(Node * n[MAX_NODE], Node ** hold, Vector2 ** offset, Vector2 * m, Uint32 ms, int *holding, int *editMode, Box * box, unsigned char *nn);