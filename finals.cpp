
// This is the codebase for the game for our assignment.

// Written and maintained over 7/20/2024 to 8/1/2024
// Active changes for this project are currently suspended
// Written and maintained by Avi and team
// Nidan maintained most of the images
// Ayush maintained most of the sounds

// To compile navigate to the root directory of the project and use
// g++ finals.cpp -Isrc/Include -Lsrc/lib -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

// Then './main' staying in root directory

// Due to compatibilty issues(unresolved) we could not use SDL_ttf for text rendering ->
// all text is image rendered

// Support for gif and video was also relaxed ->
// all dynamic scenes consist of carefully loaded individual frames

// To resolve any dependency
// Install SDL 2.0 follow "https://wiki.libsdl.org/SDL2/Installation"
// Locate output exe wherever SDL2.dll, SDL2_image.dll, SDL2_mixer.dll are

// GAME CONTROLS

// KENDRICK GAMEPLAY
// w- jump
// s- hit
// a- left
// d- right

// DRAKE GAMEPLAY
// UP- jump
// DOWN- hit
// LEFT- left
// RIGHT- right

// characters can only jump twice before landing
// jump action lasts 175 ms
// the refresh rate for screen is 500 ms

// 1. All screen parameters are null initialized
// 2. load_assets() generates assets for screen
// 3. begin() is the game precursor
// 4. game loops
// 5. on character health = 0, the program calls end() which later calls clear_screen() then abort().
// Note that end() function guarantees the program ends but does not necessarily free all resources

// ENJOY PLAYING!

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#undef main

// SCREEN ESSENTIALS
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
const Uint32 frame_delay = 500;

// ASSET ADRESSES
const char drake1[] = "assets/drake/drake1.png";
const char drake2[] = "assets/drake/drake2.png";
const char kendrick1[] = "assets/kendrick/breatheLeft.png";
const char kendrick2[] = "assets/kendrick/breatheRight.png";
const char background0[] = "assets/images/red-background.png";
const char kendrickhit[] = "assets/kendrick/kendrick_hit.png";
const char drakehit[] = "assets/drake/drake_hit.png";
const char blank[] = "assets/images/empty.png";
const char icon[] = "assets/images/icon.png";
const char message[] = "assets/entry/images/message.png";

// START PROGRAM ASSETS
const char blankscreen[] = "assets/entry/images/blank-screen.png";
const char kendrick_logo[] = "assets/entry/images/kendrick-lamar.png";
const char loading[] = "assets/entry/images/loading.png";
const char not_like_us[] = "assets/entry/images/not-like-us-title.png";
const char kendrick_piano[] = "assets/entry/images/kendrick-piano.png";
const char kendrick_piano_2[] = "assets/entry/images/kendrick-piano-2.png";
const char war[] = "assets/entry/images/war.png";
const char clk0[] = "assets/entry/images/clock.png";
const char clk1[] = "assets/entry/images/clock-2.png";
const char clk2[] = "assets/entry/images/clock-3.png";
const char owl_0[] = "assets/entry/images/owl/1.png";
const char owl_1[] = "assets/entry/images/owl/2.png";
const char owl_2[] = "assets/entry/images/owl/3.png";
const char owl_3[] = "assets/entry/images/owl/4.png";
const char owl_4[] = "assets/entry/images/owl/5.png";
const char owl_5[] = "assets/entry/images/owl/6.png";

