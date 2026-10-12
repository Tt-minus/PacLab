#include "scenes.hpp"
#include "scenes.cpp"
#include "engine/game_system.hpp"
#include "renderer.hpp"

int main() {
	Renderer::queue(&text);
	Scenes::menu = std::make_shared<MenuScene>();
	Scenes::menu->load();
	Scenes::game = std::make_shared<GameScene>();
	Scenes::game->load();
	GameSystem::set_active_scene(Scenes::menu);
	GameSystem::start(param::game_width, param::game_height, "pacman");
	return 0;
}