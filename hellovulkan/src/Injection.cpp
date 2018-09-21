#include "Injection.h"

#include <assert.h>
#include <vector>

/*
To create:

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

buffer memory
VkDeviceMemory_185
VkDeviceMemory_963
VkDeviceMemory_13619
VkDeviceMemory_4228
VkDeviceMemory_1359
VkDeviceMemory_1376

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

VkShaderModule_9511
VkPipeline_10836480

************************
To update:

initialize memories?
buffer memory
VkDeviceMemory_185
VkDeviceMemory_963
VkDeviceMemory_13619
VkDeviceMemory_4228
VkDeviceMemory_1359
VkDeviceMemory_1376

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

Updated:

VkDescriptorSet_15840359
VkDescriptorSet_15840362
VkDescriptorSet_1254
VkDescriptorSet_15840552
VkDescriptorSet_15840555



*/

// utils (maybe new file?)
void ReadBuffer(const char *name, std::vector<uint8_t> &buf)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL)
    {
        return;
    }

    fseek(f, 0, SEEK_END);
    uint64_t length = ftell(f);
    buf.resize(length);
    rewind(f);

    uint64_t result = fread(buf.data(), 1, length, f);
    fclose(f);
    assert(result <= length);
}

void InjectionContainer::CreateResources(VkDevice device)
{
    m_device = device;

    CreateDescriptorSetLayouts();
    CreatePipelineLayouts();

    CreateDescriptorPools();
    AllocateDescriptorSets();

    CreateSamplers();

    AllocateMemory();

    CreateBuffers();
    BindBufferMemory();
    CreateBufferViews();

    CreateImages();
    BindImageMemory();
    CreateImageViews();

    // update descriptor sets
    // only need to do this once!
    UpdateDescriptorSets();

    CreateShader();

    CreateResetBuffersAndImages();
}

void InjectionContainer::BuildCommandBuffer(VkCommandBuffer commandBuffer)
{
    //ResetBuffers(commandBuffer);

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

    // bind shader
    vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, VkPipeline_10836480);

    // shouldn't need pipeline barrier, assuming resources are in correct state!

    // kick off work finally!
    vkCmdDispatch(commandBuffer, 859u, 1u, 1u);

    VkMemoryBarrier pMemoryBarriers[1] = {
        { /* pMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_SHADER_READ_BIT,
        },
    };
    VkBufferMemoryBarrier* pBufferMemoryBarriers = NULL;
    VkImageMemoryBarrier* pImageMemoryBarriers = NULL;
    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 1, pMemoryBarriers, 0, pBufferMemoryBarriers, 0, pImageMemoryBarriers);
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
    // TODO: Descriptor buffer ranges are weird

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
    // any of these might need to change memory type index or the memory size
    // index should be easy
    // size...maybe not

    // these are the host visible allocs
    // VkDeviceMemory_185
    //      VkBuffer_1136 - Constant buffers
    // VkDeviceMemory_4228
    //      VkBuffer_8981352
    //          4 79: Xhlslcc_set_4_bind_79X_ClusteredInstanceCullingParams_Batches RW Buffer Buffer 559 15000 bytes Viewing bytes 0 - 15000
    //      VkBuffer_10838418
    //          4 80: Xhlslcc_set_4_bind_80X_ClusteredInstanceCullingParams_Instances RW Buffer Buffer 2587 638976 bytes Viewing bytes 0 - 638976
    // VkDeviceMemory_1359
    //      VkBuffer_1358
    //          3 3: Xhlslcc_set_3_bind_3X_InstanceParams_instancing_instanceData TexBuffer Buffer 142 R32G32B32A32_FLOAT bytes 0 - 266338304

    // 1359 is the most offensive, as Buffer 1358 is one of the primary inputs for the work


    //      buffer memory
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 1u, // WARNING...but this is ok, constant buffer
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_185);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_963);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_13619);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 1u, // WARNING
            ///* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_4228);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 266338304u,
            /* memoryTypeIndex = */ 1u, // WARNING
            ///* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_1359);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_1376);
        assert(result == VK_SUCCESS);
    }


    //    image memory
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_8977521);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_9414592);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_7793);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_9331068);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_9291315);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_21191);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 41156608u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_21183);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 41156608u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_21187);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_8976432);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_18858);
        assert(result == VK_SUCCESS);
    }
    {
        VkMemoryAllocateInfo AllocateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            /* pNext = */ NULL,
            /* allocationSize = */ 67108864u,
            /* memoryTypeIndex = */ 0u,
        };
        VkResult result = vkAllocateMemory(m_device, &AllocateInfo, NULL, &VkDeviceMemory_10831813);
        assert(result == VK_SUCCESS);
    }

}

