#include "FilterSepia.hpp"

#include "../../Renderer/Renderer.hpp"

namespace Flounder
{
	const std::vector<DescriptorType> DESCRIPTORS =
		{
			Texture::CreateDescriptor(0, VK_SHADER_STAGE_FRAGMENT_BIT) // samplerColour
		};

	FilterSepia::FilterSepia(const int &subpass) :
		IPostFilter("Resources/Shaders/Filters/Sepia.frag.spv", subpass, DESCRIPTORS)
	{
	}

	FilterSepia::~FilterSepia()
	{
	}

	void FilterSepia::RenderFilter(const VkCommandBuffer &commandBuffer)
	{
		const auto descriptorSet = m_pipeline->GetDescriptorSet();
		const std::vector<VkWriteDescriptorSet> descriptorWrites = std::vector<VkWriteDescriptorSet>
			{
				Renderer::Get()->GetSwapchain()->GetColourImage()->GetWriteDescriptor(0, descriptorSet)
			};
		IPostFilter::CmdRender(commandBuffer, descriptorWrites);
	}
}
