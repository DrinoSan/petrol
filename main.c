#include "Player.h"
#include "raylib.h"

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 600;

static struct Player_t player;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

//-----------------------------------------------------------------------------
// Program main entry point
//-----------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow( screenWidth, screenHeight, "Drive and Fight people" );

    InitGame();

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       //----------------------------------------------------------------------------------
       UpdateDrawFrame();
       //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//-----------------------------------------------------------------------------
void InitGame(void)
{
   PLAYER_INIT( player, "Sandrino" );
}

//-----------------------------------------------------------------------------
// Update game (one frame)
void UpdateGame(void)
{
   // Update and Draw
   // Handling of player sprite
   //----------------------------------------------------------------------------------
   player.framesCounter++;

   if ( player.framesCounter >= ( 60 / player.framesSpeed ) )
   {
      player.framesCounter = 0;
      player.currentFrame++;

      if ( player.currentFrame > 5 )
         player.currentFrame = 0;

      player.textureFrameRec.x =
          ( float ) player.currentFrame * ( float ) player.texture.width / 6;
   }

   // Control frames speed
   if ( IsKeyPressed( KEY_RIGHT ) )
      player.framesSpeed++;
   else if ( IsKeyPressed( KEY_LEFT ) )
      player.framesSpeed--;
}

//-----------------------------------------------------------------------------
void DrawGame(void)
{
   BeginDrawing();

   ClearBackground( RAYWHITE );

   DrawText( "Petrol", screenWidth / 2 - MeasureText( "Petrol", 40 ) / 2,
             screenHeight / 2 - 40, 40, BLACK );

   DrawTextureRec( player.texture, player.textureFrameRec,
                   player.texturePosition,
                   WHITE );   // Draw part of the texture

   DrawText( "(c) Scarfy sprite by Eiden Marsal", screenWidth - 200,
             screenHeight - 20, 10, GRAY );

   EndDrawing();
}

//-----------------------------------------------------------------------------
void UnloadGame(void)
{
   UnloadTexture( player.texture );
}

//-----------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
   UpdateGame();
   DrawGame();
}