void InjectionContainer::CreateBuffers()
{
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 18874368u,
            /* usage = */ VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_1136 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_1136);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 352u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_1091 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_1091);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 4096u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_19003 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_19003);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 15000u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_8981352 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_8981352);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 638976u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_10838418 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_10838418);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 16777208u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_1373 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_1373);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 16u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_4271 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_4271);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 1440000u,
            /* usage = */ VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_4275 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_4275);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 1104u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_1096 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_1096);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 266338304u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_1358 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_1358);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 12779520u,
            /* usage = */ VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_4256 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_4256);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkBufferCreateFlagBits(0),
            /* size = */ 2555904u,
            /* usage = */ VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
        };
        //VkBufferCreateInfo_4281 = CreateInfo;
        VkResult result = vkCreateBuffer(m_device, &CreateInfo, NULL, &VkBuffer_4281);
        assert(result == VK_SUCCESS);
    }
}

void InjectionContainer::BindBufferMemory()
{
    VkResult result;
    
    result = vkBindBufferMemory(m_device, VkBuffer_1136, VkDeviceMemory_185, 4096 /* rdoc:value 4096 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_1091, VkDeviceMemory_963, 4771648 /* rdoc:value 4771648 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_19003, VkDeviceMemory_13619, 29159424 /* rdoc:value 29159424 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_8981352, VkDeviceMemory_4228, 28761024 /* rdoc:value 28761024 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_10838418, VkDeviceMemory_4228, 33729888 /* rdoc:value 33729888 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_1373, VkDeviceMemory_963, 9916416 /* rdoc:value 9916416 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_4271, VkDeviceMemory_963, 61606976 /* rdoc:value 61606976 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_4275, VkDeviceMemory_963, 61606992 /* rdoc:value 61606992 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_1096, VkDeviceMemory_963, 4773456 /* rdoc:value 4773456 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_1358, VkDeviceMemory_1359, 0 /* rdoc:value 0 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_4256, VkDeviceMemory_1376, 44236800 /* rdoc:value 44236800 */);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(m_device, VkBuffer_4281, VkDeviceMemory_963, 63082496 /* rdoc:value 63082496 */);
    assert(result == VK_SUCCESS);
}

void InjectionContainer::CreateBufferViews()
{
    {
        VkBufferViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* buffer = */ VkBuffer_1096,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            /* offset = */ 0u,
            /* range = */ 1104u,
        };
        VkResult result = vkCreateBufferView(m_device, &CreateInfo, NULL, &VkBufferView_1098);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* buffer = */ VkBuffer_1358,
            /* format = */ VK_FORMAT_R32G32B32A32_SFLOAT,
            /* offset = */ 0u,
            /* range = */ 266338304u,
        };
        VkResult result = vkCreateBufferView(m_device, &CreateInfo, NULL, &VkBufferView_1360);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* buffer = */ VkBuffer_4256,
            /* format = */ VK_FORMAT_R32_UINT,
            /* offset = */ 0u,
            /* range = */ 12779520u,
        };
        VkResult result = vkCreateBufferView(m_device, &CreateInfo, NULL, &VkBufferView_4258);
        assert(result == VK_SUCCESS);
    }
    {
        VkBufferViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* buffer = */ VkBuffer_4281,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            /* offset = */ 0u,
            /* range = */ 2555904u,
        };
        VkResult result = vkCreateBufferView(m_device, &CreateInfo, NULL, &VkBufferView_4283);
        assert(result == VK_SUCCESS);
    }
}

