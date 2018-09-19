#include "Injection.h"

#include <assert.h>
#include <vector>

/*
To create:

shader module
graphics pipeline
bind pipeline layout to graphics pipeline
buffers
images

Created:

VkDescriptorSetLayout_1138
VkDescriptorSetLayout_1139
VkDescriptorSetLayout_1140
VkDescriptorSetLayout_1141
VkDescriptorSetLayout_1226

VkPipelineLayout_1231

VkDescriptorSet_15840359
VkDescriptorSet_15840362
VkDescriptorSet_1254
VkDescriptorSet_15840552
VkDescriptorSet_15840555

VkDescriptorPool_22232
VkDescriptorPool_1137

************************
To update:

VkDescriptorSet_15840359
VkDescriptorSet_15840362
VkDescriptorSet_1254
VkDescriptorSet_15840552
VkDescriptorSet_15840555

Updated:

*/

void InjectionContainer::CreateResources(VkDevice device)
{
    m_device = device;

    CreateDescriptorSetLayouts();
    CreatePipelineLayouts();

    CreateDescriptorPools();
    AllocateDescriptorSets();
}

void InjectionContainer::BuildCommandBuffer(VkCommandBuffer commandBuffer)
{
    // update descriptor sets
    // TODO: possibly move these into CreateResources?
    UpdateDescriptorSets();

    // bind descriptor sets
    //vkCmdBindDescriptorSets(VkCommandBuffer_360, VK_PIPELINE_BIND_POINT_COMPUTE, VkPipelineLayout_1231, 0u, 1u, pDescriptorSets, 0u, pDynamicOffsets);
    VkDescriptorSet pDescriptorSets[5] = {
        /* pDescriptorSets = */ VkDescriptorSet_15840359,
        /* pDescriptorSets = */ VkDescriptorSet_15840362,
        /* pDescriptorSets = */ VkDescriptorSet_1254,
        /* pDescriptorSets = */ VkDescriptorSet_15840552,
        /* pDescriptorSets = */ VkDescriptorSet_15840555,
    };
    uint32_t* pDynamicOffsets = NULL;
    vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, VkPipelineLayout_1231, 0u, 5u, pDescriptorSets, 0u, pDynamicOffsets);


    // shouldn't need pipeline barrier, assuming resources are in correct state!

    // kick off work finally!
    vkCmdDispatch(commandBuffer, 859u, 1u, 1u);
}

