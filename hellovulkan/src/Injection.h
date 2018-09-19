#pragma once

#include <vulkan\vulkan.h>

class InjectionContainer
{
public:
    void CreateResources(VkDevice device);
    void BuildCommandBuffer(VkCommandBuffer commandBuffer);

private:
    VkDevice m_device;

    VkDescriptorSet VkDescriptorSet_15840359;
    VkDescriptorSet VkDescriptorSet_15840362;
    VkDescriptorSet VkDescriptorSet_1254;
    VkDescriptorSet VkDescriptorSet_15840552;
    VkDescriptorSet VkDescriptorSet_15840555;

    VkDescriptorPool VkDescriptorPool_22232;
    VkDescriptorPool VkDescriptorPool_1137;

    VkDescriptorSetLayout VkDescriptorSetLayout_1138;
    VkDescriptorSetLayout VkDescriptorSetLayout_1139;
    VkDescriptorSetLayout VkDescriptorSetLayout_1140;
    VkDescriptorSetLayout VkDescriptorSetLayout_1141;
    VkDescriptorSetLayout VkDescriptorSetLayout_1226;

    VkPipelineLayout VkPipelineLayout_1231;

    VkBuffer VkBuffer_1136;
    VkBuffer VkBuffer_1091;
    VkBuffer VkBuffer_19003;
    VkBuffer VkBuffer_8981352;
    VkBuffer VkBuffer_10838418;
    VkBuffer VkBuffer_1373;
    VkBuffer VkBuffer_4271;
    VkBuffer VkBuffer_4275;

    VkSampler VkSampler_1174;
    VkSampler VkSampler_18590;
    VkSampler VkSampler_18587;
    VkSampler VkSampler_18586;
    VkSampler VkSampler_1179;
    VkSampler VkSampler_1176;
    VkSampler VkSampler_1177;
    VkSampler VkSampler_1051;
    VkSampler VkSampler_6244;

    VkImageView VkImageView_9013541;
    VkImageView VkImageView_9434270;
    VkImageView VkImageView_9013956;
    VkImageView VkImageView_10931;
    VkImageView VkImageView_9331135;
    VkImageView VkImageView_9331138;
    VkImageView VkImageView_9331097;
    VkImageView VkImageView_9331100;
    VkImageView VkImageView_9331091;
    VkImageView VkImageView_1454;
    VkImageView VkImageView_34751;
    VkImageView VkImageView_21184;
    VkImageView VkImageView_21188;
    VkImageView VkImageView_21192;
    VkImageView VkImageView_21195;
    VkImageView VkImageView_18802;
    VkImageView VkImageView_21199;
    VkImageView VkImageView_973;
    VkImageView VkImageView_988;
    VkImageView VkImageView_985;
    VkImageView VkImageView_10882645;
    VkImageView VkImageView_10894042;
    VkImageView VkImageView_10882658;
    VkImageView VkImageView_10832259;
    VkImageView VkImageView_19027;
    VkImageView VkImageView_1018;
    VkImageView VkImageView_1027;
    VkImageView VkImageView_1442;
    VkImageView VkImageView_10832000;
    VkImageView VkImageView_18651;

    VkBufferView VkBufferView_1098;
    VkBufferView VkBufferView_1360;
    VkBufferView VkBufferView_4258;
    VkBufferView VkBufferView_4283;

    void CreateDescriptorSetLayouts();
    void CreatePipelineLayouts();
    void CreateDescriptorPools();
    void AllocateDescriptorSets();

    void UpdateDescriptorSets();

};

