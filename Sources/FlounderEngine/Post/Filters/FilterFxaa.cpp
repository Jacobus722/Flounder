#include "FilterFxaa.hpp"

#include "../../Renderer/Renderer.hpp"

namespace Flounder
{
	const std::vector<DescriptorType> DESCRIPTORS =
		{
			UniformBuffer::CreateDescriptor(0, VK_SHADER_STAGE_FRAGMENT_BIT), // uboScene
			Texture::CreateDescriptor(1, VK_SHADER_STAGE_FRAGMENT_BIT) // samplerColour
		};

	FilterFxaa::FilterFxaa(const int &subpass) :
		IPostFilter("Resources/Shaders/Filters/Fxaa.frag.spv", subpass, DESCRIPTORS),
		m_uniformScene(new UniformBuffer(sizeof(UboScene))),
		m_spanMax(8.0f)
	{
	}

	FilterFxaa::~FilterFxaa()
	{
		delete m_uniformScene;
	}

	void FilterFxaa::RenderFilter(const VkCommandBuffer &commandBuffer)
	{
		UboScene uboScene = {};
		uboScene.spanMax = m_spanMax;
		m_uniformScene->Update(&uboScene);

		const auto descriptorSet = m_pipeline->GetDescriptorSet();
		const std::vector<VkWriteDescriptorSet> descriptorWrites = std::vector<VkWriteDescriptorSet>
			{
				m_uniformScene->GetWriteDescriptor(0, descriptorSet),
				Renderer::Get()->GetSwapchain()->GetColourImage()->GetWriteDescriptor(1, descriptorSet)
			};
		IPostFilter::CmdRender(commandBuffer, descriptorWrites);
	}
}