// EXIT PROGRAM ADRESSES
const char drake_killed[] = "assets/exit/images/kendrick_killed_drake.png";
const char kendrick_killed[] = "assets/exit/images/drake_killed_you.png";
const char kendrick_final[] = "assets/exit/images/exit game.png";
const char ghosts0[] = "assets/exit/images/ghosts3.png";
const char ghosts1[] = "assets/exit/images/ghosts1.png";
const char ghosts2[] = "assets/exit/images/ghosts2.png";
const char ghosts3[] = "assets/exit/images/ghosts.png";
const char kd1[] = "assets/exit/ending/outroo1.png";
const char kd2[] = "assets/exit/ending/outroo2.png";
const char kd3[] = "assets/exit/ending/outroo3.png";
const char kd4[] = "assets/exit/ending/outroo4.png";
const char kd5[] = "assets/exit/ending/outroo5.png";
const char kd6[] = "assets/exit/ending/outroo6.png";
const char kd7[] = "assets/exit/ending/outroo7.png";
const char kd8[] = "assets/exit/ending/outroo8.png";
const char kd9[] = "assets/exit/ending/outroo9.png";
const char kd10[] = "assets/exit/ending/outroo10.png";
const char kd11[] = "assets/exit/ending/outroo11.png";
const char kd12[] = "assets/exit/ending/outroo12.png";
const char kd13[] = "assets/exit/ending/outroo13.png";
const char kd14[] = "assets/exit/ending/outroo14.png";
const char kd15[] = "assets/exit/ending/outroo15.png";
const char kd16[] = "assets/exit/ending/outroo16.png";
const char kd17[] = "assets/exit/ending/outroo17.png";
const char kd18[] = "assets/exit/ending/outroo18.png";
const char kd19[] = "assets/exit/ending/outroo19.png";
const char kd20[] = "assets/exit/ending/outroo20.png";
const char kd21[] = "assets/exit/ending/outroo21.png";
const char kd22[] = "assets/exit/ending/outroo22.png";
const char kd23[] = "assets/exit/ending/outroo23.png";
const char kd24[] = "assets/exit/ending/outroo24.png";
const char kd25[] = "assets/exit/ending/outroo25.png";
const char kd26[] = "assets/exit/ending/outroo26.png";
const char kd27[] = "assets/exit/ending/outroo27.png";
const char kd28[] = "assets/exit/ending/outroo28.png";
const char kd29[] = "assets/exit/ending/outroo29.png";
const char kd30[] = "assets/exit/ending/outroo30.png";
const char kd31[] = "assets/exit/ending/outroo31.png";
const char kd32[] = "assets/exit/ending/outroo32.png";
const char kd33[] = "assets/exit/ending/outroo33.png";
const char kd34[] = "assets/exit/ending/outroo34.png";
const char kd35[] = "assets/exit/ending/outroo35.png";
const char kd36[] = "assets/exit/ending/outroo36.png";
const char kd37[] = "assets/exit/ending/outroo37.png";
const char kd38[] = "assets/exit/ending/outroo38.png";
const char kd39[] = "assets/exit/ending/outroo39.png";
const char kd40[] = "assets/exit/ending/outroo40.png";
const char kd41[] = "assets/exit/ending/outroo41.png";
const char kd42[] = "assets/exit/ending/outroo42.png";
const char kd43[] = "assets/exit/ending/outroo43.png";
const char kd44[] = "assets/exit/ending/outroo44.png";
const char kd45[] = "assets/exit/ending/outroo45.png";
const char kd46[] = "assets/exit/ending/outroo46.png";
const char kd47[] = "assets/exit/ending/outroo47.png";
const char kd48[] = "assets/exit/ending/outroo48.png";
const char kd49[] = "assets/exit/ending/outroo49.png";
const char kd50[] = "assets/exit/ending/outroo50.png";
const char kd51[] = "assets/exit/ending/outroo51.png";
const char kd52[] = "assets/exit/ending/outroo52.png";
const char kd53[] = "assets/exit/ending/outroo53.png";
const char kd54[] = "assets/exit/ending/outroo54.png";
const char kd55[] = "assets/exit/ending/outroo55.png";
const char kd56[] = "assets/exit/ending/outroo56.png";
const char kd57[] = "assets/exit/ending/outroo57.png";
const char kd58[] = "assets/exit/ending/outroo58.png";
const char kd59[] = "assets/exit/ending/outroo59.png";
const char kd60[] = "assets/exit/ending/outroo60.png";
const char kd61[] = "assets/exit/ending/outroo61.png";
const char kd62[] = "assets/exit/ending/outroo62.png";
const char kd63[] = "assets/exit/ending/outroo63.png";
const char kd64[] = "assets/exit/ending/outroo64.png";
const char kd65[] = "assets/exit/ending/outroo65.png";
const char kd66[] = "assets/exit/ending/outroo66.png";
const char kd67[] = "assets/exit/ending/outroo67.png";

