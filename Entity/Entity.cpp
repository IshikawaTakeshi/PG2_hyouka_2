#include "Entity/Entity.h"

Entity::Entity() {
	pos_ = { 0,0 };
	size_ = { 0,0 };
	direction_ = { 0,0 };
	speed_ = 0;
	length_ = 0;
	isAlive_ = 0;
}

Entity::~Entity() {}

void Entity::Draw() {}

void Entity::Normalize() {}
