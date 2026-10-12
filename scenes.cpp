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

void MenuScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		gs::set_active_scene(Scenes::game);
	}
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void GameScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		gs::set_active_scene(Scenes::menu);
	}
	Scene::update(dt);
	
}