// EXIT TEXTURES
SDL_Texture *bbl_drizzy_killed = nullptr;
SDL_Texture *dot_killed = nullptr;
SDL_Texture *dot_final = nullptr;
SDL_Texture *ghost0 = nullptr;
SDL_Texture *ghost1 = nullptr;
SDL_Texture *ghost2 = nullptr;
SDL_Texture *ghost3 = nullptr;
SDL_Texture *kdd1 = nullptr;
SDL_Texture *kdd2 = nullptr;
SDL_Texture *kdd3 = nullptr;
SDL_Texture *kdd4 = nullptr;
SDL_Texture *kdd5 = nullptr;
SDL_Texture *kdd6 = nullptr;
SDL_Texture *kdd7 = nullptr;
SDL_Texture *kdd8 = nullptr;
SDL_Texture *kdd9 = nullptr;
SDL_Texture *kdd10 = nullptr;
SDL_Texture *kdd11 = nullptr;
SDL_Texture *kdd12 = nullptr;
SDL_Texture *kdd13 = nullptr;
SDL_Texture *kdd14 = nullptr;
SDL_Texture *kdd15 = nullptr;
SDL_Texture *kdd16 = nullptr;
SDL_Texture *kdd17 = nullptr;
SDL_Texture *kdd18 = nullptr;
SDL_Texture *kdd19 = nullptr;
SDL_Texture *kdd20 = nullptr;
SDL_Texture *kdd21 = nullptr;
SDL_Texture *kdd22 = nullptr;
SDL_Texture *kdd23 = nullptr;
SDL_Texture *kdd24 = nullptr;
SDL_Texture *kdd25 = nullptr;
SDL_Texture *kdd26 = nullptr;
SDL_Texture *kdd27 = nullptr;
SDL_Texture *kdd28 = nullptr;
SDL_Texture *kdd29 = nullptr;
SDL_Texture *kdd30 = nullptr;
SDL_Texture *kdd31 = nullptr;
SDL_Texture *kdd32 = nullptr;
SDL_Texture *kdd33 = nullptr;
SDL_Texture *kdd34 = nullptr;
SDL_Texture *kdd35 = nullptr;
SDL_Texture *kdd36 = nullptr;
SDL_Texture *kdd37 = nullptr;
SDL_Texture *kdd38 = nullptr;
SDL_Texture *kdd39 = nullptr;
SDL_Texture *kdd40 = nullptr;
SDL_Texture *kdd41 = nullptr;
SDL_Texture *kdd42 = nullptr;
SDL_Texture *kdd43 = nullptr;
SDL_Texture *kdd44 = nullptr;
SDL_Texture *kdd45 = nullptr;
SDL_Texture *kdd46 = nullptr;
SDL_Texture *kdd47 = nullptr;
SDL_Texture *kdd48 = nullptr;
SDL_Texture *kdd49 = nullptr;
SDL_Texture *kdd50 = nullptr;
SDL_Texture *kdd51 = nullptr;
SDL_Texture *kdd52 = nullptr;
SDL_Texture *kdd53 = nullptr;
SDL_Texture *kdd54 = nullptr;
SDL_Texture *kdd55 = nullptr;
SDL_Texture *kdd56 = nullptr;
SDL_Texture *kdd57 = nullptr;
SDL_Texture *kdd58 = nullptr;
SDL_Texture *kdd59 = nullptr;
SDL_Texture *kdd60 = nullptr;
SDL_Texture *kdd61 = nullptr;
SDL_Texture *kdd62 = nullptr;
SDL_Texture *kdd63 = nullptr;
SDL_Texture *kdd64 = nullptr;
SDL_Texture *kdd65 = nullptr;
SDL_Texture *kdd66 = nullptr;
SDL_Texture *kdd67 = nullptr;

// START PROGRAM ADRESSES
SDL_Texture *blank_screen = nullptr;
SDL_Texture *kendrick__logo = nullptr;
SDL_Texture *load = nullptr;
SDL_Texture *like_us = nullptr;
SDL_Texture *clock0 = nullptr;
SDL_Texture *clock1 = nullptr;
SDL_Texture *clock2 = nullptr;
SDL_Texture *owl0 = nullptr;
SDL_Texture *owl1 = nullptr;
SDL_Texture *owl2 = nullptr;
SDL_Texture *owl3 = nullptr;
SDL_Texture *owl4 = nullptr;
SDL_Texture *owl5 = nullptr;
SDL_Texture *piano1 = nullptr;
SDL_Texture *piano2 = nullptr;
SDL_Texture *war_ = nullptr;

// ASSET INITIALIZATION
void load_assets();
void checkEnds(int *);
SDL_Texture *drake_1 = nullptr;
SDL_Texture *drake_2 = nullptr;
SDL_Texture *kendrick_1 = nullptr;
SDL_Texture *kendrick_2 = nullptr;
SDL_Texture *kendrick_hit = nullptr;
SDL_Texture *drake_hit = nullptr;
SDL_Texture *background = nullptr;
SDL_Texture *empty = nullptr;
SDL_Texture *msg_ = nullptr;