void InjectionContainer::CreateImages()
{
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8_UNORM,
            { /* extent = */
                /* width = */ 512u,
                /* height = */ 512u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9013537 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9013537);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_SNORM,
            { /* extent = */
                /* width = */ 128u,
                /* height = */ 128u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9434269 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9434269);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_SNORM,
            { /* extent = */
                /* width = */ 2048u,
                /* height = */ 1u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9013954 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9013954);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 512u,
                /* height = */ 512u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 10u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10929 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10929);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9331134 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9331134);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9331137 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9331137);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_SRGB_BLOCK,
            { /* extent = */
                /* width = */ 3432u,
                /* height = */ 3432u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9331096 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9331096);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 3432u,
                /* height = */ 3432u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9331099 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9331099);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R16_UNORM,
            { /* extent = */
                /* width = */ 3432u,
                /* height = */ 3432u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_9331090 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_9331090);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_B8G8R8A8_SRGB,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_1453 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_1453);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 1024u,
                /* height = */ 1024u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 11u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_34748 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_34748);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 6336u,
                /* height = */ 6336u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_21182 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_21182);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC5_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 6336u,
                /* height = */ 6336u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_21186 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_21186);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 6336u,
                /* height = */ 6336u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_21190 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_21190);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_BC4_UNORM_BLOCK,
            { /* extent = */
                /* width = */ 6336u,
                /* height = */ 6336u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_21194 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_21194);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* extent = */
                /* width = */ 1u,
                /* height = */ 1u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_18801 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_18801);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R32_UINT,
            { /* extent = */
                /* width = */ 1024u,
                /* height = */ 1024u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 11u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_21197 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_21197);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_972 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_972);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_3D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 4u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_987 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_987);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_3D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 4u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_984 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_984);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10882643 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10882643);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8_UNORM,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10894040 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10894040);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 64u,
                /* height = */ 64u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10882657 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10882657);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* extent = */
                /* width = */ 128u,
                /* height = */ 128u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10832257 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10832257);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_19025 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_19025);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_1017 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_1017);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* extent = */
                /* width = */ 4u,
                /* height = */ 4u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 4u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_1026 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_1026);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_B8G8R8A8_UNORM,
            { /* extent = */
                /* width = */ 64u,
                /* height = */ 64u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_1441 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_1441);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* extent = */
                /* width = */ 256u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 1u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_10831998 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_10831998);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkImageCreateFlagBits(0),
            /* imageType = */ VK_IMAGE_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* extent = */
                /* width = */ 512u,
                /* height = */ 256u,
                /* depth = */ 1u,
            },
            /* mipLevels = */ 9u,
            /* arrayLayers = */ 1u,
            /* samples = */ VK_SAMPLE_COUNT_1_BIT,
            /* tiling = */ VK_IMAGE_TILING_OPTIMAL,
            /* usage = */ VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_STORAGE_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | /*rdoc:init*/ VK_IMAGE_USAGE_TRANSFER_DST_BIT,
            /* sharingMode = */ VK_SHARING_MODE_EXCLUSIVE,
            /* queueFamilyIndexCount = */ 0u,
            /* pQueueFamilyIndices = */ NULL,
            /* initialLayout = */ VK_IMAGE_LAYOUT_UNDEFINED,
        };
        //VkImageCreateInfo_18649 = CreateInfo;
        VkResult result = vkCreateImage(m_device, &CreateInfo, NULL, &VkImage_18649);
        assert(result == VK_SUCCESS);
    }
}

void InjectionContainer::BindImageMemory()
{
    VkResult result;

    result = vkBindImageMemory(m_device, VkImage_9013537, VkDeviceMemory_8977521, 41222144 /* rdoc:value 41222144 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9434269, VkDeviceMemory_9414592, 26935296 /* rdoc:value 26935296 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9013954, VkDeviceMemory_8977521, 49283072 /* rdoc:value 49283072 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10929, VkDeviceMemory_7793, 32374784 /* rdoc:value 32374784 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9331134, VkDeviceMemory_9331068, 10747904 /* rdoc:value 10747904 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9331137, VkDeviceMemory_9331068, 11272192 /* rdoc:value 11272192 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9331096, VkDeviceMemory_9291315, 35127296 /* rdoc:value 35127296 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9331099, VkDeviceMemory_9291315, 48234496 /* rdoc:value 48234496 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_9331090, VkDeviceMemory_9291315, 10158080 /* rdoc:value 10158080 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_1453, VkDeviceMemory_963, 58884096 /* rdoc:value 58884096 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_34748, VkDeviceMemory_21191, 66060288 /* rdoc:value 66060288 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_21182, VkDeviceMemory_21183, 0 /* rdoc:value 0 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_21186, VkDeviceMemory_21187, 0 /* rdoc:value 0 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_21190, VkDeviceMemory_21191, 0 /* rdoc:value 0 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_21194, VkDeviceMemory_21191, 21495808 /* rdoc:value 21495808 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_18801, VkDeviceMemory_13619, 46956544 /* rdoc:value 46956544 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_21197, VkDeviceMemory_21191, 42991616 /* rdoc:value 42991616 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_972, VkDeviceMemory_963, 32768 /* rdoc:value 32768 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_987, VkDeviceMemory_963, 131072 /* rdoc:value 131072 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_984, VkDeviceMemory_963, 98304 /* rdoc:value 98304 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10882643, VkDeviceMemory_8976432, 9371648 /* rdoc:value 9371648 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10894040, VkDeviceMemory_8976432, 26607616 /* rdoc:value 26607616 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10882657, VkDeviceMemory_8976432, 8544256 /* rdoc:value 8544256 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10832257, VkDeviceMemory_9331068, 59981824 /* rdoc:value 59981824 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_19025, VkDeviceMemory_18858, 55902208 /* rdoc:value 55902208 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_1017, VkDeviceMemory_963, 622592 /* rdoc:value 622592 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_1026, VkDeviceMemory_963, 671744 /* rdoc:value 671744 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_1441, VkDeviceMemory_963, 58785792 /* rdoc:value 58785792 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_10831998, VkDeviceMemory_10831813, 35454976 /* rdoc:value 35454976 */);
    assert(result == VK_SUCCESS);

    result = vkBindImageMemory(m_device, VkImage_18649, VkDeviceMemory_13619, 31784960 /* rdoc:value 31784960 */);
    assert(result == VK_SUCCESS);
}

