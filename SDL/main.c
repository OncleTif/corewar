#include <SDL2/SDL.h>
// #include "/nfs/2015/e/eozdek/Library/Frameworks/Headers/SDL_ttf.h"
#include <SDL_ttf.h>
int main (int argc, char** argv)
{
	SDL_Window* window = NULL;
	window = SDL_CreateWindow
	(
		"Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	// // Setup renderer
	SDL_Renderer* renderer = NULL;
	renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

	// // Set render color to red ( background will be rendered in this color )
	// SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
	//
	// // Clear winow
	// SDL_RenderClear( renderer );
	//
	// // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
	// SDL_Rect r;
	// r.x = 100;
	// r.y = 100;
	// r.w = 100;
	// r.h = 100;
	//
	// // Set render color to blue ( rect will be rendered in this color )
	// SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
	//
	// // Render rect
	// SDL_RenderFillRect( renderer, &r );
	//
	// // Render the rect to the screen
	// SDL_RenderPresent(renderer);
	//
	// // Wait for 5 sec
	// SDL_Delay( 5000 );
	//
	// SDL_DestroyWindow(window);
	// SDL_Quit();
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

	SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect

	//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

	//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
	int i;
	SDL_Event event;

	i = 0;
	while (i == 1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_Quit)
			{
				i = 0;
				break ;
			}
		}
	}
	return EXIT_SUCCESS;
}
