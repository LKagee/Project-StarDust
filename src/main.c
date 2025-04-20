#include "main.h"
#include "game.h"

bool sdl_init(struct Game *game);
void sdl_cleanup(struct Game *game, int exit_status);
bool sdl_loadmedia(struct Game *game);
void update_sprite(struct Game *game);
void update_enemy1(struct Game *game); // Decleration of future A.I behavior
void directionv1(struct Game *game);
void directionv2(struct Game *game); // For later
double angle = 0;
bool left, right, down = false;
bool up = true;

int main()
{

struct Game game = {
    .window = NULL,
    .renderer = NULL,
    .img_init = 0,
    .player_image = NULL,
    .background_image = NULL,
    .player_rect = {0, 0, 0, 0},
    .player_xvol = 5,
    .player_yvol = 5,
    .keystate = SDL_GetKeyboardState(NULL),
  };
  
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
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT: {sdl_cleanup(&game, EXIT_SUCCESS); break;}
        
        case SDL_KEYDOWN: {
          switch(event.key.keysym.sym) {
            case SDLK_ESCAPE: {sdl_cleanup(&game, EXIT_SUCCESS); break;}
          }
        }
      }
    }
  update_sprite(&game);
  directionv1(&game);
  SDL_RenderClear(game.renderer);
  SDL_RenderCopy(game.renderer, game.background_image, NULL, NULL);
  SDL_RenderCopyEx(game.renderer, game.player_image, NULL, &game.player_rect, angle, NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(game.renderer);
  SDL_Delay(16);
  }
  return 0;

}


 