void InjectionContainer::CreateImageViews()
{
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9013537,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9013541);
        assert(result == VK_SUCCESS);
    }

    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9434269,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_SNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9434270);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9013954,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_SNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9013956);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10929,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 2u,
                /* levelCount = */ 8u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10931);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9331134,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9331135);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9331137,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9331138);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9331096,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_SRGB_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9331097);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9331099,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9331100);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_9331090,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R16_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_9331091);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_1453,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_B8G8R8A8_SRGB,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_1454);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_34748,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 11u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_34751);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_21182,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC3_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_21184);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_21186,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC5_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_21188);
        assert(result == VK_SUCCESS);
    }

    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_21190,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_21192);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_21194,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_BC4_UNORM_BLOCK,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_21195);
        assert(result == VK_SUCCESS);
    }

    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_18801,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_18802);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_21197,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R32_UINT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 11u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_21199);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_972,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_973);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_987,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_3D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_988);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_984,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_3D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_985);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10882643,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10882645);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10894040,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10894042);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10882657,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10882658);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10832257,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10832259);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_19025,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R16_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_19027);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_1017,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_1018);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_1026,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D_ARRAY,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 4u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_1027);
        assert(result == VK_SUCCESS);
    }

    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_1441,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_B8G8R8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_1442);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_10831998,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R8G8B8A8_UNORM,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 1u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_10832000);
        assert(result == VK_SUCCESS);
    }
    {
        VkImageViewCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* image = */ VkImage_18649,
            /* viewType = */ VK_IMAGE_VIEW_TYPE_2D,
            /* format = */ VK_FORMAT_R32_SFLOAT,
            { /* components = */
                /* r = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* g = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* b = */ VK_COMPONENT_SWIZZLE_IDENTITY,
                /* a = */ VK_COMPONENT_SWIZZLE_IDENTITY,
            },
            { /* subresourceRange = */
                /* aspectMask = */ VK_IMAGE_ASPECT_COLOR_BIT,
                /* baseMipLevel = */ 0u,
                /* levelCount = */ 9u,
                /* baseArrayLayer = */ 0u,
                /* layerCount = */ 1u,
            },
        };
        VkResult result = vkCreateImageView(m_device, &CreateInfo, NULL, &VkImageView_18651);
        assert(result == VK_SUCCESS);
    }
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

void LoadSourceBufferHelper(const char* binaryFileName, uint32_t expectedBufferSize, VkDevice device,
                          VkBuffer& sourceBuffer, VkDeviceMemory& sourceMemory)
{
    std::vector<uint8_t> bufferBinaryData;
    ReadBuffer(binaryFileName, bufferBinaryData);

    assert(bufferBinaryData.size() == expectedBufferSize);

    VkBufferCreateInfo buffer_src_ci = {
        VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        NULL,
        0,
        expectedBufferSize,
        VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        VK_SHARING_MODE_EXCLUSIVE,
        0,
        NULL };
    VkResult result = vkCreateBuffer(device, &buffer_src_ci, NULL, &sourceBuffer);
    assert(result == VK_SUCCESS);

    // TODO: we could assert against data from vkGetBufferMemoryRequirements?

    VkMemoryAllocateInfo memory_ai = {
        /* sType = */ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
        /* pNext = */ NULL,
        /* allocationSize = */ expectedBufferSize,
        /* memoryTypeIndex = */ 1u, // HOST_VISIBLE!
    };
    result = vkAllocateMemory(device, &memory_ai, NULL, &sourceMemory);
    assert(result == VK_SUCCESS);

    result = vkBindBufferMemory(device, sourceBuffer, sourceMemory, 0);
    assert(result == VK_SUCCESS);

    uint8_t *data = NULL;
    result = vkMapMemory(device, sourceMemory, 0, expectedBufferSize, 0, (void **)&data);
    assert(result == VK_SUCCESS);

    memcpy(data, bufferBinaryData.data(), expectedBufferSize);

    VkMappedMemoryRange memory_range = { VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, NULL, sourceMemory, 0, expectedBufferSize };

    result = vkFlushMappedMemoryRanges(device, 1, &memory_range);
    assert(result == VK_SUCCESS);

    vkUnmapMemory(device, sourceMemory);

    bufferBinaryData.clear();
}

