﻿#pragma once

#include <vector>

#include "../maths/Vector3.hpp"
#include "../maths/Matrix4.hpp"
#include "../physics/Aabb.hpp"
#include "../models/Model.hpp"
#include "../renderer/buffers/UniformBuffer.hpp"

namespace Flounder
{
	class Pipeline;

	class Terrain
	{
	private:
		UniformBuffer *m_uniformObject;

		Model *m_model;

		Vector3 *m_position;
		Vector3 *m_rotation;
		bool m_moved;

		Matrix4 *m_modelMatrix;
		Aabb *m_aabb;
	public:
		static const float SQUARE_SIZE;
		static const int VERTEX_COUNT;
		static const float SIDE_LENGTH;

		Terrain(const Vector3 &position, const Vector3 &rotation, const int &seed);

		~Terrain();

		void Update();

		void CmdRender(const VkCommandBuffer &commandBuffer, const Pipeline &pipeline, const UniformBuffer &uniformScene);
	private:
		void GenerateMesh();

		static void StoreQuad1(std::vector<uint16_t> &indices, const int &topLeft, const int &topRight, const int &bottomLeft, const int &bottomRight, const bool &mixed);

		static void StoreQuad2(std::vector<uint16_t> &indices, const int &topLeft, const int &topRight, const int &bottomLeft, const int &bottomRight, const bool &mixed);

		Vector3 CalculateNormal(const float &x, const float &z);
	public:
		float GetHeight(const float &x, const float &z);

		Model *GetModel() const { return m_model; }

		Vector3 *GetPosition() const { return m_position; }

		void SetPosition(const Vector3 &position);

		Vector3 *GetRotation() const { return m_rotation; }

		void SetRotation(const Vector3 &rotation);

		Matrix4 *GetModelMatrix() const { return m_modelMatrix; }

		Aabb *GetAabb() const { return m_aabb; }
	};
}
