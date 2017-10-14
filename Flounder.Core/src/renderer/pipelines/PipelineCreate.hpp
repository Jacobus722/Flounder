#pragma once

#include "../../platforms/Platform.hpp"
#include "InputState.hpp"
#include "Descriptor.hpp"
#include "ShaderStages.hpp"

namespace Flounder
{
	enum PipelineModeFlags
	{
		PIPELINE_POLYGON,
		PIPELINE_NO_DEPTH,
		PIPELINE_MRT,
		PIPELINE_MULTI_TEXTURE
	};

	struct PipelineCreateInfo
	{
		PipelineModeFlags pipelineModeFlags = PIPELINE_POLYGON;
		VkPolygonMode polygonMode = VK_POLYGON_MODE_FILL;
		VkCullModeFlags cullModeFlags = VK_CULL_MODE_BACK_BIT;
		InputState inputState = InputState();
		Descriptor descriptor = Descriptor();
		ShaderStages shaderStages = ShaderStages();
	};
}
