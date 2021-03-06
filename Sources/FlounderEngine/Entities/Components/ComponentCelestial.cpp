﻿#include "ComponentCelestial.hpp"

#include "../../Worlds/Worlds.hpp"
#include "../Entity.hpp"
#include "ComponentLight.hpp"

namespace Flounder
{
	ComponentCelestial::ComponentCelestial(const CelestialType &type) :
		IComponent(),
		m_type(type)
	{
	}

	ComponentCelestial::ComponentCelestial(ComponentPrefab* prefab) :
		IComponent(),
		m_type(static_cast<CelestialType>(atoi(prefab->m_data.at(0).c_str())))
	{
	}

	ComponentCelestial::~ComponentCelestial()
	{
	}

	void ComponentCelestial::Update()
	{
		Transform *entityTransform = GetEntity()->GetTransform();

		if (Worlds::Get() != nullptr)
		{
			switch (m_type)
			{
			case CelestialSun:
				entityTransform->SetPosition(*Worlds::Get()->GetSunPosition());
				break;
			case CelestialMoon:
				entityTransform->SetPosition(*Worlds::Get()->GetMoonPosition());
				break;
			}
		}

		auto componentLight = GetEntity()->GetComponent<ComponentLight>();

		if (Worlds::Get() != nullptr && componentLight != nullptr)
		{
			switch (m_type)
			{
			case CelestialSun:
				componentLight->GetLight()->m_colour->Set(*Worlds::Get()->GetSunColour());
				break;
			case CelestialMoon:
				componentLight->GetLight()->m_colour->Set(*Worlds::Get()->GetMoonColour());
				break;
			}
		}
	}

	void ComponentCelestial::CmdRender(EntityRender *entityRender)
	{
		// TODO: Disable fog/shadows/lighting.
	}
}
