﻿#pragma once

#include "../IComponent.hpp"

namespace Flounder
{
	struct Constraint3
	{
		bool x, y, z;
	};

	class ComponentCollider :
		public IComponent
	{
	private:
		ICollider *m_collider;
		float m_mass;
		float m_drag;
		bool m_useGravity;
		Constraint3 m_freezePosition;
		Constraint3 m_freezeRotation;
	public:
		ComponentCollider();

		ComponentCollider(ComponentPrefab* prefab);

		~ComponentCollider();

		void Update() override;

		void CmdRender(EntityRender *entityRender) override;

		ICollider *GetCollider() override { return m_collider; }
	};
}
