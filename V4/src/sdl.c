/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:56:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/26 15:14:36 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_sdl(t_env_g *env)
{
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		ft_error_sdl();
	if ((env->sdl.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		ft_error_sdl();
	if ((env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1, 0)) == NULL)
		ft_error_sdl();
	env->sdl.format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if ((env->env1.sdl.draw = SDL_CreateTexture(env->sdl.rend, \
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
		WIDTH, HEIGHT)) == NULL)
		ft_error_sdl();	
	if ((env->env2.sdl.draw = SDL_CreateTexture(env->sdl.rend, \
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
		WIDTH, HEIGHT)) == NULL)
		ft_error_sdl();	
	if ((env->env3.sdl.draw = SDL_CreateTexture(env->sdl.rend, \
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
		WIDTH, HEIGHT)) == NULL)
		ft_error_sdl();	
	if ((env->env4.sdl.draw = SDL_CreateTexture(env->sdl.rend, \
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
		WIDTH, HEIGHT)) == NULL)
		ft_error_sdl();	
	env->sdl.keep = 1;
}
