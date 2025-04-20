#include "game.h"
#include "main.h"
  
void update_sprite(struct Game *game) {
  if(game->keystate[SDL_SCANCODE_W]) {
    game->player_rect.y -= game->player_yvol;
       if(game->keystate[SDL_SCANCODE_LSHIFT]) {
      game->player_rect.y -= 5;
    }
  }

  if(game->keystate[SDL_SCANCODE_A]) {
    game->player_rect.x -= game->player_xvol;
      if(game->keystate[SDL_SCANCODE_LSHIFT]) {
      game->player_rect.x -= 5;
    }
  }
  if(game->keystate[SDL_SCANCODE_S]) {
    game->player_rect.y += game->player_yvol;
       if(game->keystate[SDL_SCANCODE_LSHIFT]) {
      game->player_rect.y += 5;
    }
  }
  if(game->keystate[SDL_SCANCODE_D]) {
    game->player_rect.x += game->player_xvol;
       if(game->keystate[SDL_SCANCODE_LSHIFT]) {
      game->player_rect.x += 5;
    }
  }
}

// Start of enemy A.I, moves towards player
void update_enemy1(struct Game *game) {
int mouseX, mouseY; // Repurposed from scraped player movement
  SDL_GetMouseState(&mouseX, &mouseY);
  if(mouseX == game->player_rect.x) {
    if(mouseY == game->player_rect.y) {
    game->player_rect.x += 2;
    game->player_rect.y += 2;
    }
  }

  float dx = mouseX - game->player_rect.x;
  float dy = mouseY - game->player_rect.y;
  float magnititude = sqrt(dx * dx + dy * dy);
  float normalized_dx = dx / magnititude;
  float normalized_dy = dy / magnititude;
  float newXvol = game->player_rect.x + normalized_dx * game->player_xvol;
  float newYvol = game->player_rect.y + normalized_dy * game->player_yvol;
  game->player_rect.x = newXvol;
  game->player_rect.y = newYvol;  

}

void sdl_cleanup(struct Game *game, int exit_status) {
  SDL_DestroyWindow(game->window);
  SDL_DestroyRenderer(game->renderer);
  IMG_Quit();
  SDL_Quit();
  exit(exit_status);
}

bool sdl_init(struct Game *game) {
  if(SDL_Init(SDL_FLAGS)) {
    fprintf(stderr, "Error WHAT THE FUCK", SDL_GetError() );
    return true;
  }

  game->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if(!game->window) {
    fprintf(stderr, "Error creating window: %s\n", SDL_GetError() );
    return true;
;  }

  game->renderer = SDL_CreateRenderer(game->window, -1, 0);
  if(!game->renderer) {
    fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError() );
   return true;
  }

  game->img_init = IMG_Init(IMG_FLAGS);
    if((game->img_init & IMG_FLAGS) != IMG_FLAGS) {
        fprintf(stderr, "Error initializing image flags: %s", IMG_GetError() );
        return true;
  }

  SDL_ShowCursor(SDL_ENABLE); // Will be set to disable in future updates

  return false;
}

bool sdl_loadmedia(struct Game *game) {
  game->player_image = IMG_LoadTexture(game->renderer, "../images/CaptainLightShip2.png");
  if(!game->player_image) {
    fprintf(stderr, "Error loading player texture: %s", IMG_GetError() ); 
    return true;
  }

  game->background_image = IMG_LoadTexture(game->renderer, "../images/space.png");
  if(!game->background_image) {
    fprintf(stderr, "Error loading background texture: %s", IMG_GetError() );
    return true;
  }

  if(SDL_QueryTexture(game->player_image, NULL, NULL, &game->player_rect.w, &game->player_rect.h)) {
    fprintf(stderr, "Error querying player texture: %s", SDL_GetError() );
    return true;
  }
  
  return false; 
}  

void directionv1(struct Game *game) {
int mouse_x, mouse_y;
double angle_rad;
SDL_GetMouseState(&mouse_x, &mouse_y);
double delta_y = mouse_y - game->player_rect.y;
double delta_x = mouse_x - game->player_rect.x;

angle_rad = atan2(delta_y, delta_x);
angle = angle_rad * (180.0 / M_PI);
angle += 90;
printf("%d\n", angle);
}
// Maybe for later use
void directionv2(struct Game *game) {
  double dotproduct, mag1, mag2;
  int x1 = game->player_rect.x;
  int y1 = game->player_rect.y;
  int x2, y2;
  float cosine, theta;
  SDL_GetMouseState(&x2, &y2);
  dotproduct = x1*x2 + y1*y2;
  mag1 = sqrt(x1*x1 + y1*y1);
  mag2 = sqrt(x2*x2 + y2*y2);
  cosine = dotproduct / mag1*mag2;
  angle = (acos(cosine)*180.00000) / 3.141592;
  printf("%.2f", angle);
}

