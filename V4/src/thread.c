/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:58:47 by ghubert           #+#    #+#             */
/*   Updated: 2017/06/26 15:28:25 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_pixels(t_env *env)
{
	Uint32	color;

	ft_init_start(env);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				ft_light(env);
				ft_shadow(env);
				color = ft_chose_color(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
					color;
				/*env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.green * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.blue * \
				env->light->power * env->tmp.darkness, 255);*/
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
}

int		thread_1(void *env_1)
{
	Uint32	color;
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < (HEIGHT / 2))
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < (WIDTH / 2))
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				ft_light(env);
				ft_shadow(env);
				color = ft_chose_color(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
					color;
				/*env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.green * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.blue * \
				env->light->power * env->tmp.darkness, 255);*/
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_2(void *env_1)
{
	Uint32	color;
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < (HEIGHT / 2))
	{
		env->sdl.pos.x = WIDTH / 2;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				ft_light(env);
				ft_shadow(env);
				color = ft_chose_color(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
					color;
				/*env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.green * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.blue * \
				env->light->power * env->tmp.darkness, 255);*/
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_3(void *env_1)
{
	Uint32	color;
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	env->sdl.pos.y = HEIGHT / 2;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < (WIDTH / 2))
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				ft_light(env);
				ft_shadow(env);
				color = ft_chose_color(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
					color;
				/*env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.green * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.blue * \
				env->light->power * env->tmp.darkness, 255);*/
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_4(void *env_1)
{
	Uint32	color;
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	env->sdl.pos.y = HEIGHT / 2;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = WIDTH / 2;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				ft_light(env);
				ft_shadow(env);
				color = ft_chose_color(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
					color;
				/*env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.green * \
				env->light->power * env->tmp.darkness, env->tmp.current->color.blue * \
				env->light->power * env->tmp.darkness, 255);*/
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

void	ft_thread(t_env_g *env)
{
	int		ret;
	void	*env1;
	void	*env2;
	void	*env3;
	void	*env4;

	env1 = (void *)env->env1;
	env2 = (void *)env->env2;
	env3 = (void *)env->env3;
	env4 = (void *)env->env4;
	ret = 0;
	env->thread.t_1 = NULL;
	env->thread.t_2 = NULL;
	env->thread.t_3 = NULL;
	env->thread.t_4 = NULL;
	env->thread.t_1 = SDL_CreateThread(thread_1, "T1", env1);
	SDL_WaitThread(env->thread.t_1, &ret);
	env->thread.t_2 = SDL_CreateThread(thread_2, "T2", env2);
	SDL_WaitThread(env->thread.t_2, &ret);
	env->thread.t_3 = SDL_CreateThread(thread_3, "T3", env3);
	SDL_WaitThread(env->thread.t_3, &ret);
	env->thread.t_4 = SDL_CreateThread(thread_4, "T4", env4);
	SDL_WaitThread(env->thread.t_4, &ret);
}
