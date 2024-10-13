#ifndef PLAYER_H
#define PLAYER_H

// System Headers
#include <stdint.h>

// Project Headers
#include "raylib.h"

// TODO: move texture related stuff into own struct and use texture struct in
// player struct
struct Player_t
{
   char*     name;
   int32_t   lifePoints;
   Vector2   speed;
   Rectangle rec;
   Texture2D texture;
   Vector2   texturePosition;
   Rectangle textureFrameRec;
   int       framesCounter;
   int       framesSpeed;
   int       currentFrame;
};

#define PLAYER_INIT( player, playerName )                                      \
   do                                                                          \
   {                                                                           \
      player = ( struct Player_t ){ .name       = playerName,                  \
                                    .lifePoints = 100,                         \
                                    .speed      = { 0.0f, 0.0f },              \
                                    .rec = { 350.0f, 280.0f, 50.0f, 50.0f },   \
                                    .texture =                                 \
                                        LoadTexture( "resources/scarfy.png" ), \
                                    .texturePosition = { 350.0f, 280.0f },     \
                                    .framesCounter   = 0,                      \
                                    .framesSpeed     = 8,                      \
                                    .currentFrame    = 0 };                       \
      player.textureFrameRec =                                                 \
          ( Rectangle ){ 0.0f, 0.0f, ( float ) player.texture.width / 6,       \
                         ( float ) player.texture.height };                    \
   } while ( false )

#endif

// State updates
void playerUpdateState( struct Player_t* player );

// Draw
void playerDrawPlayer( struct Player_t* player );