// SOUND ADRESSES .wav files
const char hit1[] = "assets/sounds/hit1.wav";
const char hit2[] = "assets/sounds/hit2.wav";
const char voice1[] = "assets/sounds/voice1.wav";
const char voice2[] = "assets/sounds/voice2.wav";
const char brocolli[] = "assets/sounds/Kendrick Lamar  Broccoli Snippet Edit.mp3";
const char playtrack[] = "assets/play/music/playtrack.mp3";

// SOUND ASSETS
Mix_Music *track = nullptr;
Mix_Music *broccolli = nullptr;
Mix_Chunk *hits1 = nullptr;
Mix_Chunk *hits2 = nullptr;
Mix_Chunk *voices1 = nullptr;
Mix_Chunk *voices2 = nullptr;

// CHARACTER+HEALTH CONTROL BOXES
SDL_Rect kendrick{100, 330, 100, 128};
SDL_Rect kendrick_health{20, 10, 270, 15};
SDL_Rect drake{400, 330, 100, 128};
SDL_Rect drake_health{330, 50, 270, 15};

// UTILITY FEATURES
enum class impact
{
    KENDRICK,
    DRAKE,
    NONE
};
enum class hits
{
    KENDRICK,
    DRAKE,
    NONE
};
impact striked = impact::NONE;
hits agressor = hits::NONE;
enum last_button
{
    S,
    DOWN,
    NONE
};
int entry = NONE;
void clear_screen();
void health_regulator();
auto collision = []()
{ return SDL_HasIntersection(&kendrick, &drake); };
SDL_Rect like_us_bar{200, 200, 240, 80};
SDL_Rect k_head{50, 100, 500, 330};
SDL_Rect msg{30, 30, 280, 80};
bool quit = false; // for game loop

// RUN ON BEGIN + END
void begin();
void end();

int main(int arg, char *args[])
{

    // BASIC INITIALIZATION to handle other image formats like JPG(example) use IMG_INIT_PNG | IMG_INIT_JPG
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    window = SDL_CreateWindow("KENDRICK.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // SET ICON FOR OUR GAME
    SDL_Surface *icon_surface = IMG_Load(icon);
    SDL_SetWindowIcon(window, icon_surface);

    load_assets();
    begin();

    // EVENT HANDLING
    Uint32 start_time = SDL_GetTicks();
    static int kendrick_jumps = 0; // TO RESOLVE >2 JUMPS (NOT POSSIBLE)
    static int drake_jumps = 0;
    Uint32 kendrick_t0, drake_t0; // TO KEEP TRACK OF LANDING TIME
    Uint32 agressor_time;         // TO KEEP TRACK OF HIT TIME
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = true;
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                // KENDRICK CASES
                case SDLK_d:
                    kendrick.x += 20;
                    striked = impact::DRAKE;
                    break;
                case SDLK_a:
                    kendrick.x -= 20;
                    striked = impact::DRAKE;
                    break;
                case SDLK_w:
                    if (kendrick_jumps < 2)
                    {
                        kendrick.y -= 65;
                        ++kendrick_jumps;
                        kendrick_t0 = SDL_GetTicks();
                    }
                    break;
                case SDLK_s:
                    agressor = hits::KENDRICK;
                    agressor_time = SDL_GetTicks();
                    entry = S;
                    Mix_PlayChannel(-1, voices1, 0);
                    break;

                // DRAKE CASES
                case SDLK_RIGHT:
                    drake.x += 20;
                    striked = impact::KENDRICK;
                    break;
                case SDLK_LEFT:
                    drake.x -= 20;
                    striked = impact::KENDRICK;
                    break;
                case SDLK_UP:
                    if (drake_jumps < 2)
                    {
                        drake.y -= 65;
                        ++drake_jumps;
                        drake_t0 = SDL_GetTicks();
                    }
                    break;
                case SDLK_DOWN:
                    agressor = hits::DRAKE;
                    agressor_time = SDL_GetTicks();
                    entry = DOWN;
                    Mix_PlayChannel(-1, hits1, 0);
                    break;
                }
            }
        }

        Uint32 current_time = SDL_GetTicks();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, nullptr, nullptr);

        // JUMPING
        if (current_time - kendrick_t0 > 175 && kendrick_jumps > 0)
        {
            kendrick.y = 330;
            kendrick_jumps = 0;
        }
        if (current_time - drake_t0 > 175 && drake_jumps > 0)
        {
            drake.y = 330;
            drake_jumps = 0;
        }

        // BREATHE EFFECT
        if ((current_time - start_time) % (2 * frame_delay) < frame_delay)
        {
            SDL_RenderCopy(renderer, drake_1, nullptr, &drake);
            SDL_RenderCopy(renderer, kendrick_1, nullptr, &kendrick);
        }
        else
        {
            if (current_time - agressor_time < 500)
            {
                if (agressor == hits::KENDRICK)
                {
                    SDL_RenderCopy(renderer, kendrick_hit, nullptr, &kendrick);
                    SDL_RenderCopy(renderer, drake_2, nullptr, &drake);
                }
                if (agressor == hits::DRAKE)
                {
                    SDL_RenderCopy(renderer, drake_hit, nullptr, &drake);
                    SDL_RenderCopy(renderer, kendrick_2, nullptr, &kendrick);
                }
            }
            else
            {
                agressor = hits::NONE;
                SDL_RenderCopy(renderer, kendrick_2, nullptr, &kendrick);
                SDL_RenderCopy(renderer, drake_2, nullptr, &drake);
            }
        }

        checkEnds(&kendrick.x);
        checkEnds(&drake.x);
        // HEALTH BAR
        health_regulator();
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &kendrick_health);

        SDL_SetRenderDrawColor(renderer, 2, 0, 225, 255);
        SDL_RenderFillRect(renderer, &drake_health);

        SDL_RenderPresent(renderer);
        if (kendrick_health.w == 0 or drake_health.w == 0)
            quit = true;
    }
    end();
    clear_screen();
    std::exit(0);
    return 0;
}

