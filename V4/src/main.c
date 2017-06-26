/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/26 15:13:20 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		main(int ac, char **av)
{
	t_env_g	env;
	int		i;

	if (ac == 2)
	{
		i = 1;
		ft_parse(&env.env1, av[1]);
		ft_parse(&env.env2, av[1]);
		ft_parse(&env.env3, av[1]);
		ft_parse(&env.env4, av[1]);
		ft_init_sdl(&env);
		ft_calc_angles(&env.env1);
		ft_calc_angles(&env.env2);
		ft_calc_angles(&env.env3);
		ft_calc_angles(&env.env4);
	/*	while (env.obj)
		{
			printf("obj %d type :%d\n", i, env.obj->type);
			printf("obj %d tex :%d\n", i, env.obj->tex);
			printf("obj %d radius :%d\n", i, env.obj->radius);
			printf("obj %d pos x %f y %f z %f\n", i, env.obj->pos.x, \
					env.obj->pos.y, env.obj->pos.z);
			printf("obj %d angles x %f y %f z %f\n", i, env.obj->angles.x, \
					env.obj->angles.y, env.obj->angles.z);
			printf("obj %d angle %d\n", i, env.obj->angle);
			printf("obj %d color red %d green %d blue %d\n", i, \
			env.obj->color.red, env.obj->color.green, env.obj->color.blue);
			printf("obj %d tile red %d green %d blue %d, w %d\n", i, \
			env.obj->tile.red, env.obj->tile.green, env.obj->tile.blue, \
			env.obj->tile.w);
			i++;
			env.obj = env.obj->next;
		}*/
		ft_display(&env);
		while (env.sdl.keep)
		{
			SDL_WaitEvent(&env.sdl.event);
			if (env.sdl.event.type == SDL_QUIT || \
								env.sdl.event.key.keysym.sym == SDLK_ESCAPE)
				env.sdl.keep = 0;
            if (env.sdl.event.type == SDL_KEYDOWN)
            {
                if (env.sdl.event.key.keysym.sym == SDLK_LEFT)
                    env.env1.cam.pos.x -= 0.01;
                if (env.sdl.event.key.keysym.sym == SDLK_RIGHT)
                    env.env1.cam.pos.x += 0.01;
                if (env.sdl.event.key.keysym.sym == SDLK_UP)
                    env.env1.cam.pos.y += 0.01;
                if (env.sdl.event.key.keysym.sym == SDLK_DOWN)
                    env.env1.cam.pos.y -= 0.01;
                
                if (env.sdl.event.key.keysym.sym == 1073741919)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, -1, 1);
                if (env.sdl.event.key.keysym.sym == 1073741921)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, 1, 1);
                if (env.sdl.event.key.keysym.sym == 1073741916)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, -1, 2);
                if (env.sdl.event.key.keysym.sym == 1073741918)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, 1, 2);
                if (env.sdl.event.key.keysym.sym == 1073741913)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, -1, 3);
                if (env.sdl.event.key.keysym.sym == 1073741915)
                    env.env1.cam.dir = ft_vect_rot(env.env1.cam.dir, 1, 3);
			//	ft_display(&env);
            }
		}
		SDL_DestroyRenderer(env.sdl.rend);
		SDL_DestroyWindow(env.sdl.win);
		SDL_Quit();
	}
	else
		ft_putendl("Usage : ./rt scene");
	return (0);
}