void InjectionContainer::CreateDescriptorSetLayouts()
{
    //VkDescriptorSetLayout_1138
    {
        VkDescriptorSetLayoutBinding pBindings[25] = {
            { /* pBindings = */
                /* binding = */ 0u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 1u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 2u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 3u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 4u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 5u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 6u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 7u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 8u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 9u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 10u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 11u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 12u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 13u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 14u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 15u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 16u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 17u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 18u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 19u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 20u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 21u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 22u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 23u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 24u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
        };
        VkDescriptorSetLayoutCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkDescriptorSetLayoutCreateFlagBits(0),
            /* bindingCount = */ 25u,
            /* pBindings = */ pBindings,
        };
        //VkResult result = vkCreateDescriptorSetLayout(VkDevice_5, &CreateInfo, NULL, &VkDescriptorSetLayout_1138);
        VkResult result = vkCreateDescriptorSetLayout(m_device, &CreateInfo, NULL, &VkDescriptorSetLayout_1138);
        assert(result == VK_SUCCESS);
    }

    //VkDescriptorSetLayout_1139
    {
        VkDescriptorSetLayoutBinding pBindings[55] = {
            { /* pBindings = */
                /* binding = */ 0u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 1u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 2u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 3u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 4u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 5u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 6u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 7u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 8u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 9u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 10u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 11u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 12u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 13u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 14u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 15u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 16u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 17u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 18u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 19u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 20u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 21u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 22u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 23u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 24u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 25u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 26u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 27u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 28u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 29u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 30u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 31u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 32u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 33u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 34u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 35u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 36u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 37u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 38u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 39u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 40u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 41u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 42u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 43u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 44u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 45u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 46u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 47u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 48u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 49u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 50u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 51u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 52u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 53u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 54u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
        };
        VkDescriptorSetLayoutCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkDescriptorSetLayoutCreateFlagBits(0),
            /* bindingCount = */ 55u,
            /* pBindings = */ pBindings,
        };
        //VkResult result = vkCreateDescriptorSetLayout(VkDevice_5, &CreateInfo, NULL, &VkDescriptorSetLayout_1139);
        VkResult result = vkCreateDescriptorSetLayout(m_device, &CreateInfo, NULL, &VkDescriptorSetLayout_1139);
        assert(result == VK_SUCCESS);
     }

    // VkDescriptorSetLayout_1140
    {
        VkDescriptorSetLayoutBinding pBindings[13] = {
            { /* pBindings = */
                /* binding = */ 0u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 1u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 2u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 3u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 4u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 5u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 6u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 7u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 8u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 9u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 10u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 11u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 12u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
        };
        VkDescriptorSetLayoutCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkDescriptorSetLayoutCreateFlagBits(0),
            /* bindingCount = */ 13u,
            /* pBindings = */ pBindings,
        };
        //VkResult result = vkCreateDescriptorSetLayout(VkDevice_5, &CreateInfo, NULL, &VkDescriptorSetLayout_1140);
        VkResult result = vkCreateDescriptorSetLayout(m_device, &CreateInfo, NULL, &VkDescriptorSetLayout_1140);
        assert(result == VK_SUCCESS);
    }

    //VkDescriptorSetLayout_1141
    {
        VkDescriptorSetLayoutBinding pBindings[10] = {
            { /* pBindings = */
                /* binding = */ 0u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 1u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 2u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 3u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 4u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 5u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 6u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 7u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 8u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 9u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
        };
        VkDescriptorSetLayoutCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkDescriptorSetLayoutCreateFlagBits(0),
            /* bindingCount = */ 10u,
            /* pBindings = */ pBindings,
        };
        //VkResult result = vkCreateDescriptorSetLayout(VkDevice_5, &CreateInfo, NULL, &VkDescriptorSetLayout_1141);
        VkResult result = vkCreateDescriptorSetLayout(m_device, &CreateInfo, NULL, &VkDescriptorSetLayout_1141);
        assert(result == VK_SUCCESS);
    }


    // VkDescriptorSetLayout_1226
    {
        VkDescriptorSetLayoutBinding pBindings[89] = {
            { /* pBindings = */
                /* binding = */ 0u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 1u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 2u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 3u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 4u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 5u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 6u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 7u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 8u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 9u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 10u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 11u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 12u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 13u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 14u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 15u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 16u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 17u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 18u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 19u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 20u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 21u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 22u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 23u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 24u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 25u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 26u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 27u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 28u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 29u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 30u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 31u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 32u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 33u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 34u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 35u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 36u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 37u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 38u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 39u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 40u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 41u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 42u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 43u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 44u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 45u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 46u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 47u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 48u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 49u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 50u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 51u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 52u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 53u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 54u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 55u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 56u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 57u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 58u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 59u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 60u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 61u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 62u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 63u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 64u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 65u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 66u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 67u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 68u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 69u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 70u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 71u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 72u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 73u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 74u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 75u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 76u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 77u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 78u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 79u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 80u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 81u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 82u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 83u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 84u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 85u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 86u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 87u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
            { /* pBindings = */
                /* binding = */ 88u,
                /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 1u,
                /* stageFlags = */ VK_SHADER_STAGE_ALL,
                /* pImmutableSamplers = */ NULL,
            },
        };
        VkDescriptorSetLayoutCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkDescriptorSetLayoutCreateFlagBits(0),
            /* bindingCount = */ 89u,
            /* pBindings = */ pBindings,
        };
        //VkResult result = vkCreateDescriptorSetLayout(VkDevice_5, &CreateInfo, NULL, &VkDescriptorSetLayout_1226);
        VkResult result = vkCreateDescriptorSetLayout(m_device, &CreateInfo, NULL, &VkDescriptorSetLayout_1226);
        assert(result == VK_SUCCESS);
    }

}