void InjectionContainer::CreateResetBuffersAndImages()
{
    // Buffer 141 - VkBuffer_1136

    // Buffer 142 - VkBufferView_1360 - VkBuffer_1358
    // Image 316 - VkImageView_18651 - VkImage_18649
    
    // Buffer 173 - VkBufferView_4258 - VkBuffer_4256
    // Buffer 559 - VkBuffer_8981352
    // Buffer 2587 - VkBuffer_10838418
    // Buffer 148 - VkBuffer_1373
    // Buffer 177 - VkBuffer_4271
    // Buffer 180 - VkBuffer_4275

    // constant buffer
    VkBuffer_buffer_1136_source.expectedSize = 18874368u;
    LoadSourceBufferHelper("buffer141_to_buffer1136.bin", VkBuffer_buffer_1136_source.expectedSize,
                          m_device, VkBuffer_buffer_1136_source.buffer, VkBuffer_buffer_1136_source.deviceMem);

    // source buffer and image
    VkBuffer_buffer_1358_source.expectedSize = 266338304u;
    LoadSourceBufferHelper("buffer142_to_buffer1358.bin", VkBuffer_buffer_1358_source.expectedSize,
        m_device, VkBuffer_buffer_1358_source.buffer, VkBuffer_buffer_1358_source.deviceMem);

    VkBuffer_image_18649_source.expectedSize = 524288u;
    LoadSourceBufferHelper("image316_to_image18649.bin", VkBuffer_image_18649_source.expectedSize,
        m_device, VkBuffer_image_18649_source.buffer, VkBuffer_image_18649_source.deviceMem);

    // RW buffers, pre-dispatch state
    VkBuffer_buffer_4256_reset_source.expectedSize = 12779520u;
    LoadSourceBufferHelper("buffer173_pre_to_buffer4256.bin", VkBuffer_buffer_4256_reset_source.expectedSize,
        m_device, VkBuffer_buffer_4256_reset_source.buffer, VkBuffer_buffer_4256_reset_source.deviceMem);

    VkBuffer_buffer_8981352_reset_source.expectedSize = 15000u;
    LoadSourceBufferHelper("buffer559_pre_to_buffer8981352.bin", VkBuffer_buffer_8981352_reset_source.expectedSize,
        m_device, VkBuffer_buffer_8981352_reset_source.buffer, VkBuffer_buffer_8981352_reset_source.deviceMem);

    VkBuffer_buffer_10838418_reset_source.expectedSize = 638976u;
    LoadSourceBufferHelper("buffer2587_pre_to_buffer_10838418.bin", VkBuffer_buffer_10838418_reset_source.expectedSize,
        m_device, VkBuffer_buffer_10838418_reset_source.buffer, VkBuffer_buffer_10838418_reset_source.deviceMem);

    VkBuffer_buffer_1373_reset_source.expectedSize = 16777208u;
    LoadSourceBufferHelper("buffer148_pre_to_buffer1373.bin", VkBuffer_buffer_1373_reset_source.expectedSize,
        m_device, VkBuffer_buffer_1373_reset_source.buffer, VkBuffer_buffer_1373_reset_source.deviceMem);

    VkBuffer_buffer_4271_reset_source.expectedSize = 16u;
    LoadSourceBufferHelper("buffer177_pre_to_buffer4271.bin", VkBuffer_buffer_4271_reset_source.expectedSize,
        m_device, VkBuffer_buffer_4271_reset_source.buffer, VkBuffer_buffer_4271_reset_source.deviceMem);

    VkBuffer_buffer_4275_reset_source.expectedSize = 1440000u;
    LoadSourceBufferHelper("buffer180_pre_to_buffer4275.bin", VkBuffer_buffer_4275_reset_source.expectedSize,
        m_device, VkBuffer_buffer_4275_reset_source.buffer, VkBuffer_buffer_4275_reset_source.deviceMem);
}

