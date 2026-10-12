#include "renderer.hpp"
#include "engine/game_system.hpp"
#include "components.hpp"
#include "ecm.hpp"
#define GHOSTS_COUNT 4

sf::Font font;
std::shared_ptr<Scene> Scenes::menu;
std::shared_ptr<Scene> Scenes::game;

void MenuScene::update(const float& dt) {
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	//Set up the text element here!
	 // Load font-face from res dir
	font.loadFromFile("resources/fonts/RobotoMono-Regular.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);
	text.setColor(sf::Color(255, 255, 255));
}

void GameScene::load() {
	{
		std::shared_ptr<Entity> player = std::make_shared<Entity>();
		std::shared_ptr<ShapeComponent> shape = player->add_component<ShapeComponent>();
		shape->set_shape<sf::CircleShape>(param::entity_size);
		shape->get_shape().setFillColor(sf::Color::Yellow);
		shape->get_shape().setOrigin(sf::Vector2f(param::entity_size, param::entity_size));
		_entities.list.push_back(player);
	}

	const sf::Color ghost_cols[]{ {208, 62, 25},    // red Blinky
								 {219, 133, 28},   // orange Clyde
								 {70, 191, 238},   // cyan Inky
								 {234, 130, 229} }; // pink Pinky

	for (int i = 0; i < param::ghost_count; i++) {
		std::shared_ptr<Entity> ghost = std::make_shared<Entity>();
		std::shared_ptr<ShapeComponent> shape = ghost->add_component<ShapeComponent>();
		shape->set_shape<sf::CircleShape>(param::entity_size);
		shape->get_shape().setFillColor(ghost_cols[i % param::number_ghosts]);
		shape->get_shape().setOrigin(
			sf::Vector2f(param::entity_size, param::entity_size));
		_entities.list.push_back(ghost);
	}
}

void GameScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		gs::set_active_scene(Scenes::menu);
	}
	Scene::update(dt);
	
}

void GameScene::respawn() {
	_player->set_position(ls::get_start_position());
	_player->get_compatible_components<ActorMovementComponent>()[0]
		->set_speed(param::player_speed);

	std::vector<sf::Vector2i> ghost_spawns = ls::find_tiles(ls::ENEMY);
	for (size_t i = 1; i < _entities.list.size(); i++) {
		std::shared_ptr<Entity>& ghost = _entities.list[i];
		ghost->set_position(
			ls::get_tile_position(ghost_spawns[rand() % ghost_spawns.size()]));
		ghost->get_compatible_components<ActorMovementComponent>()[0]->set_speed(param::ghost_speed);
	}
}