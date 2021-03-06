﻿#include "ComponentCollider.hpp"

#include "../Entity.hpp"
#include "ComponentModel.hpp"

namespace Flounder
{
	ComponentCollider::ComponentCollider() :
		IComponent(),
		m_collider(nullptr)
	{
	}

	ComponentCollider::ComponentCollider(ComponentPrefab* prefab) :
		IComponent(),
		m_collider(nullptr)
	{
	}

	ComponentCollider::~ComponentCollider()
	{
	}

	void ComponentCollider::Update()
	{
		/*auto componentModel = GetEntity()->GetComponent<ComponentModel>();

		if (componentModel != nullptr)
		{
			delete m_collider; // TODO?
			componentModel->GetModel()->GetAabb()->Update(*m_entity->GetTransform(), m_collider);
		}
		else
		{
			m_collider = nullptr;
		}*/
	}

	void ComponentCollider::CmdRender(EntityRender *entityRender)
	{
	}
}
