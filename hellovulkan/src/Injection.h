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

    VkSampler VkSampler_1174;
    VkSampler VkSampler_18590;
    VkSampler VkSampler_18587;
    VkSampler VkSampler_18586;
    VkSampler VkSampler_1179;
    VkSampler VkSampler_1176;

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

    VkBufferView VkBufferView_1098;

    void CreateDescriptorSetLayouts();
    void CreatePipelineLayouts();
    void CreateDescriptorPools();
    void AllocateDescriptorSets();

    void UpdateDescriptorSets();

};

