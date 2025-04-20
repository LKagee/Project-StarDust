#ifndef MAIN_H
#define MAIN_H
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h> 
#include <math.h>   
#define WINDOW_NAME "StarDust"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define SDL_FLAGS SDL_INIT_EVERYTHING
#define IMG_FLAGS IMG_INIT_PNG 
extern bool right, left, down, up;
extern double angle;

/* PLACEHOLDER FOR FUTURE ENEMY STRUCT */

struct Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *player_image;
  SDL_Texture *background_image;
  SDL_Rect player_rect;
  int player_xvol;
  int player_yvol;
  int img_init;
  const Uint8 *keystate;
};



#endif
