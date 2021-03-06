﻿#pragma once

#include "../IComponent.hpp"

namespace Flounder
{
	class ComponentCollision :
		public IComponent
	{
	private:
	public:
		ComponentCollision();

		~ComponentCollision();

		void Update() override;

		void CmdRender(EntityRender *entityRender) override;

		Vector3 ResolveCollisions(const Vector3 &amount);
	};
}
