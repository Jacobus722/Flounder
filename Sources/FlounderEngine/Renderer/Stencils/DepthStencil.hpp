#pragma once

#include "../../Platforms/Platform.hpp"
#include "../Pipelines/PipelineCreate.hpp"

namespace Flounder
{
	class DepthStencil
	{
	private:
		VkImage m_image;
		VkDeviceMemory m_imageMemory;
		VkImageView m_imageView;
		VkSampler m_sampler;
		VkFormat m_format;

		VkDescriptorImageInfo m_imageInfo;
	public:
		DepthStencil(const VkExtent3D &extent);

		~DepthStencil();

		static DescriptorType CreateDescriptor(const uint32_t &binding, const VkShaderStageFlags &stage);

		VkWriteDescriptorSet GetWriteDescriptor(const uint32_t &binding, const VkDescriptorSet &descriptorSet) const;

		VkImage GetImage() const { return m_image; }

		VkDeviceMemory GetImageMemory() const { return m_imageMemory; }

		VkImageView GetImageView() const { return m_imageView; }

		VkFormat GetFormat() const { return m_format; }
	};
}
