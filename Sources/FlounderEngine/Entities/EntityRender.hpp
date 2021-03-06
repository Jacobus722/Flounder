#pragma once

#include <vector>
#include "../Platforms/Platform.hpp"
#include "../Models/Model.hpp"
#include "UbosEntities.hpp"

namespace Flounder
{
	struct EntityRender
	{
		VkDescriptorSet descriptorSet;
		UbosEntities::UboObject uboObject;
		std::vector<VkWriteDescriptorSet> descriptorWrites;
		Model *model;
	};
}
