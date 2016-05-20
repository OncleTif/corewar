// TTF Example - Headerphile.blogspot.no
// Font used : Sketchy https://github.com/olevegard/Headerphile/raw/master/SDL2_Tutorial/Tutorial_10/sketchy.ttf
// Font license : https://github.com/olevegard/Headerphile/raw/master/SDL2_Tutorial/Tutorial_10/sketchy-license.txt
// Compilation : clang++ text_test.cpp -std=c++1y -lSDL2 -lSDL2_ttf -o FontTest && ./FontTest
// You can use g++ instead of clang++
//
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
// #include <iostream>
#define true 1
#define false 0
// Setup
int InitEverything();
int InitSDL();
int CreateWindow();
int CreateRenderer();
void SetupRenderer();

// Our new function for setting uo SDL_TTF
int SetupTTF(SDL_Texture *fontName);
SDL_Texture* SurfaceToTexture( SDL_Surface* surf );
void CreateTextTextures();

// Update ( happens every frame )
void Render();
void RunGame();

// Stuff for text rendering
TTF_Font* font;
SDL_Color textColor = { 255, 255, 255, 255 }; // white
SDL_Color backgroundColor = { 0, 0, 0, 255 }; // black

SDL_Texture* solidTexture;
SDL_Texture* blendedTexture;
SDL_Texture* shadedTexture;

SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;

SDL_Rect windowRect = { 900, 300, 400, 400 };
SDL_Window* window;
SDL_Renderer* renderer;

void RunGame()
{
	Render();
	// printf("error");
	// std::cin.ignore();
}
void Render()
{
	// Clear the window and make it all red
	SDL_RenderClear( renderer );

	// Render our text objects ( like normal )
	SDL_RenderCopy( renderer, solidTexture, NULL, &solidRect );
	SDL_RenderCopy( renderer, blendedTexture, NULL, &blendedRect );
	SDL_RenderCopy( renderer, shadedTexture, NULL, &shadedRect );

	// Render the changes above
	SDL_RenderPresent( renderer);
}
// Initialization ++
// ==================================================================
int SetupTTF(SDL_Texture *fontName)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if ( TTF_Init() == -1 )
	{
		printf("error");
		return false;
	}

	// Load our fonts, with a huge size
	font = TTF_OpenFont( fontName, 90 );

	// Error check
	if ( font == NULL )
	{
		printf("error");
		return false;
	}

	return true;
}
void CreateTextTextures()
{
	SDL_Surface* solid = TTF_RenderText_Solid( font, "solid", textColor );
	solidTexture = SurfaceToTexture( solid );

	SDL_QueryTexture( solidTexture, NULL, NULL, &solidRect.w, &solidRect.h );
	solidRect.x = 0;
	solidRect.y = 0;

	SDL_Surface* blended = TTF_RenderText_Blended( font, "blended", textColor );
	blendedTexture = SurfaceToTexture( blended );

	SDL_QueryTexture( blendedTexture, NULL, NULL, &blendedRect.w, &blendedRect.h );
	blendedRect.x = 0;
	blendedRect.y = solidRect.y + solidRect.h +  20;

	SDL_Surface* shaded = TTF_RenderText_Shaded( font, "shaded", textColor, backgroundColor );
	shadedTexture = SurfaceToTexture( shaded );

	SDL_QueryTexture( shadedTexture , NULL, NULL, &shadedRect.w, &shadedRect.h );
	shadedRect.x = 0;
	shadedRect.y = blendedRect.y + blendedRect.h + 20;
}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture( SDL_Surface* surf )
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface( renderer, surf );

	SDL_FreeSurface( surf );

	return text;
}
int InitEverything()
{
	if ( !InitSDL() )
	return false;

	if ( !CreateWindow() )
	return false;

	if ( !CreateRenderer() )
	return false;

	SetupRenderer();

	if ( !SetupTTF( "./open-sans/OpenSans-Bold.ttf" ) )
	return false;

	CreateTextTextures();

	return true;
}
int InitSDL()
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf("error");
		return false;
	}

	return true;
}
int CreateWindow()
{
	window = SDL_CreateWindow( "Server", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0 );

	if ( window == NULL )
	{
		printf("error");
		return false;
	}

	return true;
}
int CreateRenderer()
{
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	if ( renderer == NULL )
	{
		printf("error");
		return false;
	}

	return true;
}
void SetupRenderer()
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( renderer, windowRect.w, windowRect.h );

	// Set color of renderer to red
	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
}

int main( int argc, char *args[])
{
	if ( !InitEverything() )
		return -1;

	RunGame();
	TTF_CloseFont( font );
}
