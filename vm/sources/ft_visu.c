#include "../includes/corewar.h"

void initSdl(t_sdl *sdl)
{
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->fontname = ft_strdup("../../SDL/open-sans/OpenSans-Bold.ttf");
}

SDL_Color ft_make_color(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color c = {r, g, b, 255};
	return (c);
}
//
// void	renderLast(t_sdl *sdl, t_vm *vm)
// {
// 	sdl->window = NULL;
//
// }
//
// void 	createLastTexture(t_sdl *sdl, t_vm *vm, int tmp, char *win)
// {
// 	SDL_Surface *text;
// 	SDL_Texture *texture;
// 	char *str;
// 	char *str2;
//
// 	str = ft_strjoin("Contestant ", ft_itoa(tmp));
// 	str2 = ft_strjoin(win, ", has won !\n");
// 	str = ft_strjoin(str, str2);
// 	text = TTF_RenderText_Blended(font, , backgroundColor);
// 	texture = SurfaceToTexture(solid, renderer);
// 	SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
// 	solidRect.x = 1000;
// 	solidRect.y = 1000;
// 	SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
// 	SDL_RenderClear(renderer);
// 	renderLast(renderer, vm);
// 	free(str);
// 	free(str2);
// }
//
// void	display_winner(SDL_Window *window, SDL_Renderer *renderer, t_vm *vm)
// {
// 	t_bin	*win;
// 	int		tmp;
//
// 	win = who_win(vm);
// 	if (win->num_plyr < 0)
// 		tmp = (-1 * win->num_plyr);
// 	else
// 		tmp = win->num_plyr;
// 	while (SDL_PollEvent(&event))
// 	{
// 		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
// 		{
// 			quit(window, renderer);
// 			exit(0);
// 		}
// 	}
// 	SDL_RenderPresent(renderer);
// }