void InjectionContainer::InitializeStaticResources(VkCommandBuffer commandBuffer)
{
    /*
    uniform buffers
    3 0: Xhlslcc_set_3_bind_0X_InstanceParams_cbuffer Buffer 141 12679536 - 12679856 1 Variables, 320 bytes
    4 1 : Xhlslcc_set_4_bind_1X_ClusteredInstanceCullingParams_cbuffer Buffer 141 12765088 - 12765104 1 Variables, 16 bytes
    4 2 : Xhlslcc_set_4_bind_2X_HZBConsts_cbuffer Buffer 141 12677600 - 12677888 1 Variables, 288 bytes
    4 3 : Xhlslcc_set_4_bind_3X_MiscCullingConsts_cbuffer Buffer 141 12676976 - 12677600 1 Variables, 624 bytes

    input buffers
    3 3: Xhlslcc_set_3_bind_3X_InstanceParams_instancing_instanceData TexBuffer Buffer 142 R32G32B32A32_FLOAT bytes 0 - 266338304
    4 24: Xhlslcc_set_4_bind_24X_ClusteredInstanceCullingParams_HZBTexture Texture 2D Image 2D Color Attachment 316 512x256 R32_FLOAT
    */


    // constant buffers
    // Buffer 141 - VkBuffer_1136

    // we can just map and update the buffer for now, though in the future, we could try to make it transfer_src
    std::vector<uint8_t> bufferBinaryData;
    ReadBuffer("buffer141_to_buffer1136.bin", bufferBinaryData);

    uint8_t *data = NULL;
    VkResult result = vkMapMemory(m_device, VkDeviceMemory_185, 4096, 18874368u, 0, (void **)&data);
    assert(result == VK_SUCCESS);

    memcpy(data, bufferBinaryData.data(), 18874368u);

    VkMappedMemoryRange memory_range = { VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, NULL, VkDeviceMemory_185, 4096, 18874368u };

    result = vkFlushMappedMemoryRanges(m_device, 1, &memory_range);
    assert(result == VK_SUCCESS);

    vkUnmapMemory(m_device, VkDeviceMemory_185);

    bufferBinaryData.clear();

    // source buffer
    // Buffer 142 - VkBufferView_1360 - VkBuffer_1358

    // copy into 1358!
    VkBufferCopy region = { 0, 0, VkBuffer_buffer_1358_source.expectedSize };
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_1358_source.buffer, VkBuffer_1358, 1, &region);

    VkMemoryBarrier* pMemoryBarriers = NULL;
    VkBufferMemoryBarrier pBufferMemoryBarriers[1] = {
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_SHADER_READ_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_1358,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_1358_source.expectedSize,
        }
    };
    VkImageMemoryBarrier* pImageMemoryBarriers = NULL;

    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, pMemoryBarriers, 1, pBufferMemoryBarriers, 0, pImageMemoryBarriers);
    
    // source image
    // Image 316 - VkImageView_18651 - VkImage_18649

    // this is the hard one!
    // layout transition to transfer_WRITE
    uint32_t all_access =
        VK_ACCESS_INDIRECT_COMMAND_READ_BIT | VK_ACCESS_INDEX_READ_BIT |
        VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT | VK_ACCESS_UNIFORM_READ_BIT |
        VK_ACCESS_INPUT_ATTACHMENT_READ_BIT | VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT |
        VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT |
        VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT |
        VK_ACCESS_TRANSFER_READ_BIT | VK_ACCESS_TRANSFER_WRITE_BIT | VK_ACCESS_HOST_READ_BIT |
        VK_ACCESS_HOST_WRITE_BIT;

    VkImageSubresourceRange subresourceRange = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 9u, 0, 1 };

    VkImageMemoryBarrier imgBarrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        NULL,
        all_access,
        VK_ACCESS_TRANSFER_WRITE_BIT,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
        VK_QUEUE_FAMILY_IGNORED,
        VK_QUEUE_FAMILY_IGNORED,
        VkImage_18649,
        subresourceRange };
    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
        VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, NULL, 0, NULL, 1, &imgBarrier);

    VkExtent3D dim =
    { /* extent = */
        /* width = */ 512u,
        /* height = */ 256u,
        /* depth = */ 1u,
    };

    VkBufferImageCopy imgRegion = {
        0, 
        dim.width, dim.height,
        { VK_IMAGE_ASPECT_COLOR_BIT, 0, 0, 1 },
        { 0, 0, 0 },  dim
    };
    vkCmdCopyBufferToImage(commandBuffer, VkBuffer_image_18649_source.buffer, VkImage_18649, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &imgRegion);

    imgBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    imgBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
    imgBarrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    imgBarrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
        VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, 0, 0, NULL, 0, NULL, 1, &imgBarrier);

    // VALIDATION SURVIVES
 
}