void health_regulator()
{
    bool collide = collision();
    if (collide)
    {
        if (striked == impact::DRAKE)
        {
            if (agressor == hits::KENDRICK)
            {
                drake_health.w -= 18;
                drake.x += 20;
            }
        }

        if (striked == impact::KENDRICK)
        {
            if (agressor == hits::DRAKE)
            {
                kendrick_health.w -= 10;
                kendrick.x -= 20;
            }
        }
    }
    if (kendrick_health.w < 0)
        kendrick_health.w = 0;
    if (drake_health.w < 0)
        drake_health.w = 0;
    striked = impact::NONE;
    // agressor = hits::NONE;
}

void load_assets()
{
    drake_1 = IMG_LoadTexture(renderer, drake1);
    drake_2 = IMG_LoadTexture(renderer, drake2);
    kendrick_1 = IMG_LoadTexture(renderer, kendrick1);
    kendrick_2 = IMG_LoadTexture(renderer, kendrick2);
    kendrick_hit = IMG_LoadTexture(renderer, kendrickhit);
    drake_hit = IMG_LoadTexture(renderer, drakehit);
    background = IMG_LoadTexture(renderer, background0);
    empty = IMG_LoadTexture(renderer, blank);
    msg_ = IMG_LoadTexture(renderer, message);

    blank_screen = IMG_LoadTexture(renderer, blankscreen);
    kendrick__logo = IMG_LoadTexture(renderer, kendrick_logo);
    load = IMG_LoadTexture(renderer, loading);
    like_us = IMG_LoadTexture(renderer, not_like_us);
    clock0 = IMG_LoadTexture(renderer, clk0);
    clock1 = IMG_LoadTexture(renderer, clk1);
    clock2 = IMG_LoadTexture(renderer, clk2);
    owl0 = IMG_LoadTexture(renderer, owl_0);
    owl1 = IMG_LoadTexture(renderer, owl_1);
    owl2 = IMG_LoadTexture(renderer, owl_2);
    owl3 = IMG_LoadTexture(renderer, owl_3);
    owl4 = IMG_LoadTexture(renderer, owl_4);
    owl5 = IMG_LoadTexture(renderer, owl_5);
    piano1 = IMG_LoadTexture(renderer, kendrick_piano);
    piano2 = IMG_LoadTexture(renderer, kendrick_piano_2);
    war_ = IMG_LoadTexture(renderer, war);

    broccolli = Mix_LoadMUS(brocolli);
    track = Mix_LoadMUS(playtrack);
    hits1 = Mix_LoadWAV(hit1);
    hits2 = Mix_LoadWAV(hit2);
    voices1 = Mix_LoadWAV(voice1);
    voices2 = Mix_LoadWAV(voice2);

    bbl_drizzy_killed = IMG_LoadTexture(renderer, drake_killed);
    dot_killed = IMG_LoadTexture(renderer, kendrick_killed);
    dot_final = IMG_LoadTexture(renderer, kendrick_final);
    ghost0 = IMG_LoadTexture(renderer, ghosts0);
    ghost1 = IMG_LoadTexture(renderer, ghosts1);
    ghost2 = IMG_LoadTexture(renderer, ghosts2);
    ghost3 = IMG_LoadTexture(renderer, ghosts3);
    kdd1 = IMG_LoadTexture(renderer, kd1);
    kdd2 = IMG_LoadTexture(renderer, kd2);
    kdd3 = IMG_LoadTexture(renderer, kd3);
    kdd4 = IMG_LoadTexture(renderer, kd4);
    kdd5 = IMG_LoadTexture(renderer, kd5);
    kdd6 = IMG_LoadTexture(renderer, kd6);
    kdd7 = IMG_LoadTexture(renderer, kd7);
    kdd8 = IMG_LoadTexture(renderer, kd8);
    kdd9 = IMG_LoadTexture(renderer, kd9);
    kdd10 = IMG_LoadTexture(renderer, kd10);
    kdd11 = IMG_LoadTexture(renderer, kd11);
    kdd12 = IMG_LoadTexture(renderer, kd12);
    kdd13 = IMG_LoadTexture(renderer, kd13);
    kdd14 = IMG_LoadTexture(renderer, kd14);
    kdd15 = IMG_LoadTexture(renderer, kd15);
    kdd16 = IMG_LoadTexture(renderer, kd16);
    kdd17 = IMG_LoadTexture(renderer, kd17);
    kdd18 = IMG_LoadTexture(renderer, kd18);
    kdd19 = IMG_LoadTexture(renderer, kd19);
    kdd20 = IMG_LoadTexture(renderer, kd20);
    kdd21 = IMG_LoadTexture(renderer, kd21);
    kdd22 = IMG_LoadTexture(renderer, kd22);
    kdd23 = IMG_LoadTexture(renderer, kd23);
    kdd24 = IMG_LoadTexture(renderer, kd24);
    kdd25 = IMG_LoadTexture(renderer, kd25);
    kdd26 = IMG_LoadTexture(renderer, kd26);
    kdd27 = IMG_LoadTexture(renderer, kd27);
    kdd28 = IMG_LoadTexture(renderer, kd28);
    kdd29 = IMG_LoadTexture(renderer, kd29);
    kdd30 = IMG_LoadTexture(renderer, kd30);
    kdd31 = IMG_LoadTexture(renderer, kd31);
    kdd32 = IMG_LoadTexture(renderer, kd32);
    kdd33 = IMG_LoadTexture(renderer, kd33);
    kdd34 = IMG_LoadTexture(renderer, kd34);
    kdd35 = IMG_LoadTexture(renderer, kd35);
    kdd36 = IMG_LoadTexture(renderer, kd36);
    kdd37 = IMG_LoadTexture(renderer, kd37);
    kdd38 = IMG_LoadTexture(renderer, kd38);
    kdd39 = IMG_LoadTexture(renderer, kd39);
    kdd40 = IMG_LoadTexture(renderer, kd40);
    kdd41 = IMG_LoadTexture(renderer, kd41);
    kdd42 = IMG_LoadTexture(renderer, kd42);
    kdd43 = IMG_LoadTexture(renderer, kd43);
    kdd44 = IMG_LoadTexture(renderer, kd44);
    kdd45 = IMG_LoadTexture(renderer, kd45);
    kdd46 = IMG_LoadTexture(renderer, kd46);
    kdd47 = IMG_LoadTexture(renderer, kd47);
    kdd48 = IMG_LoadTexture(renderer, kd48);
    kdd49 = IMG_LoadTexture(renderer, kd49);
    kdd50 = IMG_LoadTexture(renderer, kd50);
    kdd51 = IMG_LoadTexture(renderer, kd51);
    kdd52 = IMG_LoadTexture(renderer, kd52);
    kdd53 = IMG_LoadTexture(renderer, kd53);
    kdd54 = IMG_LoadTexture(renderer, kd54);
    kdd55 = IMG_LoadTexture(renderer, kd55);
    kdd56 = IMG_LoadTexture(renderer, kd56);
    kdd57 = IMG_LoadTexture(renderer, kd57);
    kdd58 = IMG_LoadTexture(renderer, kd58);
    kdd59 = IMG_LoadTexture(renderer, kd59);
    kdd60 = IMG_LoadTexture(renderer, kd60);
    kdd61 = IMG_LoadTexture(renderer, kd61);
    kdd62 = IMG_LoadTexture(renderer, kd62);
    kdd63 = IMG_LoadTexture(renderer, kd63);
    kdd64 = IMG_LoadTexture(renderer, kd64);
    kdd65 = IMG_LoadTexture(renderer, kd65);
    kdd66 = IMG_LoadTexture(renderer, kd66);
    kdd67 = IMG_LoadTexture(renderer, kd67);

    // CHECK FOR PROPER INITIALIZATION
    if (!(broccolli or track or hits1 or hits2 or voices1 or voices2 or blank_screen or kendrick__logo or piano1 or piano2 or load or like_us or clock0 or clock1 or clock2 or owl0 or owl1 or owl2 or owl3 or owl4 or owl5 or war_))
        std::cerr << "Error initializing starting assets";

    if (!(drake_1 or drake_2 or kendrick_1 or kendrick_2 or kendrick_hit or drake_hit or background or empty or msg_))
        std::cerr << "Error initializing runtime assets";

    return;
}

