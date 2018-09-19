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

    void CreateDescriptorSetLayouts();
    void CreatePipelineLayouts();
    void CreateDescriptorPools();
    void AllocateDescriptorSets();

    void UpdateDescriptorSets();

};

