#include "scenes.cpp"

class MenuScene : public Scene {
private:
	sf::Text text;

public:
	MenuScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load()override;
};

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load() override;
};

struct Scenes {
	static std::shared_ptr<Scene> menu;
	static std::shared_ptr<Scene> game;
};