void begin()
{

    SDL_RenderClear(renderer);
    Mix_PlayMusic(track, 0);

    SDL_RenderCopy(renderer, like_us, nullptr, nullptr);
    SDL_Delay(100);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, clock0, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(1400);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, clock1, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(200);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(1000);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, clock2, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(200);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(800);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, piano1, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(300);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(1100);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, piano2, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, like_us, nullptr, &like_us_bar);
    SDL_RenderPresent(renderer);

    SDL_Delay(1500);
    // SDL_RenderClear(renderer);
    // SDL_RenderCopy(renderer, load, nullptr, &like_us_bar);
    // SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, war_, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(1700 + 2600);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl0, nullptr, &k_head);
    SDL_RenderPresent(renderer);
    SDL_Delay(700);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl1, nullptr, &k_head);
    SDL_RenderPresent(renderer);
    SDL_Delay(800);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl2, nullptr, &k_head);
    SDL_RenderPresent(renderer);
    SDL_Delay(800);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl3, nullptr, &k_head);
    SDL_RenderPresent(renderer);
    SDL_Delay(800);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl4, nullptr, &k_head);
    SDL_RenderPresent(renderer);
    SDL_Delay(800);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, owl5, nullptr, &k_head);
    SDL_RenderPresent(renderer);

    SDL_Delay(400);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    // SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, msg_, nullptr, &msg);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    return;
}

