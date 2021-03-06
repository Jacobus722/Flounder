#pragma once

#include "../Renderer/IRenderer.hpp"
#include "../Renderer/Buffers/UniformBuffer.hpp"
#include "../Renderer/Pipelines/Pipeline.hpp"
#include "Skyboxes.hpp"

namespace Flounder
{
	class RendererSkyboxes :
		public IRenderer
	{
	private:
		UniformBuffer *m_uniformScene;
		Pipeline *m_pipeline;
	public:
		RendererSkyboxes(const int &subpass);

		~RendererSkyboxes();

		void Render(const VkCommandBuffer &commandBuffer, const Vector4 &clipPlane, const ICamera &camera) override;
	};
}
