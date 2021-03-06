#include "Rectangle.hpp"

namespace Flounder
{
	Rectangle::Rectangle::Rectangle(const float &min, const float &max) :
		Model()
	{
		std::vector<Vertex> vertices = {
			Vertex(Vector3(min, min, 0.0f), Vector2(0.0f, 0.0f)),
			Vertex(Vector3(max, min, 0.0f), Vector2(1.0f, 0.0f)),
			Vertex(Vector3(max, max, 0.0f), Vector2(1.0f, 1.0f)),
			Vertex(Vector3(min, max, 0.0f), Vector2(0.0f, 1.0f)),
		};
		std::vector<uint32_t> indices = {
			0, 3, 2, 2, 1, 0
		};

		Model::Set(vertices, indices, ToFilename(min, max));
	}

	std::string Rectangle::Rectangle::ToFilename(const float &min, const float &max)
	{
		return "Rectangle_" + std::to_string(min) + "_" + std::to_string(max);
	}
}
