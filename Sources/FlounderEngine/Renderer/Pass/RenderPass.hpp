﻿#pragma once

#include "../../Platforms/Platform.hpp"

namespace Flounder
{
	class RenderPass
	{
	private:
		VkRenderPass m_renderPass;
	public:
		RenderPass(const VkFormat &depthFormat, const VkFormat &surfaceFormat);

		~RenderPass();

		VkRenderPass GetRenderPass() const { return m_renderPass; }
	};
}
