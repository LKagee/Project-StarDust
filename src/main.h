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
extern bool right, left, down, up, firegun;
extern double angle, angle_rad, bulangle;
extern int i, count;
extern float Vx, Vy;

/* PLACEHOLDER FOR FUTURE ENEMY STRUCT */

struct Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *player_image;
  SDL_Texture *background_image;
  SDL_Texture *plasma_image;
  SDL_Rect player_rect;
  SDL_Rect bullet_dist;
  SDL_Rect plasma_rect[2];
  int player_xvol;
  int player_yvol;
  int img_init;
  const Uint8 *keystate;
};



#endif
