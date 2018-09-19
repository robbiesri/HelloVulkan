#include "Injection.h"

#include <assert.h>
#include <vector>

/*
To create:

buffer memory
VkDeviceMemory_185
VkDeviceMemory_963
VkDeviceMemory_13619
VkDeviceMemory_4228

image memory
VkDeviceMemory_8977521
VkDeviceMemory_9414592
VkDeviceMemory_7793
VkDeviceMemory_9331068
VkDeviceMemory_9291315
VkDeviceMemory_21191
VkDeviceMemory_21183
VkDeviceMemory_21187 
VkDeviceMemory_8976432
VkDeviceMemory_18858
VkDeviceMemory_10831813

VkBuffer_1136;
VkBuffer_1091;
VkBuffer_19003;
VkBuffer_8981352;
VkBuffer_10838418;
VkBuffer_1373;
VkBuffer_4271;
VkBuffer_4275;

VkBuffer_1096
VkBuffer_1358
VkBuffer_4256
VkBuffer_4281

VkBufferView_1098;
VkBufferView_1360;
VkBufferView_4258
VkBufferView_4283;

VkImage_9013537
VkImage_9434269
VkImage_9013954
VkImage_10929
VkImage_9331134
VkImage_9331137
VkImage_9331096
VkImage_9331099
VkImage_9331090
VkImage_1453
VkImage_34748
VkImage_21182
VkImage_21186
VkImage_21190
VkImage_21194
VkImage_18801
VkImage_21197
VkImage_972
VkImage_987
VkImage_984
VkImage_10882643
VkImage_10894040
VkImage_10882657
VkImage_10832257
VkImage_19025
VkImage_1017
VkImage_1026
VkImage_1441
VkImage_10831998
VkImage_18649

VkImageView_9013541;
VkImageView_9434270;
VkImageView_9013956;
VkImageView_10931;
VkImageView_9331135;
VkImageView_9331138;
VkImageView_9331097;
VkImageView_9331100;
VkImageView_9331091;
VkImageView_1454;
VkImageView_34751;
VkImageView_21184;
VkImageView_21188;
VkImageView_21192;
VkImageView_21195;
VkImageView_18802
VkImageView_21199
VkImageView_973
VkImageView_988
VkImageView_985
VkImageView_10882645
VkImageView_10894042
VkImageView_10882658
VkImageView_10832259
VkImageView_19027
VkImageView_1018
VkImageView_1027
VkImageView_1442
VkImageView_10832000
VkImageView_18651

shader module
graphics pipeline
bind pipeline layout to graphics pipeline

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

VkSampler_1174;
VkSampler_18590;
VkSampler_18587;
VkSampler_18586;
VkSampler_1179;
VkSampler_1176;
VkSampler_1177;
VkSampler_1051
VkSampler_6244

************************
To update:

Updated:

VkDescriptorSet_15840359
VkDescriptorSet_15840362
VkDescriptorSet_1254
VkDescriptorSet_15840552
VkDescriptorSet_15840555

*/

void InjectionContainer::CreateResources(VkDevice device)
{
    m_device = device;

    CreateDescriptorSetLayouts();
    CreatePipelineLayouts();

    CreateDescriptorPools();
    AllocateDescriptorSets();

    // update descriptor sets
    // only need to do this once!
    UpdateDescriptorSets();

    CreateSamplers();
}

