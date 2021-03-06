#pragma once

#include <Entities/Entity.hpp>
#include <Models/Model.hpp>
#include <Textures/Texture.hpp>

using namespace Flounder;

class EntityTreePine :
	public Entity
{
public:
	EntityTreePine(const Transform &transform, ISpatialStructure<Entity *> *structure = nullptr);
};