void clear_screen()
{
    SDL_DestroyTexture(drake_1);
    SDL_DestroyTexture(drake_2);
    SDL_DestroyTexture(kendrick_1);
    SDL_DestroyTexture(kendrick_2);
    SDL_DestroyTexture(kendrick_hit);
    SDL_DestroyTexture(empty);
    SDL_DestroyTexture(kendrick__logo);
    SDL_DestroyTexture(load);
    SDL_DestroyTexture(like_us);
    SDL_DestroyTexture(blank_screen);
    SDL_DestroyTexture(owl0);
    SDL_DestroyTexture(owl1);
    SDL_DestroyTexture(owl2);
    SDL_DestroyTexture(owl3);
    SDL_DestroyTexture(owl4);
    SDL_DestroyTexture(owl5);
    SDL_DestroyTexture(clock0);
    SDL_DestroyTexture(clock1);
    SDL_DestroyTexture(clock2);
    SDL_DestroyTexture(piano1);
    SDL_DestroyTexture(piano2);
    SDL_DestroyTexture(war_);
    SDL_DestroyTexture(msg_);
    Mix_FreeMusic(broccolli);
    Mix_FreeChunk(hits1);
    Mix_FreeChunk(hits2);
    Mix_FreeChunk(voices1);
    Mix_FreeChunk(voices2);
    Mix_FreeMusic(track);

    SDL_DestroyTexture(bbl_drizzy_killed);
    SDL_DestroyTexture(dot_killed);
    SDL_DestroyTexture(dot_final);
    SDL_DestroyTexture(ghost0);
    SDL_DestroyTexture(ghost1);
    SDL_DestroyTexture(ghost2);
    SDL_DestroyTexture(ghost3);
    SDL_DestroyTexture(kdd1);
    SDL_DestroyTexture(kdd2);
    SDL_DestroyTexture(kdd3);
    SDL_DestroyTexture(kdd4);
    SDL_DestroyTexture(kdd5);
    SDL_DestroyTexture(kdd6);
    SDL_DestroyTexture(kdd7);
    SDL_DestroyTexture(kdd8);
    SDL_DestroyTexture(kdd9);
    SDL_DestroyTexture(kdd10);
    SDL_DestroyTexture(kdd11);
    SDL_DestroyTexture(kdd12);
    SDL_DestroyTexture(kdd13);
    SDL_DestroyTexture(kdd14);
    SDL_DestroyTexture(kdd15);
    SDL_DestroyTexture(kdd16);
    SDL_DestroyTexture(kdd17);
    SDL_DestroyTexture(kdd18);
    SDL_DestroyTexture(kdd19);
    SDL_DestroyTexture(kdd20);
    SDL_DestroyTexture(kdd21);
    SDL_DestroyTexture(kdd22);
    SDL_DestroyTexture(kdd23);
    SDL_DestroyTexture(kdd24);
    SDL_DestroyTexture(kdd25);
    SDL_DestroyTexture(kdd26);
    SDL_DestroyTexture(kdd27);
    SDL_DestroyTexture(kdd28);
    SDL_DestroyTexture(kdd29);
    SDL_DestroyTexture(kdd30);
    SDL_DestroyTexture(kdd31);
    SDL_DestroyTexture(kdd32);
    SDL_DestroyTexture(kdd33);
    SDL_DestroyTexture(kdd34);
    SDL_DestroyTexture(kdd35);
    SDL_DestroyTexture(kdd36);
    SDL_DestroyTexture(kdd37);
    SDL_DestroyTexture(kdd38);
    SDL_DestroyTexture(kdd39);
    SDL_DestroyTexture(kdd40);
    SDL_DestroyTexture(kdd41);
    SDL_DestroyTexture(kdd42);
    SDL_DestroyTexture(kdd43);
    SDL_DestroyTexture(kdd44);
    SDL_DestroyTexture(kdd45);
    SDL_DestroyTexture(kdd46);
    SDL_DestroyTexture(kdd47);
    SDL_DestroyTexture(kdd48);
    SDL_DestroyTexture(kdd49);
    SDL_DestroyTexture(kdd50);
    SDL_DestroyTexture(kdd51);
    SDL_DestroyTexture(kdd52);
    SDL_DestroyTexture(kdd53);
    SDL_DestroyTexture(kdd54);
    SDL_DestroyTexture(kdd55);
    SDL_DestroyTexture(kdd56);
    SDL_DestroyTexture(kdd57);
    SDL_DestroyTexture(kdd58);
    SDL_DestroyTexture(kdd59);
    SDL_DestroyTexture(kdd60);
    SDL_DestroyTexture(kdd61);
    SDL_DestroyTexture(kdd62);
    SDL_DestroyTexture(kdd63);
    SDL_DestroyTexture(kdd64);
    SDL_DestroyTexture(kdd65);
    SDL_DestroyTexture(kdd66);
    SDL_DestroyTexture(kdd67);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
    // exit(0);

    return;
}

