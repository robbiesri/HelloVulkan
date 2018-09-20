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

    VkShaderModule VkShaderModule_9511;
    VkPipelineLayout VkPipelineLayout_1231;

    // buffer memory
    VkDeviceMemory VkDeviceMemory_185;
    VkDeviceMemory VkDeviceMemory_963;
    VkDeviceMemory VkDeviceMemory_13619;
    VkDeviceMemory VkDeviceMemory_4228;
    VkDeviceMemory VkDeviceMemory_1359;
    VkDeviceMemory VkDeviceMemory_1376;

    // image memory
    VkDeviceMemory VkDeviceMemory_8977521;
    VkDeviceMemory VkDeviceMemory_9414592;
    VkDeviceMemory VkDeviceMemory_7793;
    VkDeviceMemory VkDeviceMemory_9331068;
    VkDeviceMemory VkDeviceMemory_9291315;
    VkDeviceMemory VkDeviceMemory_21191;
    VkDeviceMemory VkDeviceMemory_21183;
    VkDeviceMemory VkDeviceMemory_21187;
    VkDeviceMemory VkDeviceMemory_8976432;
    VkDeviceMemory VkDeviceMemory_18858;
    VkDeviceMemory VkDeviceMemory_10831813;

    VkBuffer VkBuffer_1136;
    VkBuffer VkBuffer_1091;
    VkBuffer VkBuffer_19003;
    VkBuffer VkBuffer_8981352;
    VkBuffer VkBuffer_10838418;
    VkBuffer VkBuffer_1373;
    VkBuffer VkBuffer_4271;
    VkBuffer VkBuffer_4275;
    VkBuffer VkBuffer_1096;
    VkBuffer VkBuffer_1358;
    VkBuffer VkBuffer_4256;
    VkBuffer VkBuffer_4281;

    VkBufferView VkBufferView_1098;
    VkBufferView VkBufferView_1360;
    VkBufferView VkBufferView_4258;
    VkBufferView VkBufferView_4283;

    VkSampler VkSampler_1174;
    VkSampler VkSampler_18590;
    VkSampler VkSampler_18587;
    VkSampler VkSampler_18586;
    VkSampler VkSampler_1179;
    VkSampler VkSampler_1176;
    VkSampler VkSampler_1177;
    VkSampler VkSampler_1051;
    VkSampler VkSampler_6244;

    VkImage VkImage_9013537;
    VkImage VkImage_9434269;
    VkImage VkImage_9013954;
    VkImage VkImage_10929;
    VkImage VkImage_9331134;
    VkImage VkImage_9331137;
    VkImage VkImage_9331096;
    VkImage VkImage_9331099;
    VkImage VkImage_9331090;
    VkImage VkImage_1453;
    VkImage VkImage_34748;
    VkImage VkImage_21182;
    VkImage VkImage_21186;
    VkImage VkImage_21190;
    VkImage VkImage_21194;
    VkImage VkImage_18801;
    VkImage VkImage_21197;
    VkImage VkImage_972;
    VkImage VkImage_987;
    VkImage VkImage_984;
    VkImage VkImage_10882643;
    VkImage VkImage_10894040;
    VkImage VkImage_10882657;
    VkImage VkImage_10832257;
    VkImage VkImage_19025;
    VkImage VkImage_1017;
    VkImage VkImage_1026;
    VkImage VkImage_1441;
    VkImage VkImage_10831998;
    VkImage VkImage_18649;

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

    VkPipeline VkPipeline_10836480;

    // initial content buffers
    struct SourceBufferInfo
    {
        VkDeviceMemory deviceMem;
        VkBuffer buffer;
        uint32_t expectedSize;
    };

    SourceBufferInfo VkBuffer_buffer_1136_source; // constant buffer

    SourceBufferInfo VkBuffer_buffer_1358_source; // input buffer + image
    SourceBufferInfo VkBuffer_image_18649_source;

    SourceBufferInfo VkBuffer_buffer_4256_reset_source; // RW buffers
    SourceBufferInfo VkBuffer_buffer_10838418_reset_source;
    SourceBufferInfo VkBuffer_buffer_1373_reset_source;
    SourceBufferInfo VkBuffer_buffer_4271_reset_source;
    SourceBufferInfo VkBuffer_buffer_4275_reset_source;

    void CreateDescriptorSetLayouts();
    void CreatePipelineLayouts();
    void CreateDescriptorPools();
    void AllocateDescriptorSets();

    void UpdateDescriptorSets();

    void AllocateMemory();
    void CreateBuffers();
    void BindBufferMemory();
    void CreateBufferViews();
    void CreateImages();
    void BindImageMemory();
    void CreateImageViews();
    void CreateSamplers();

    void CreateResetBuffersAndImages();

    void InitializeConstantBuffers();

    void ResetMemory();

    void CreateShader();


};