void InjectionContainer::CreatePipelineLayouts()
{
    VkDescriptorSetLayout pSetLayouts[5] = {
        /* pSetLayouts = */ VkDescriptorSetLayout_1138,
        /* pSetLayouts = */ VkDescriptorSetLayout_1139,
        /* pSetLayouts = */ VkDescriptorSetLayout_1140,
        /* pSetLayouts = */ VkDescriptorSetLayout_1141,
        /* pSetLayouts = */ VkDescriptorSetLayout_1226,
    };
    VkPipelineLayoutCreateInfo CreateInfo = {
        /* sType = */ VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        /* pNext = */ NULL,
        /* flags = */ 0,
        /* setLayoutCount = */ 5u,
        /* pSetLayouts = */ pSetLayouts,
        /* pushConstantRangeCount = */ 0u,
        /* pPushConstantRanges = */ NULL,
    };
    //VkResult result = vkCreatePipelineLayout(VkDevice_5, &CreateInfo, NULL, &VkPipelineLayout_1231);
    VkResult result = vkCreatePipelineLayout(m_device, &CreateInfo, NULL, &VkPipelineLayout_1231);
    assert(result == VK_SUCCESS);
}

void InjectionContainer::CreateDescriptorPools()
{
    {
        //std::vector<VkDescriptorPoolSize> VkDescriptorPoolSize_22232;

        VkDescriptorPoolSize pPoolSizes[7] = {
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 25600u,
            },
        };
        VkDescriptorPoolCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT,
            /* maxSets = */ 8192u,
            /* poolSizeCount = */ 7u,
            /* pPoolSizes = */ pPoolSizes,
        };
        //for (uint32_t i = 0; i < CreateInfo.poolSizeCount; i++) {
        //    VkDescriptorPoolSize_22232.push_back(CreateInfo.pPoolSizes[i]);
        //}
        //CreateInfo.pPoolSizes = VkDescriptorPoolSize_22232.data();
        //VkResult result = vkCreateDescriptorPool(VkDevice_5, &CreateInfo, NULL, &VkDescriptorPool_22232);
        VkResult result = vkCreateDescriptorPool(m_device, &CreateInfo, NULL, &VkDescriptorPool_22232);
        assert(result == VK_SUCCESS);
        //VkDescriptorPoolCreateInfo_22232 = CreateInfo;
        //VkDescriptorPoolVec_22232.push_back(VkDescriptorPool_22232);
    }

    {
        std::vector<VkDescriptorPoolSize> VkDescriptorPoolSize_1137;

        VkDescriptorPoolSize pPoolSizes[7] = {
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_SAMPLER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_IMAGE,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                /* descriptorCount = */ 25600u,
            },
            { /* pPoolSizes = */
                /* type = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                /* descriptorCount = */ 25600u,
            },
        };
        VkDescriptorPoolCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT,
            /* maxSets = */ 16384u,
            /* poolSizeCount = */ 7u,
            /* pPoolSizes = */ pPoolSizes,
        };
        //for (uint32_t i = 0; i < CreateInfo.poolSizeCount; i++) {
        //    VkDescriptorPoolSize_1137.push_back(CreateInfo.pPoolSizes[i]);
        //}
        //CreateInfo.pPoolSizes = VkDescriptorPoolSize_1137.data();
        //VkResult result = vkCreateDescriptorPool(VkDevice_5, &CreateInfo, NULL, &VkDescriptorPool_1137);
        VkResult result = vkCreateDescriptorPool(m_device, &CreateInfo, NULL, &VkDescriptorPool_1137);
        assert(result == VK_SUCCESS);
        //VkDescriptorPoolCreateInfo_1137 = CreateInfo;
        //VkDescriptorPoolVec_1137.push_back(VkDescriptorPool_1137);
    }

}