//void InjectionContainer::InitialTransitionBuffers(VkCommandBuffer commandBuffer)
//{
//
//    // do we need an initial barrier before doing the initial transfer?
//}


void InjectionContainer::ResetBuffers(VkCommandBuffer commandBuffer)
{
    /*
    RW buffers
    4 69: Xhlslcc_set_4_bind_69X_ClusteredInstanceCullingParams_BatchRenderIndirect RW TexBuffer Buffer 173 R32_UINT bytes 0 - 12779520
    4 79: Xhlslcc_set_4_bind_79X_ClusteredInstanceCullingParams_Batches RW Buffer Buffer 559 15000 bytes Viewing bytes 0 - 15000
    4 80: Xhlslcc_set_4_bind_80X_ClusteredInstanceCullingParams_Instances RW Buffer Buffer 2587 638976 bytes Viewing bytes 0 - 638976
    4 81: Xhlslcc_set_4_bind_81X_ClusteredInstanceCullingParams_GPUPrimitives RW Buffer Buffer 148 16777208 bytes Viewing bytes 0 - 16777208
    4 86: Xhlslcc_set_4_bind_86X_ClusteredInstanceCullingParams_ChunkCounter RW Buffer Buffer 177 16 bytes Viewing bytes 0 - 16
    4 87: Xhlslcc_set_4_bind_87X_ClusteredInstanceCullingParams_ChunkCullBuffer RW Buffer Buffer 180 1440000 bytes Viewing bytes 0 - 1440000
    */

    // Buffer 173 - VkBufferView_4258 - VkBuffer_4256
    // Buffer 559 - VkBuffer_8981352
    // Buffer 2587 - VkBuffer_10838418
    // Buffer 148 - VkBuffer_1373
    // Buffer 177 - VkBuffer_4271
    // Buffer 180 - VkBuffer_4275

    VkMemoryBarrier* pMemoryBarriers = NULL;
    VkBufferMemoryBarrier pBufferMemoryBarriers[6] = {
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_4256,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_4256_reset_source.expectedSize,
        },
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_8981352,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_8981352_reset_source.expectedSize,
        },
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_10838418,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_10838418_reset_source.expectedSize,
        },
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_1373,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_1373_reset_source.expectedSize,
        },
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_4271,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_4271_reset_source.expectedSize,
        },
        { /* pBufferMemoryBarriers = */
            /* sType = */ VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            /* pNext = */ NULL,
            /* srcAccessMask = */ VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT,
            /* dstAccessMask = */ VK_ACCESS_TRANSFER_WRITE_BIT,
            /* srcQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* dstQueueFamilyIndex = */ VK_QUEUE_FAMILY_IGNORED,
            /* buffer = */ VkBuffer_4275,
            /* offset = */ 0u,
            /* size = */ VkBuffer_buffer_4275_reset_source.expectedSize,
        },
    };
    VkImageMemoryBarrier* pImageMemoryBarriers = NULL;
    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, pMemoryBarriers, 6, pBufferMemoryBarriers, 0, pImageMemoryBarriers);

    // reset images now!
    VkBufferCopy region = { 0, 0, VkBuffer_buffer_4256_reset_source.expectedSize };
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_4256_reset_source.buffer, VkBuffer_4256, 1, &region);

    region.size = VkBuffer_buffer_8981352_reset_source.expectedSize;
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_8981352_reset_source.buffer, VkBuffer_8981352, 1, &region);

    region.size = VkBuffer_buffer_10838418_reset_source.expectedSize;
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_10838418_reset_source.buffer, VkBuffer_10838418, 1, &region);

    region.size = VkBuffer_buffer_1373_reset_source.expectedSize;
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_1373_reset_source.buffer, VkBuffer_1373, 1, &region);

    region.size = VkBuffer_buffer_4271_reset_source.expectedSize;
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_4271_reset_source.buffer, VkBuffer_4271, 1, &region);

    region.size = VkBuffer_buffer_4275_reset_source.expectedSize;
    vkCmdCopyBuffer(commandBuffer, VkBuffer_buffer_4275_reset_source.buffer, VkBuffer_4275, 1, &region);


    // now barrier for shader access
    for (uint32_t idx = 0; idx < 6; idx++)
    {
        pBufferMemoryBarriers[idx].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        pBufferMemoryBarriers[idx].dstAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;
    }
    vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, pMemoryBarriers, 6, pBufferMemoryBarriers, 0, pImageMemoryBarriers);


}