void end()
{
    if (drake_health.w == 0)
    {

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bbl_drizzy_killed, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);

        Mix_FreeChunk(hits1);
        Mix_FreeChunk(hits2);
        Mix_FreeMusic(track);
        Mix_PlayMusic(broccolli, 0);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd1, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd2, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd3, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd4, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd5, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd6, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd7, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd8, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd9, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd10, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd11, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd12, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd13, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd14, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd15, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd16, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd17, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd18, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd19, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd20, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd21, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd22, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd23, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd24, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd25, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd26, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd27, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd28, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd29, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd30, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd31, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd32, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd33, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd34, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd35, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd36, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd37, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd38, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd39, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd40, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd41, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd42, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd43, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd44, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd45, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd46, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd47, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd48, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd49, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd50, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd51, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd52, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd53, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd54, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd55, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd56, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd57, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd58, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd59, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd60, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd61, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd62, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd63, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd64, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd65, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd66, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(238);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, kdd67, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(738);

        // quit = true;
        // clear_screen();
        // return;
        abort();
    }
    else if (kendrick_health.w == 0)
    {

        Mix_FreeChunk(hits1);
        Mix_FreeChunk(hits2);
        Mix_FreeMusic(track);
        Mix_PlayMusic(broccolli, 0);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, dot_killed, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(800);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, ghost0, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, ghost1, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(300);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, ghost2, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(300);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, ghost3, nullptr, nullptr);
        SDL_RenderPresent(renderer);
        SDL_Delay(800);

        for (auto i = 0; i < 20; i++)
        {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, dot_final, nullptr, nullptr);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, blank_screen, nullptr, nullptr);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }

        SDL_Delay(5000);

        // quit = true;
        // clear_screen();
        // return;
        abort();
    }

    // return;
}

void checkEnds(int *coordinate)
{
    if (*coordinate < 20)
    {
        *coordinate = -13;
    }
    else if (*coordinate >= 545)
    {
        *coordinate = 555;
    }
}