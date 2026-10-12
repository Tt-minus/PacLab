void ShapeComponent::update(const float& dt) {
	_shape->setPosition(_parent->get_position());
}

void SharedComponent::render() { Renderer::queue(_shape.get()); }

sf::Shape& ShapeComponent::get_shape() const { return *_shape; }

ShapeComponent::ShapeComponent(entity* p) : Component(p), _shape(std::make_shared<sf::CircleShape>()) {}