void InjectionContainer::BuildCommandBuffer(VkCommandBuffer commandBuffer)
{
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
    // VkDescriptorSet_15840359 + VkDescriptorSet_15840362
    {
        // VkDescriptorSet_15840359 - 25 writes

        VkDescriptorBufferInfo pBufferInfo_0[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12637424u,
                /* range = */ 8336u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_0 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 0u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_0,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_1[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_1174,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_1 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 1u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_1,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_2[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_18590,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_2 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 2u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_2,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_3[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_18587,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_3 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 3u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_3,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_4[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_18586,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_4 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 4u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_4,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_5[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_1179,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_5 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 5u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_5,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_6[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_1176,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_6 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 6u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_6,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_7[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9013541,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_7 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 7u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_7,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_8[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9434270,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_8 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 8u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_8,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_9[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9434270,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_9 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 9u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_9,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_10[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9013956,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_10 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 10u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_10,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_11[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10931,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_11 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 11u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_11,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_12[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9331135,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_12 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 12u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_12,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_13[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9331138,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_13 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 13u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_13,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_14[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9331097,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_14 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 14u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_14,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_15[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9331100,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_15 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 15u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_15,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_16[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_9331091,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_16 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 16u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_16,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_17[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1454,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_17 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 17u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_17,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_18[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_34751,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_18 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 18u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_18,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_19[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_21184,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_19 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 19u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_19,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_20[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_21188,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_20 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 20u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_20,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_21[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_21192,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_21 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 21u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_21,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_22[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_21195,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_22 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 22u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_22,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkBufferView pTexelBufferView_23[1] = {
            /* pTexelBufferView = */ VkBufferView_1098,
        };
        VkWriteDescriptorSet pDescriptorWrites_23 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 23u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ pTexelBufferView_23,
        };
        VkDescriptorBufferInfo pBufferInfo_24[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1091,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_24 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840359,
            /* dstBinding = */ 24u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_24,
            /* pTexelBufferView = */ NULL,
        };

        // VkDescriptorSet_15840362 - 23 writes

        VkDescriptorBufferInfo pBufferInfo_25[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12677904u,
                /* range = */ 1632u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_25 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 0u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_25,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_26[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_1177,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_26 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 1u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_26,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_27[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_1051,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_27 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 2u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_27,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_28[1] = {
            { /* pImageInfo = */
                /* sampler = */ VkSampler_6244,
                /* imageView = */ NULL,
                /* imageLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_28 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 3u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLER,
            /* pImageInfo = */ pImageInfo_28,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_29[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_18802,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_29 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 4u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_29,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_30[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_21199,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_30 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 5u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_30,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_31[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_973,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_31 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 6u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_31,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_32[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_973,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_32 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 7u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_32,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_33[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_988,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_33 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 27u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_33,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_34[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_985,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_34 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 28u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_34,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_35[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10882645,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_35 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 29u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_35,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_36[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10894042,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_36 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 30u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_36,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_37[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10882658,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_37 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 31u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_37,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_38[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10832259,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_38 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 32u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_38,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_39[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_19027,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_39 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 36u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_39,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_40[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1018,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_40 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 40u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_40,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_41[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1018,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_41 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 41u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_41,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_42[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1018,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_42 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 42u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_42,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_43[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1027,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_43 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 43u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_43,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_44[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1027,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_44 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 44u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_44,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_45[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_1442,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_45 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 45u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_45,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_46[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_10832000,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_46 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 46u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_46,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_47[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_19003,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_47 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840362,
            /* dstBinding = */ 53u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_47,
            /* pTexelBufferView = */ NULL,
        };

        //VkWriteDescriptorSet pDescriptorWrites[56] = {
        VkWriteDescriptorSet pDescriptorWrites[48] = {
            /* pDescriptorWrites = */ pDescriptorWrites_0,
            /* pDescriptorWrites = */ pDescriptorWrites_1,
            /* pDescriptorWrites = */ pDescriptorWrites_2,
            /* pDescriptorWrites = */ pDescriptorWrites_3,
            /* pDescriptorWrites = */ pDescriptorWrites_4,
            /* pDescriptorWrites = */ pDescriptorWrites_5,
            /* pDescriptorWrites = */ pDescriptorWrites_6,
            /* pDescriptorWrites = */ pDescriptorWrites_7,
            /* pDescriptorWrites = */ pDescriptorWrites_8,
            /* pDescriptorWrites = */ pDescriptorWrites_9,
            /* pDescriptorWrites = */ pDescriptorWrites_10,
            /* pDescriptorWrites = */ pDescriptorWrites_11,
            /* pDescriptorWrites = */ pDescriptorWrites_12,
            /* pDescriptorWrites = */ pDescriptorWrites_13,
            /* pDescriptorWrites = */ pDescriptorWrites_14,
            /* pDescriptorWrites = */ pDescriptorWrites_15,
            /* pDescriptorWrites = */ pDescriptorWrites_16,
            /* pDescriptorWrites = */ pDescriptorWrites_17,
            /* pDescriptorWrites = */ pDescriptorWrites_18,
            /* pDescriptorWrites = */ pDescriptorWrites_19,
            /* pDescriptorWrites = */ pDescriptorWrites_20,
            /* pDescriptorWrites = */ pDescriptorWrites_21,
            /* pDescriptorWrites = */ pDescriptorWrites_22,
            /* pDescriptorWrites = */ pDescriptorWrites_23,
            /* pDescriptorWrites = */ pDescriptorWrites_24,
            /* pDescriptorWrites = */ pDescriptorWrites_25,
            /* pDescriptorWrites = */ pDescriptorWrites_26,
            /* pDescriptorWrites = */ pDescriptorWrites_27,
            /* pDescriptorWrites = */ pDescriptorWrites_28,
            /* pDescriptorWrites = */ pDescriptorWrites_29,
            /* pDescriptorWrites = */ pDescriptorWrites_30,
            /* pDescriptorWrites = */ pDescriptorWrites_31,
            /* pDescriptorWrites = */ pDescriptorWrites_32,
            /* pDescriptorWrites = */ pDescriptorWrites_33,
            /* pDescriptorWrites = */ pDescriptorWrites_34,
            /* pDescriptorWrites = */ pDescriptorWrites_35,
            /* pDescriptorWrites = */ pDescriptorWrites_36,
            /* pDescriptorWrites = */ pDescriptorWrites_37,
            /* pDescriptorWrites = */ pDescriptorWrites_38,
            /* pDescriptorWrites = */ pDescriptorWrites_39,
            /* pDescriptorWrites = */ pDescriptorWrites_40,
            /* pDescriptorWrites = */ pDescriptorWrites_41,
            /* pDescriptorWrites = */ pDescriptorWrites_42,
            /* pDescriptorWrites = */ pDescriptorWrites_43,
            /* pDescriptorWrites = */ pDescriptorWrites_44,
            /* pDescriptorWrites = */ pDescriptorWrites_45,
            /* pDescriptorWrites = */ pDescriptorWrites_46,
            /* pDescriptorWrites = */ pDescriptorWrites_47,
            ///* pDescriptorWrites = */ pDescriptorWrites_48,
            ///* pDescriptorWrites = */ pDescriptorWrites_49,
            ///* pDescriptorWrites = */ pDescriptorWrites_50,
            ///* pDescriptorWrites = */ pDescriptorWrites_51,
            ///* pDescriptorWrites = */ pDescriptorWrites_52,
            ///* pDescriptorWrites = */ pDescriptorWrites_53,
            ///* pDescriptorWrites = */ pDescriptorWrites_54,
            ///* pDescriptorWrites = */ pDescriptorWrites_55,
        };
        VkCopyDescriptorSet* pDescriptorCopies = NULL;
        //vkUpdateDescriptorSets(VkDevice_5, 56, pDescriptorWrites, 0, pDescriptorCopies);
        vkUpdateDescriptorSets(m_device, 48, pDescriptorWrites, 0, pDescriptorCopies);
    }

    //VkDescriptorSet_1254 - no writes? no use?
    {

    }

    // VkDescriptorSet_15840552 + VkDescriptorSet_15840555
    // could split these into two writes...
    {
        // VkDescriptorSet_15840552 - 3 writes

        VkDescriptorBufferInfo pBufferInfo_0[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12679536u,
                /* range = */ 320u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_0 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840552,
            /* dstBinding = */ 0u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_0,
            /* pTexelBufferView = */ NULL,
        };
        VkBufferView pTexelBufferView_1[1] = {
            /* pTexelBufferView = */ VkBufferView_1360,
        };
        VkWriteDescriptorSet pDescriptorWrites_1 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840552,
            /* dstBinding = */ 3u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ pTexelBufferView_1,
        };
        VkDescriptorBufferInfo pBufferInfo_2[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12679856u,
                /* range = */ 304u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_2 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840552,
            /* dstBinding = */ 1u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_2,
            /* pTexelBufferView = */ NULL,
        };



        //VkDescriptorSet_15840555 - 11 writes
        VkDescriptorBufferInfo pBufferInfo_3[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12765088u,
                /* range = */ 16u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_3 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 1u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_3,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorImageInfo pImageInfo_4[1] = {
            { /* pImageInfo = */
                /* sampler = */ NULL,
                /* imageView = */ VkImageView_18651,
                /* imageLayout = */ VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_4 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 24u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,
            /* pImageInfo = */ pImageInfo_4,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ NULL,
        };
        VkBufferView pTexelBufferView_5[1] = {
            /* pTexelBufferView = */ VkBufferView_4258,
        };
        VkWriteDescriptorSet pDescriptorWrites_5 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 69u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ pTexelBufferView_5,
        };
        VkBufferView pTexelBufferView_6[1] = {
            /* pTexelBufferView = */ VkBufferView_4283,
        };
        VkWriteDescriptorSet pDescriptorWrites_6 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 70u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ NULL,
            /* pTexelBufferView = */ pTexelBufferView_6,
        };
        VkDescriptorBufferInfo pBufferInfo_7[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_8981352,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_7 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 79u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_7,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_8[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_10838418,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_8 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 80u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_8,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_9[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1373,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_9 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 81u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_9,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_10[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_4271,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_10 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 86u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_10,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_11[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_4275,
                /* offset = */ 0u,
                /* range = */ 18446744073709551615u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_11 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 87u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_11,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_12[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12677600u,
                /* range = */ 288u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_12 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 2u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_12,
            /* pTexelBufferView = */ NULL,
        };
        VkDescriptorBufferInfo pBufferInfo_13[1] = {
            { /* pBufferInfo = */
                /* buffer = */ VkBuffer_1136,
                /* offset = */ 12676976u,
                /* range = */ 624u,
            },
        };
        VkWriteDescriptorSet pDescriptorWrites_13 = {
            /* sType = */ VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            /* pNext = */ NULL,
            /* dstSet = */ VkDescriptorSet_15840555,
            /* dstBinding = */ 3u,
            /* dstArrayElement = */ 0u,
            /* descriptorCount = */ 1u,
            /* descriptorType = */ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            /* pImageInfo = */ NULL,
            /* pBufferInfo = */ pBufferInfo_13,
            /* pTexelBufferView = */ NULL,
        };

        VkWriteDescriptorSet pDescriptorWrites[14] = {
            /* pDescriptorWrites = */ pDescriptorWrites_0,
            /* pDescriptorWrites = */ pDescriptorWrites_1,
            /* pDescriptorWrites = */ pDescriptorWrites_2,
            /* pDescriptorWrites = */ pDescriptorWrites_3,
            /* pDescriptorWrites = */ pDescriptorWrites_4,
            /* pDescriptorWrites = */ pDescriptorWrites_5,
            /* pDescriptorWrites = */ pDescriptorWrites_6,
            /* pDescriptorWrites = */ pDescriptorWrites_7,
            /* pDescriptorWrites = */ pDescriptorWrites_8,
            /* pDescriptorWrites = */ pDescriptorWrites_9,
            /* pDescriptorWrites = */ pDescriptorWrites_10,
            /* pDescriptorWrites = */ pDescriptorWrites_11,
            /* pDescriptorWrites = */ pDescriptorWrites_12,
            /* pDescriptorWrites = */ pDescriptorWrites_13,
        };
        VkCopyDescriptorSet* pDescriptorCopies = NULL;
        //vkUpdateDescriptorSets(VkDevice_5, 14, pDescriptorWrites, 0, pDescriptorCopies);
        vkUpdateDescriptorSets(m_device, 14, pDescriptorWrites, 0, pDescriptorCopies);
    }

}

void InjectionContainer::AllocateMemory()
{

}

void InjectionContainer::CreateBuffers()
{

}

void InjectionContainer::CreateBufferViews()
{

}

void InjectionContainer::CreateImages()
{

}

void InjectionContainer::CreateImageViews()
{

}

void InjectionContainer::CreateSamplers()
{
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_NEAREST,
            /* minFilter = */ VK_FILTER_NEAREST,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_NEAREST,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        //VkResult result = vkCreateSampler(VkDevice_5, &CreateInfo, NULL, &VkSampler_1174);
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_1174);
        assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_NEAREST,
            /* minFilter = */ VK_FILTER_NEAREST,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_NEAREST,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        //VkResult result = vkCreateSampler(VkDevice_5, &CreateInfo, NULL, &VkSampler_18590);
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_18590);
        assert(result == VK_SUCCESS);
    }

    {
    VkSamplerCreateInfo CreateInfo = {
        /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
        /* pNext = */ NULL,
        /* flags = */ 0,
        /* magFilter = */ VK_FILTER_LINEAR,
        /* minFilter = */ VK_FILTER_LINEAR,
        /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
        /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        /* mipLodBias = */ 0.000000f,
        /* anisotropyEnable = */ 0u,
        /* maxAnisotropy = */ 0.000000f,
        /* compareEnable = */ 0u,
        /* compareOp = */ VK_COMPARE_OP_NEVER,
        /* minLod = */ -340282346638528859811704183484516925440.000000f,
        /* maxLod = */ 340282346638528859811704183484516925440.000000f,
        /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
        /* unnormalizedCoordinates = */ 0u,
    };
    VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_18587);
    assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_18586);
        assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_REPEAT,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 1u,
            /* maxAnisotropy = */ 16.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_1179);
        assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 1u,
            /* compareOp = */ VK_COMPARE_OP_LESS_OR_EQUAL,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_1176);
        assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_1177);
        assert(result == VK_SUCCESS);
    }
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_1051);
        assert(result == VK_SUCCESS);
    }    
    {
        VkSamplerCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* magFilter = */ VK_FILTER_LINEAR,
            /* minFilter = */ VK_FILTER_LINEAR,
            /* mipmapMode = */ VK_SAMPLER_MIPMAP_MODE_LINEAR,
            /* addressModeU = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* addressModeV = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* addressModeW = */ VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
            /* mipLodBias = */ 0.000000f,
            /* anisotropyEnable = */ 0u,
            /* maxAnisotropy = */ 0.000000f,
            /* compareEnable = */ 0u,
            /* compareOp = */ VK_COMPARE_OP_NEVER,
            /* minLod = */ -340282346638528859811704183484516925440.000000f,
            /* maxLod = */ 340282346638528859811704183484516925440.000000f,
            /* borderColor = */ VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK,
            /* unnormalizedCoordinates = */ 0u,
        };
        VkResult result = vkCreateSampler(m_device, &CreateInfo, NULL, &VkSampler_6244);
        assert(result == VK_SUCCESS);
    }
}