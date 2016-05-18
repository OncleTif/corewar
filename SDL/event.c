#include <SDL2/SDL.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

/*
Il y a un segfault de merde
*/

void ft_putchar(char c)
{
	write (1, &c, 1);
}

int init(SDL_Window* window, SDL_Surface *screen)
{
	int flags;
	int status;
	int x;
	int y;
	SDL_Rect* rect;
	Uint32 color;

	ft_putchar('a');
	flags = SDL_INIT_VIDEO;
	status = SDL_Init(flags);
	x = SDL_WINDOWPOS_UNDEFINED;
	y = SDL_WINDOWPOS_UNDEFINED;
	rect = NULL;
	ft_putchar('b');
	if (status == 0)
	{
		window = SDL_CreateWindow("SDL window", x, y, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window)
		{
			screen = SDL_GetWindowSurface(window);
			color = SDL_MapRGB(screen->format, 0, 0, 0);
			SDL_FillRect(screen, rect, color);
			SDL_UpdateWindowSurface(window);
			// ft_putchar('w');
			// Uint32 color = SDL_MapRGB(screen->format, 255, 255, 0);
			return (1);
		}
		else
			return (0);
		ft_putchar('d');
	}
	else
	{
		return (0);
	}
}

void	handleKeydown(SDL_Keycode keycode, SDL_Surface *screen, SDL_Window* window)
{
	SDL_Rect* rect;
	Uint32 color;

	if (keycode == SDLK_UP)
	{
		color = SDL_MapRGB(screen->format, 255, 0, 0);
		ft_putchar('m');
		SDL_FillRect(screen, rect, color);
	}
	else if (keycode == SDLK_DOWN)
	{
		ft_putchar('o');
		color = SDL_MapRGB(screen->format, 255, 255, 0);
		SDL_FillRect(screen, rect, color);
	}
	else if (keycode == SDLK_LEFT)
	{
		ft_putchar('p');
		color = SDL_MapRGB(screen->format, 0, 255, 0);
		SDL_FillRect(screen, rect, color);
	}
	else if (keycode == SDLK_RIGHT)
	{
		ft_putchar('q');
		color = SDL_MapRGB(screen->format, 0, 0, 255);
		SDL_FillRect(screen, rect, color);
	}
	SDL_UpdateWindowSurface(window);
}


// void	ft_render(SDL_Window* window, SDL_Surface* screen)
// {
//
// }

void	loop(SDL_Surface *screen, SDL_Window* window)
{
	int running;
	int status;
	SDL_Event event;
	Uint32 type;
	SDL_KeyboardEvent keyboardEvent;
	SDL_Keysym keysym;
	SDL_Keycode keycode;

	running = 1;
	// event = NULL;
	// type = NULL;
	// keyboardEvent = NULL;
	// keysym = NULL;
	// keycode = NULL;
	// ft_putchar('a');
	while (running)
	{
		status = SDL_PollEvent(&event);
		if (status != 0)
		{
			type = event.type;
			if (type == SDL_QUIT)
			{
				running = 0;
				break ;
			}
			else if (type == SDL_KEYDOWN)
			{
				keyboardEvent = event.key;
				keysym = keyboardEvent.keysym;
				keycode = keysym.sym;
				handleKeydown(keycode, screen, window);
				break ;
			}

		}
	}
	// ft_putchar('b');
}

void	ft_quit(SDL_Surface *screen, SDL_Window* window)
{
	(void)screen;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char **argv)
{
	SDL_Window *window;
	SDL_Surface *screen;

	window = NULL;
	screen = NULL;
	// ft_putchar('c');
	if (init(window, screen))
	{
		ft_putchar('e');
		// ft_render();
		Uint32 color = SDL_MapRGB(screen->format, 255, 255, 0);
		loop(screen, window);
	}
	// ft_putchar('d');
	ft_quit(screen, window);
	return (0);
}