void InjectionContainer::CreateShader()
{
    std::vector<uint8_t> shader_265;
    ReadBuffer("shader_265", shader_265);

    {
        VkShaderModuleCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ 0,
            /* codeSize = */ 18416u,
            /* pCode = */ (const uint32_t*)shader_265.data(),
        };
        //VkResult result = shim_vkCreateShaderModule(VkDevice_5, &CreateInfo, NULL, &VkShaderModule_9511);
        VkResult result = vkCreateShaderModule(m_device, &CreateInfo, NULL, &VkShaderModule_9511);
        assert(result == VK_SUCCESS);
        shader_265.clear();
    }

    //shim_vkCmdBindPipeline(VkCommandBuffer_360, VK_PIPELINE_BIND_POINT_COMPUTE, VkPipeline_10836480);
    {
        VkComputePipelineCreateInfo CreateInfo = {
            /* sType = */ VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
            /* pNext = */ NULL,
            /* flags = */ VkPipelineCreateFlagBits(0),
            { /* stage = */
                /* sType = */ VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
                /* pNext = */ NULL,
                /* flags = */ 0,
                /* stage = */ VK_SHADER_STAGE_COMPUTE_BIT,
                /* module = */ VkShaderModule_9511,
                /* pName = */ "CS_Main",
                /* pSpecializationInfo = */ NULL,
            },
            /* layout = */ VkPipelineLayout_1231,
            /* basePipelineHandle = */ NULL,
            /* basePipelineIndex = */ 0,
        };
        //VkResult result = shim_vkCreateComputePipelines(VkDevice_5, VkPipelineCache_957, 1, &CreateInfo, NULL, &VkPipeline_10836480);
        VkResult result = vkCreateComputePipelines(m_device, NULL, 1, &CreateInfo, NULL, &VkPipeline_10836480);
        assert(result == VK_SUCCESS);
    }

}


// constant buffers
// All part of VkBuffer_1136
//struct float4
//{
//    float x, y, x, w;
//};
//struct float4x4
//{
//    float4 row0;
//    float4 row1;
//    float4 row2;
//    float4 row3;
//};

//struct int4
//{
//    int32_t x, y, z, w;
//};

//struct InstanceParams
//{
//    float4x4 world;
//    float4x4 worldPrevFrame;
//    float4x4 worldViewProj;
//    float4x4 worldViewProjPrevFrame;

//    float4 dissolveFactor;

//    float LODBlendFactor;
//    float wetnessBias;
//    float alphaTestValue;
//    uint32_t materialTableIndex;

//    uint32_t instanceOffset;
//    uint32_t CameraTAADither;
//    uint32_t _padmania_0;
//    uint32_t _padmania_1;

//    int4 offsets;
//};

//struct ClusteredInstanceCullingParams
//{
//    uint32_t MaxClusterChunks;
//    uint32_t InstanceCount;
//    uint32_t InstanceStartIdx;
//    uint32_t _padmania_0;
//};

//struct HZBConsts
//{
//    float4 ZScaleBias;
//    float4x4    ViewProjectionNoTranslation;
//    float4     ViewTranslation;
//    float4 Viewport;
//    float4 MinMipLevel;
//    float4 CascadeScale[4];
//    float4  CascadeOffset[4];
//    int4 CascadeCount;
//    float4 HalfPixel;
//};

//struct MiscCullingConsts
//{
//    float4 ViewerPosition;
//    float4 ViewerDirection;
//    float4 FrustumPlanes[16];
//    float4 AntiFrustumPlanes[16];

//    uint32_t FrustumPlaneCount;
//    uint32_t AntiFrustumPlaneCount;
//    float MinTriangleArea;
//    uint32_t CullingFlags;

//    uint32_t ForceLOD;
//    float FOVDistanceFactor;
//    float GeometricObjectLODDistanceBias;
//    float GeometricObjectLODDistanceScale;

//    float4 LODCullingViewerPosition;
//    float4 VPosToUV;

//    float ProjectorShadowDimensions[2];
//    float ProjectorShadowFarClip;
//    uint32_t _padmania_0;
//};