void InjectionContainer::AllocateDescriptorSets()
{
    // TODO: Functionalize this?

    // VkDescriptorSet_15840359
    {
        VkDescriptorSetLayout pSetLayouts[1] = {
            /* pSetLayouts = */ VkDescriptorSetLayout_1138,
        };
        VkDescriptorSetAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* descriptorPool = */ VkDescriptorPool_22232,
            /* descriptorSetCount = */ 1u,
            /* pSetLayouts = */ pSetLayouts,
        };
        //VkResult result = vkAllocateDescriptorSets(VkDevice_5, &AllocateInfo, &VkDescriptorSet_15840359);
        VkResult result = vkAllocateDescriptorSets(m_device, &AllocateInfo, &VkDescriptorSet_15840359);
        assert(result == VK_SUCCESS);
    }

    // VkDescriptorSet_15840362
    {
        VkDescriptorSetLayout pSetLayouts[1] = {
            /* pSetLayouts = */ VkDescriptorSetLayout_1139,
        };
        VkDescriptorSetAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* descriptorPool = */ VkDescriptorPool_22232,
            /* descriptorSetCount = */ 1u,
            /* pSetLayouts = */ pSetLayouts,
        };
        //VkResult result = vkAllocateDescriptorSets(VkDevice_5, &AllocateInfo, &VkDescriptorSet_15840362);
        VkResult result = vkAllocateDescriptorSets(m_device, &AllocateInfo, &VkDescriptorSet_15840362);
        assert(result == VK_SUCCESS);
    }

    // VkDescriptorSet_1254
    {
        VkDescriptorSetLayout pSetLayouts[1] = {
            /* pSetLayouts = */ VkDescriptorSetLayout_1140,
        };
        VkDescriptorSetAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* descriptorPool = */ VkDescriptorPool_1137,
            /* descriptorSetCount = */ 1u,
            /* pSetLayouts = */ pSetLayouts,
        };
        //VkResult result = vkAllocateDescriptorSets(VkDevice_5, &AllocateInfo, &VkDescriptorSet_1254);
        VkResult result = vkAllocateDescriptorSets(m_device, &AllocateInfo, &VkDescriptorSet_1254);
        assert(result == VK_SUCCESS);
    }

    // VkDescriptorSet_15840552
    {
        VkDescriptorSetLayout pSetLayouts[1] = {
            /* pSetLayouts = */ VkDescriptorSetLayout_1141,
        };
        VkDescriptorSetAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* descriptorPool = */ VkDescriptorPool_22232,
            /* descriptorSetCount = */ 1u,
            /* pSetLayouts = */ pSetLayouts,
        };
        //VkResult result = vkAllocateDescriptorSets(VkDevice_5, &AllocateInfo, &VkDescriptorSet_15840552);
        VkResult result = vkAllocateDescriptorSets(m_device, &AllocateInfo, &VkDescriptorSet_15840552);
        assert(result == VK_SUCCESS);
    }

    // VkDescriptorSet_15840555
    {
        VkDescriptorSetLayout pSetLayouts[1] = {
            /* pSetLayouts = */ VkDescriptorSetLayout_1226,
        };
        VkDescriptorSetAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* descriptorPool = */ VkDescriptorPool_22232,
            /* descriptorSetCount = */ 1u,
            /* pSetLayouts = */ pSetLayouts,
        };
        //VkResult result = vkAllocateDescriptorSets(VkDevice_5, &AllocateInfo, &VkDescriptorSet_15840555);
        VkResult result = vkAllocateDescriptorSets(m_device, &AllocateInfo, &VkDescriptorSet_15840555);
        assert(result == VK_SUCCESS);
    }

}

void InjectionContainer::UpdateDescriptorSets()
{
}
