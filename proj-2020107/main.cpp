/*
 * main.cpp
 *
 *  Created on: 15 окт. 2020 г.
 *      Author: erijkova
 */


#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

#include <SDL2/SDL.h>

constexpr double Pi = acos(-1.);

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 600;

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"Окно нашего графического приложения",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (win == nullptr) {
		std::cerr << "При создании окна произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (ren == nullptr) {
		std::cerr << "При создании renderer-а произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event event;

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 48, 64, 255);
		SDL_RenderClear(ren.get());

		SDL_SetRenderDrawColor(ren.get(), 255, 255, 255, 255);
		SDL_RenderDrawLine(ren.get(), 10, 200, 110, 30); //крыша
		SDL_RenderDrawLine(ren.get(), 110, 30, 200, 200);

		SDL_RenderDrawLine(ren.get(), 200, 200, 200, 400); //домик
		SDL_RenderDrawLine(ren.get(), 200, 400, 10, 400);
		SDL_RenderDrawLine(ren.get(), 10, 400, 10, 200);
		SDL_RenderDrawLine(ren.get(), 10, 200, 200, 200);

		SDL_RenderDrawLine(ren.get(), 30, 400, 30, 270); //дверь
		SDL_RenderDrawLine(ren.get(), 30, 270, 80, 270);
		SDL_RenderDrawLine(ren.get(), 80, 270, 80, 400);
		SDL_RenderDrawLine(ren.get(), 35, 330, 40, 330); //ручка двери

		SDL_RenderDrawLine(ren.get(), 110, 250, 170, 250); //окно
		SDL_RenderDrawLine(ren.get(), 170, 250, 170, 320);
		SDL_RenderDrawLine(ren.get(), 170, 320, 110, 320);
		SDL_RenderDrawLine(ren.get(), 110, 320, 110, 250);
		SDL_RenderDrawLine(ren.get(), 140, 250, 140, 320);
		SDL_RenderDrawLine(ren.get(), 110, 285, 140, 285);

		SDL_RenderDrawLine(ren.get(), 170, 140, 170, 90); //труба
		SDL_RenderDrawLine(ren.get(), 170, 90, 160, 90);
		SDL_RenderDrawLine(ren.get(), 160, 90, 160, 125);

		SDL_RenderPresent(ren.get());
	}


	return 0;
}



