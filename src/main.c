#include "main.h"
#include "game.h"

bool sdl_init(Game *game);
void sdl_cleanup(Game *game, int exit_status);
bool sdl_loadmedia(Game *game);
void update_sprite(Game *game);
void update_enemy1(Game *game); // Decleration of future A.I behavior
void directionv1(Game *game);
void directionv2(Game *game); // For later
void directionbullet(Game *game);
void weapons_handling(Game *game);
// bool check(Game* game);

Bullet* AllocBullet(Game* game);
void DeallocBullet(Game* game, int bulletIndex);
void CreateBullet(Game* game);
void updateBullets(Game* game);
void renderBullets(Game* game);


double angle = 0;
double angle_rad = 0;
double bulangle = 0;
bool left, right, down = false;
bool up = true;
int i = 1;
int count = 0;
float Vx, Vy = 0;

int main()
{  
    Game game;
    game.keystate = SDL_GetKeyboardState(NULL);


    /* game.window = NULL,
    game.renderer = NULL,
    game.img_init = 0,
    game.player_image = NULL,
    game.background_image = NULL,
    game.plasma_image = NULL,
    game.player_rect = {0, 0, 0, 0},
    game.bullet_dist = {0, 100, 50, 50},
   // .plasma_rect = {0, 0, 0, 0},

    game.plasma_rect[0].x = 0,
    game.plasma_rect[0].y = 0,
    game.plasma_rect[0].h = 50,
    game.plasma_rect[0].w = 50,

    game.plasma_rect[1].x = 0,
    game.plasma_rect[1].y = 100,
    game.plasma_rect[1].h = 50,
    game.plasma_rect[1].w = 50,

    game.player_xvol = 5, 
    game.player_yvol = 5,
    game.keystate = SDL_GetKeyboardState(NULL),
    
  */
  
  if(sdl_init(&game)) {
    sdl_cleanup(&game, EXIT_FAILURE);
      return 0;
  }
  
  if(sdl_loadmedia(&game)) {
    sdl_cleanup(&game, EXIT_FAILURE);
      return 0;
  }


  while(true) {
    SDL_Point center = {10, -20}; // Testing
    SDL_Event event;
    bool firegun = false;
  /* game.bullet_dist.x = game.player_rect.x + 25;
    game.bullet_dist.y = game.player_rect.y + 40; */

    
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT: {sdl_cleanup(&game, EXIT_SUCCESS); break;}
        
        case SDL_KEYDOWN: {
          switch(event.key.keysym.sym) {
            case SDLK_ESCAPE: {sdl_cleanup(&game, EXIT_SUCCESS); break;}
            case SDLK_SPACE: {CreateBullet(&game); i = 0; printf("%d\n", i); break;}
          }
        }
      }
    }

   
  update_sprite(&game);
  //directionv1(&game);
  directionbullet(&game);

  updateBullets(&game);
  SDL_RenderClear(game.renderer);
  renderBullets(&game);
  SDL_RenderCopy(game.renderer, game.background_image, NULL, NULL);
  SDL_RenderCopyEx(game.renderer, game.player_image, NULL, &game.player_rect, angle, NULL, SDL_FLIP_NONE);
   /* if(i == 1) {
  SDL_RenderCopyEx(game.renderer, game.plasma_image, &game.plasma_rect[i], &game.bullet_dist, angle - 90, NULL, SDL_FLIP_NONE);
   }

    if(i == 0) { 
      if(count == 0) {
      game.plasma_rect[i].x = game.player_rect.x;
      game.plasma_rect[i].y = game.player_rect.y;
      weapons_handling(&game);
      bulangle = angle - 90;
        count++;
      }
    // SDL_RenderCopy(game.renderer, game.plasma_image, NULL, &game.plasma_rect[i]);
  SDL_RenderCopyEx(game.renderer, game.plasma_image, NULL, &game.plasma_rect[i], bulangle, NULL, SDL_FLIP_NONE);
 if(check(&game)) {
      i = 1;
      count = 0;
      Vx = 0;
      Vy = 0;
    }
  } */

  SDL_RenderPresent(game.renderer);
  SDL_Delay(16);
  }
  return 0;

}


 
