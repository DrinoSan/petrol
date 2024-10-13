#include "Player.h"

//----------------------------------------------------------------------------------
// Update and Draw
// Handling of player sprite
void playerUpdateState( struct Player_t* player )
{

   if ( player->framesCounter >= ( 60 / player->framesSpeed ) )
   {
      player->framesCounter = 0;
      player->currentFrame++;

      if ( player->currentFrame > 5 )
         player->currentFrame = 0;

      player->textureFrameRec.x =
          ( float ) player->currentFrame * ( float ) player->texture.width / 6;
   }

   // Control frames speed
   if ( IsKeyDown( KEY_RIGHT ) )
   {
      player->texturePosition.x += 5;
      player->framesCounter++;
   }
   if ( IsKeyDown( KEY_LEFT ) )
   {
      player->texturePosition.x -= 5;
      player->framesCounter++;
   }
   if ( IsKeyDown( KEY_UP ) )
   {
      player->texturePosition.y -= 5;
      player->framesCounter++;
   }
   if ( IsKeyDown( KEY_DOWN ) )
   {
      player->texturePosition.y += 5;
      player->framesCounter++;
   }
}

//----------------------------------------------------------------------------------
// Drawing stuff
void playerDrawPlayer( struct Player_t* player )
{
   DrawTextureRec( player->texture, player->textureFrameRec,
                   player->texturePosition,
                   WHITE );   // Draw part of the texture
}
