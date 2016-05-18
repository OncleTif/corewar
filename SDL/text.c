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
int SetupTTF(char *fontName);
SDL_Texture* SurfaceToTexture( SDL_Surface* surf );
void CreateTextTextures();

// Update ( happens every frame )
void Render();
void RunGame();

// Stuff for text rendering
TTF_Font* font;
SDL_Color textColor = {255, 255, 255, 255}; // white
SDL_Color backgroundColor = {0, 0, 0, 255}; // black

SDL_Texture* solidTexture;
SDL_Texture* blendedTexture;
SDL_Texture* shadedTexture;

SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;

SDL_Rect windowRect = {2000, 2000, 2000, 2000};
SDL_Window* window;
SDL_Renderer* renderer;


static void	ft_uitoaa(unsigned int nbr, char *ptr)
{
	int				i;
	size_t			range;

	i = 0;
	range = ft_range(nbr);
	while (range)
	{
		ptr[i] = nbr / range + '0';
		nbr = nbr % range;
		range = range / 10;
		i++;
	}
}

char		*ft_itoa(int n)
{
	int				neg;
	unsigned int	nbr;
	size_t			size;
	char			*ptr;
	int				i;

	i = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	nbr = n * neg;
	size = ft_intsize(nbr);
	ptr = ft_strnew(size + (neg == -1));
	if (!ptr)
		return (NULL);
	if (neg == -1)
	{
		ptr[i] = '-';
		i++;
	}
	ft_uitoaa(nbr, ptr + i);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*ptr;

	ptr = NULL;
	if (s1 && s2)
	{
		s1_size = ft_strlen(s1);
		s2_size = ft_strlen(s2);
		ptr = ft_strnew(s1_size + s2_size + 1);
		if (!ptr)
			return (NULL);
		ft_strcpy(ptr, s1);
		ft_strcpy(ptr + s1_size, s2);
	}
	return (ptr);
}


void RunGame()
{
	Render();
	// printf("error");
	// std::cin.ignore();
}
void Render()
{
	// Clear the window and make it all red
	SDL_RenderClear(renderer);
	// Render our text objects ( like normal )
	SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
	SDL_RenderCopy(renderer, blendedTexture, NULL, &blendedRect);
	SDL_RenderCopy(renderer, shadedTexture, NULL, &shadedRect);
	// Render the changes above
	SDL_RenderPresent(renderer);
}
// Initialization ++
// ==================================================================
int SetupTTF(char *fontName)
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
	SDL_Surface* solid = TTF_RenderText_Blended(font, "YO", textColor);
	solidTexture = SurfaceToTexture(solid);

	SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 1500;
	solidRect.y = 1500;

	SDL_Surface* blended = TTF_RenderText_Blended(font, "Corewar", textColor);
	blendedTexture = SurfaceToTexture( blended );

	SDL_QueryTexture(blendedTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = solidRect.x;
	blendedRect.y = solidRect.y + solidRect.h +  20;

	SDL_Surface* shaded = TTF_RenderText_Shaded(font, "visu", textColor, backgroundColor);
	shadedTexture = SurfaceToTexture( shaded );

	SDL_QueryTexture(shadedTexture , NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = solidRect.x;
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
	SDL_Init(SDL_INIT_EVERYTHING);
	// if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	// {
	// 	printf("error");
	// 	return false;
	// }

	return true;
}
int CreateWindow()
{
	window = SDL_CreateWindow( "YO", windowRect.x, windowRect.y, windowRect.w, windowRect.h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	// if ( window == NULL )
	// {
	// 	printf("error");
	// 	return false;
	// }

	return true;
}
int CreateRenderer()
{
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	//
	// if ( renderer == NULL )
	// {
	// 	printf("error");
	// 	return false;
	// }

	return true;
}
void SetupRenderer()
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize( renderer, windowRect.w, windowRect.h );

	// Set color of renderer to red
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
}

int main( int argc, char *args[])
{
	if ( !InitEverything() )
		return -1;
	int i;
	SDL_Event event;

	i = 1;
	while (i == 1)
	{
		RunGame();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				i = 0;
				break ;
			}
		}
	}
	TTF_CloseFont( font );
	return (0);
}
