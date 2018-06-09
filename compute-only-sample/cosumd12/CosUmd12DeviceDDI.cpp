#include "CosUmd12.h"

void APIENTRY CosUmd12Device_Ddi_CheckFormatSupport(
    D3D12DDI_HDEVICE Device,
    DXGI_FORMAT Format,
    _Out_ UINT* pFlags)
{
    // TODO: Review format support

    *pFlags = D3D10_DDI_FORMAT_SUPPORT_NOT_SUPPORTED;

    switch( Format )
    {
    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_FLOAT:
    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R32G32B32_SINT:
    case DXGI_FORMAT_Y210:
    case DXGI_FORMAT_Y216:
    case DXGI_FORMAT_AYUV:
    case DXGI_FORMAT_P016:
    case DXGI_FORMAT_NV11:
        return;
    }

    const UINT SupportEverything = D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE |
        D3D10_DDI_FORMAT_SUPPORT_RENDERTARGET |
        D3D10_DDI_FORMAT_SUPPORT_BLENDABLE |
        D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET |
        D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_LOAD;

    const UINT SupportNoMSAA = D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE |
        D3D10_DDI_FORMAT_SUPPORT_RENDERTARGET |
        D3D10_DDI_FORMAT_SUPPORT_BLENDABLE;

    const UINT SupportNoMSAANoRT = D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE |
        D3D10_DDI_FORMAT_SUPPORT_BLENDABLE;

    const UINT SupportMSAALoad = SupportNoMSAANoRT | D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_LOAD;

    const UINT SupportSampleOnly = D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE;

    switch( Format )
    {
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
        break;

    case DXGI_FORMAT_R32G32B32_FLOAT:
        *pFlags = SupportSampleOnly;
        break;

    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R32G32B32_SINT:
        *pFlags = SupportNoMSAA;
        break;

    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
        *pFlags =SupportNoMSAANoRT;
        break;

    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
    case DXGI_FORMAT_BC4_TYPELESS:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_BC5_SNORM:
    case DXGI_FORMAT_BC6H_TYPELESS:
    case DXGI_FORMAT_BC6H_UF16:
    case DXGI_FORMAT_BC6H_SF16:
    case DXGI_FORMAT_BC7_TYPELESS:
    case DXGI_FORMAT_BC7_UNORM:
    case DXGI_FORMAT_BC7_UNORM_SRGB:
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
    case DXGI_FORMAT_Y410:
    case DXGI_FORMAT_Y416:
    case DXGI_FORMAT_420_OPAQUE:
    case DXGI_FORMAT_YUY2:
    case DXGI_FORMAT_AI44:
    case DXGI_FORMAT_IA44:
    case DXGI_FORMAT_P8:
    case DXGI_FORMAT_A8P8:
    case DXGI_FORMAT_NV12:
    case DXGI_FORMAT_R1_UNORM:
        *pFlags = SupportSampleOnly;
        break;

    default:
        *pFlags = SupportEverything;
        break;
    }
}

void APIENTRY CosUmd12Device_Ddi_CheckMultisampleQualityLevels(
    D3D12DDI_HDEVICE Device,
    DXGI_FORMAT Format,
    UINT SampleCount,
    D3D12DDI_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags,
    _Out_ UINT* pNumQualityLevels)
{
    *pNumQualityLevels = 0;
}

void APIENTRY CosUmd12Device_Ddi_GetMipPacking(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HRESOURCE TiledResource,
    _Out_ UINT* pNumPackedMips,
    _Out_ UINT* pNumTilesForPackedMips)
{
    STOP_IN_FUNCTION();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateElementLayoutSize_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATEELEMENTLAYOUT_0010* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

void APIENTRY CosUmd12Device_Ddi_CreateElementLayout_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATEELEMENTLAYOUT_0010* pDesc,
    D3D12DDI_HELEMENTLAYOUT ElementLayout)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_DestroyElementLayout(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HELEMENTLAYOUT ElementLayout)
{
    STOP_IN_FUNCTION();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateBlendStateSize_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_BLEND_DESC_0010* pDesc)
{
    return CosUmd12BlendState::CalculateSize(pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateBlendState_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_BLEND_DESC_0010* pDesc,
    D3D12DDI_HBLENDSTATE BlendState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12BlendState * pBlendState = new (BlendState.pDrvPrivate) CosUmd12BlendState(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_DestroyBlendState(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HBLENDSTATE BlendState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12BlendState * pBlendState = CosUmd12BlendState::CastFrom(BlendState);

    pBlendState->~CosUmd12BlendState();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateDepthStencilStateSize_0025(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_DEPTH_STENCIL_DESC_0025* pDesc)
{
    return CosUmd12DepthStencilState::CalculateSize(pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateDepthStencilState_0025(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_DEPTH_STENCIL_DESC_0025* pDesc,
    D3D12DDI_HDEPTHSTENCILSTATE DepthStencilState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12DepthStencilState * pShader = new (DepthStencilState.pDrvPrivate) CosUmd12DepthStencilState(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_DestroyDepthStencilState(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HDEPTHSTENCILSTATE DepthStencilState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12DepthStencilState * pDepthStencilState = CosUmd12DepthStencilState::CastFrom(DepthStencilState);

    pDepthStencilState->~CosUmd12DepthStencilState();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateRasterizerStateSize_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_RASTERIZER_DESC_0010* pDesc)
{
    return CosUmd12RasterizerState::CalculateSize(pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateRasterizerState_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_RASTERIZER_DESC_0010* pDesc,
    D3D12DDI_HRASTERIZERSTATE RasterizerState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12RasterizerState * pRasterizerState = new (RasterizerState.pDrvPrivate) CosUmd12RasterizerState(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_DestroyRasterizerState(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HRASTERIZERSTATE RasterizerState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12RasterizerState * pRasterizerState = CosUmd12RasterizerState::CastFrom(RasterizerState);

    pRasterizerState->~CosUmd12RasterizerState();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateShaderSize_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc)
{
    return CosUmd12Shader::CalculateSize(pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateVertexShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Shader * pShader = new (Shader.pDrvPrivate) CosUmd12Shader(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreatePixelShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Shader * pShader = new (Shader.pDrvPrivate) CosUmd12Shader(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateGeometryShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Shader * pShader = new (Shader.pDrvPrivate) CosUmd12Shader(pDevice, pDesc);
}

void APIENTRY CosUmd12Device_Ddi_CreateComputeShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Shader * pShader = new (Shader.pDrvPrivate) CosUmd12Shader(pDevice, pDesc);
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateGeometryShaderWithStreamOutput_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

void APIENTRY CosUmd12Device_Ddi_CreateGeometryShaderWithStreamOutput_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    STOP_IN_FUNCTION();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateTessellationShaderSize_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

void APIENTRY CosUmd12Device_Ddi_CreateHullShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateDomainShader_0026(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_0026* pDesc,
    D3D12DDI_HSHADER Shader)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_DestroyShader(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HSHADER Shader)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Shader * pShader = CosUmd12Shader::CastFrom(Shader);

    pShader->~CosUmd12Shader();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateCommandQueueSize_0023(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATECOMMANDQUEUE_0023* pDesc)
{
    return CosUmd12CommandQueue::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateCommandQueue_0023(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATECOMMANDQUEUE_0023* pDesc,
    D3D12DDI_HCOMMANDQUEUE DrvCommandQueue,
    D3D12DDI_HRTCOMMANDQUEUE RTCommandQueue)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12CommandQueue * pCommandQueue = new (DrvCommandQueue.pDrvPrivate) CosUmd12CommandQueue(pDevice, RTCommandQueue, pDesc);

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_DestroyCommandQueue(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HCOMMANDQUEUE CommandQueue)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12CommandQueue * pCommandQueue = CosUmd12CommandQueue::CastFrom(CommandQueue);

    pCommandQueue->~CosUmd12CommandQueue();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateCommandAllocatorSize(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATECOMMANDALLOCATOR* pDesc)
{
    return CosUmd12CommandAllocator::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateCommandAllocator(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATECOMMANDALLOCATOR* pDesc)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12CommandAllocator * pCommandQueue = new (pDesc->hDrvCommandAllocator.pDrvPrivate) CosUmd12CommandAllocator(pDevice, pDesc);

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_DestroyCommandAllocator(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HCOMMANDALLOCATOR CommandAllocator)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12CommandAllocator * pCommandAllocator = CosUmd12CommandAllocator::CastFrom(CommandAllocator);

    pCommandAllocator->~CosUmd12CommandAllocator();
}

void APIENTRY CosUmd12Device_Ddi_ResetCommandAllocator(
    D3D12DDI_HCOMMANDALLOCATOR CommandAllocator)
{
    CosUmd12CommandAllocator * pCommandAllocator = CosUmd12CommandAllocator::CastFrom(CommandAllocator);
    pCommandAllocator->Reset();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivatePipelineStateSize_0033(
    D3D12DDI_HDEVICE Device, 
    _In_ const D3D12DDIARG_CREATE_PIPELINE_STATE_0033* pDesc)
{
    return CosUmd12PipelineState::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreatePipelineState_0033(
    D3D12DDI_HDEVICE Device, 
    _In_ const D3D12DDIARG_CREATE_PIPELINE_STATE_0033* pDesc, 
    D3D12DDI_HPIPELINESTATE PipelineState,
    D3D12DDI_HRTPIPELINESTATE RTPipelineState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12PipelineState * pPipelineState = new (PipelineState.pDrvPrivate) CosUmd12PipelineState(pDevice, RTPipelineState, pDesc);

    return S_OK;
}

VOID APIENTRY CosUmd12Device_Ddi_DestroyPipelineState(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HPIPELINESTATE PipelineState)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12PipelineState * pPipelineState = CosUmd12PipelineState::CastFrom(PipelineState);

    pPipelineState->~CosUmd12PipelineState();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateCommandListSize_0001(
    D3D12DDI_HDEVICE Device, 
    _In_ const D3D12DDIARG_CREATE_COMMAND_LIST_0001* pDesc)
{
    return CosUmd12CommandList::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateCommandList_0001(
    D3D12DDI_HDEVICE Device, 
    _In_ const D3D12DDIARG_CREATE_COMMAND_LIST_0001* pDesc)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);

    CosUmd12CommandList * pCommandList = new (pDesc->hDrvCommandList.pDrvPrivate) CosUmd12CommandList(pDevice, pDesc);

    HRESULT hr = pCommandList->StandUp();

    if (hr != S_OK) pCommandList->~CosUmd12CommandList();

    return hr;
}

void APIENTRY CosUmd12Device_Ddi_DestroyCommandList(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HCOMMANDLIST CommandList)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12CommandList * pCommandList = CosUmd12CommandList::CastFrom(CommandList);

    pCommandList->~CosUmd12CommandList();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateFenceSize(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_FENCE* pDesc)
{
    return CosUmd12Fence::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateFence(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HFENCE Fence,
    _In_ const D3D12DDIARG_CREATE_FENCE* pDesc)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Fence * pFence = new (Fence.pDrvPrivate) CosUmd12Fence(pDevice, pDesc);

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_DestroyFence(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HFENCE Fence)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Fence * pFence = CosUmd12Fence::CastFrom(Fence);

    pFence->~CosUmd12Fence();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateDescriptorHeapSize_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_DESCRIPTOR_HEAP_0001* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateDescriptorHeap_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_DESCRIPTOR_HEAP_0001* pDesc,
    D3D12DDI_HDESCRIPTORHEAP DescriptorHeap)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

void APIENTRY CosUmd12Device_Ddi_DestroyDescriptorHeap(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HDESCRIPTORHEAP DescriptorHeap)
{
    STOP_IN_FUNCTION();
}

UINT APIENTRY CosUmd12Device_Ddi_GetDescriptorSizeInBytes(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_DESCRIPTOR_HEAP_TYPE HeapType)
{
    UINT size = 0;

    switch (HeapType) {
    case D3D12DDI_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV:
    case D3D12DDI_DESCRIPTOR_HEAP_TYPE_SAMPLER:
    case D3D12DDI_DESCRIPTOR_HEAP_TYPE_RTV:
    case D3D12DDI_DESCRIPTOR_HEAP_TYPE_DSV:
        return sizeof(CosUmd12Descriptor);

    default:
        ASSERT(0);
    }

    return size;
}

D3D12DDI_CPU_DESCRIPTOR_HANDLE APIENTRY CosUmd12Device_Ddi_GetCpuDescriptorHandleForHeapStart(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HDESCRIPTORHEAP DescriptorHeap)
{
    STOP_IN_FUNCTION();

    return { 0 };
}

D3D12DDI_GPU_DESCRIPTOR_HANDLE APIENTRY CosUmd12Device_Ddi_GetGpuDescriptorHandleForHeapStart(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HDESCRIPTORHEAP DescriptorHeap)
{
    STOP_IN_FUNCTION();

    return { 0 };
}

void APIENTRY CosUmd12Device_Ddi_CreateShaderResourceView_0002(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SHADER_RESOURCE_VIEW_0002* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateConstantBufferView(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDI_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateSampler(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_SAMPLER* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateUnorderedAccessView_0002(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_UNORDERED_ACCESS_VIEW_0002* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateRenderTargetView_0002(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_RENDER_TARGET_VIEW_0002* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CreateDepthStencilView(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_DEPTH_STENCIL_VIEW* pDesc,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    STOP_IN_FUNCTION();
}


SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateRootSignatureSize_0013(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_ROOT_SIGNATURE_0013* pDesc)
{
    return CosUmd12RootSignature::CalculateSize(pDesc);
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateRootSignature_0013(
    D3D12DDI_HDEVICE hDevice,
    _In_ const D3D12DDIARG_CREATE_ROOT_SIGNATURE_0013* pDesc,
    D3D12DDI_HROOTSIGNATURE hRootSignature)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(hDevice);
    CosUmd12RootSignature * pCosUmdRootSignature = new (hRootSignature.pDrvPrivate) CosUmd12RootSignature(pDevice, pDesc);

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_DestroyRootSignature(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HROOTSIGNATURE RootSignature)
{
    // do nothing
}

HRESULT APIENTRY CosUmd12Device_Ddi_MapHeap(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HHEAP Heap,
    _Out_ void** pHeapData)
{
    STOP_IN_FUNCTION();

    CosUmd12Heap * pHeap = (CosUmd12Heap *)Heap.pDrvPrivate;

    return pHeap->Map(pHeapData);
}

void APIENTRY CosUmd12Device_Ddi_UnmapHeap(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HHEAP Heap)
{
    STOP_IN_FUNCTION();
}

D3D12DDI_HEAP_AND_RESOURCE_SIZES APIENTRY CosUmd12Device_Ddi_CalcPrivateHeapAndResourceSizes_0030(
    D3D12DDI_HDEVICE Device,
    _In_opt_ const D3D12DDIARG_CREATEHEAP_0001* pHeapDesc,
    _In_opt_ const D3D12DDIARG_CREATERESOURCE_0003* pResourceDesc,
    D3D12DDI_HPROTECTEDRESOURCESESSION_0030 hProtectedResourceSession)
{
    D3D12DDI_HEAP_AND_RESOURCE_SIZES sizes;

    sizes.Heap = CosUmd12Heap::CalculateSize();
    sizes.Resource = CosUmd12Resource::CalculateSize();

    return sizes;
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateHeapAndResource_0030(
    D3D12DDI_HDEVICE Device,
    _In_opt_ const D3D12DDIARG_CREATEHEAP_0001* pHeapDesc,
    D3D12DDI_HHEAP Heap,
    D3D12DDI_HRTRESOURCE RtHeap,
    _In_opt_ const D3D12DDIARG_CREATERESOURCE_0003* pResourceDesc,
    _In_opt_ const D3D12DDI_CLEAR_VALUES* pClearValues,
    D3D12DDI_HPROTECTEDRESOURCESESSION_0030 hProtectedResourceSession, //TODO: DRM!
    D3D12DDI_HRESOURCE Resource)
{
    // TODO: Talk to whoever designed this and find out how it works
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);

    CosUmd12Heap * pHeap = NULL;

    if (pHeapDesc != NULL) {
        STOP_IN_FUNCTION();
        pHeap = new (Heap.pDrvPrivate) CosUmd12Heap(pDevice, RtHeap, pHeapDesc);

        pHeap->Standup();
    }

    if (pResourceDesc != NULL) {
        STOP_IN_FUNCTION();
        CosUmd12Resource * pResource = new (Resource.pDrvPrivate) CosUmd12Resource(pDevice, pResourceDesc);

        pResource->Standup(pHeap);
    }

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_DestroyHeapAndResource(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HHEAP Heap,
    D3D12DDI_HRESOURCE Resource)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Heap * pHeap = CosUmd12Heap::CastFrom(Heap);
    CosUmd12Resource * pResource = CosUmd12Resource::CastFrom(Resource);

    if (pHeap != NULL) pHeap->~CosUmd12Heap();
    if (pResource != NULL) pResource->~CosUmd12Resource();
}

HRESULT APIENTRY CosUmd12Device_Ddi_MakeResident_0001(
    D3D12DDI_HDEVICE Device,
    D3D12DDIARG_MAKERESIDENT_0001* pDesc)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);

    ASSERT(pDesc->NumAdapters == 1);

    UINT numAllocations = pDesc->NumObjects;

    D3DKMT_HANDLE* pAllocations = (D3DKMT_HANDLE*)malloc(sizeof(D3DKMT_HANDLE) * numAllocations);
    if (pAllocations == NULL) return E_OUTOFMEMORY;

    D3DDDI_MAKERESIDENT makeResident = {};

    makeResident.hPagingQueue = 0;
    makeResident.Flags = pDesc->Flags;
    makeResident.AllocationList = pAllocations;
    makeResident.PriorityList = nullptr;

    HRESULT hr = S_OK;

    UINT makeResidentCount = 0;

    for (UINT i = 0; i < numAllocations; ++i)
    {
        switch (pDesc->pObjects[i].Type)
        {
            case D3D12DDI_HT_HEAP:
            {
                // TODO: Determine if we need to deal with residency
#if 0
                D3D12DDI_HHEAP hHeap;
                hHeap.pDrvPrivate = pDesc->pObjects[i].Handle;

                CosUmd12Heap* pHeap = CosUmd12Heap::CastFrom(hHeap);

                if ((pHeap->m_Allocation.m_Flags & GpuMemoryAlloc_Esram) == 0)
                {
                    DBGASSERT(pHeap->m_Allocation.m_CpuMapCount == 0);
                    pAllocations[makeResidentCount++] = pHeap->m_Allocation.GetHandle();
                }
#endif
                break;
            }
            case D3D12DDI_HT_DESCRIPTOR_HEAP:
            {
                STOP_IN_FUNCTION();
#if 0
                D3D12DDI_HDESCRIPTORHEAP hDescriptorHeap;
                hDescriptorHeap.pDrvPrivate = pDesc->pObjects[i].Handle;
                CDescriptorHeap* pDescriptorHeap = Promote(hDescriptorHeap);
                pAllocations[makeResidentCount++] = pDescriptorHeap->m_DescriptorBuffer.GetHandle();
#endif
                break;
            }
            case D3D12DDI_HT_QUERY_HEAP:
            {
                STOP_IN_FUNCTION();
#if 0
                D3D12DDI_HQUERYHEAP hQueryHeap;
                hQueryHeap.pDrvPrivate = pDesc->pObjects[i].Handle;
                CQueryHeap* pQueryHeap = Promote(hQueryHeap);
                DBGASSERT(pQueryHeap->m_Allocation.m_CpuMapCount == 0);
                pAllocations[makeResidentCount++] = pQueryHeap->m_Allocation.GetHandle();
#endif
                break;
            }

            case D3D12DDI_HT_0012_RESOURCE:
            case D3D12DDI_HT_PIPELINE_STATE:
            case D3D12DDI_HT_COMMAND_ALLOCATOR:
            case D3D12DDI_HT_COMMAND_QUEUE:
            case D3D12DDI_HT_FENCE:
            case D3D12DDI_HT_COMMAND_SIGNATURE:
            default:
                ASSERT(0);
                hr = E_INVALIDARG;
                break;
        }
    }

    if (SUCCEEDED(hr))
    {
        if (makeResidentCount == 0)
        {
            *pDesc->pPagingFenceValue = 0;
            pDesc->WaitMask = 0;
        }
        else
        {
            makeResident.NumAllocations = makeResidentCount;

            hr = pDevice->m_pUMCallbacks->pfnMakeResidentCb(pDevice->m_hRTDevice, *pDesc->pRTPagingQueue, &makeResident);
            if ((hr == E_PENDING) || SUCCEEDED(hr))
            {
                *pDesc->pPagingFenceValue = makeResident.PagingFenceValue;
                pDesc->WaitMask = (hr == E_PENDING) ? 1 : 0;
            }
        }
    }

    return hr;
}

HRESULT APIENTRY CosUmd12Device_Ddi_Evict2(
    D3D12DDI_HDEVICE Device,
    const D3D12DDIARG_EVICT* pDesc)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

D3D12DDI_HEAP_AND_RESOURCE_SIZES APIENTRY CosUmd12Device_Ddi_CalcPrivateOpenedHeapAndResourceSizes_0003(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_OPENHEAP_0003* pDesc)
{
    D3D12DDI_HEAP_AND_RESOURCE_SIZES sizes;

    sizes.Heap = CosUmd12Heap::CalculateSize();
    sizes.Resource = CosUmd12Resource::CalculateSize();

    return sizes;
}

HRESULT APIENTRY CosUmd12Device_Ddi_OpenHeapAndResource_0003(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_OPENHEAP_0003* pDesc,
    D3D12DDI_HHEAP Heap,
    D3D12DDI_HRTRESOURCE RtResource,
    D3D12DDI_HRESOURCE Resource)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Heap * pHeap = new (Heap.pDrvPrivate) CosUmd12Heap(pDevice);
    CosUmd12Resource * pResource = new (Resource.pDrvPrivate) CosUmd12Resource(pDevice, RtResource);

    if (pDesc->NumAllocations == 1) {
        ASSERT(pDesc->pOpenAllocationInfo->PrivateDriverDataSize == sizeof(CosAllocationExchange));
        CosAllocationExchange * pAllocation = (CosAllocationExchange *)pDesc->pOpenAllocationInfo->pPrivateDriverData;
        ASSERT(pAllocation->m_magic == CosAllocationExchange::kMagic);

        pResource->Initialize(pAllocation);

    } else {
        STOP_IN_FUNCTION();
        return E_NOTIMPL;
    }

    return S_OK;
}

void APIENTRY CosUmd12Device_Ddi_CopyDescriptors_0003(
    D3D12DDI_HDEVICE Device,
    _In_ UINT NumDestDescriptorRanges,
    _In_reads_(NumDestDescriptorRanges) const D3D12DDI_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    _In_reads_opt_(NumDestDescriptorRanges) const UINT* pDestDescriptorRangeSizes, // NULL means all ranges 1
    _In_ UINT NumSrcDescriptorRanges,
    _In_reads_(NumSrcDescriptorRanges) const D3D12DDI_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    _In_reads_opt_(NumSrcDescriptorRanges) const UINT* pSrcDescriptorRangeSizes, // NULL means all ranges 1
    _In_ D3D12DDI_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    STOP_IN_FUNCTION();
}

void APIENTRY CosUmd12Device_Ddi_CopyDescriptorsSimple_0003(
    D3D12DDI_HDEVICE,
    _In_ UINT NumDescriptors,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    _In_ D3D12DDI_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    _In_ D3D12DDI_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    STOP_IN_FUNCTION();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateQueryHeapSize_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_QUERY_HEAP_0001* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateQueryHeap_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_QUERY_HEAP_0001* pDesc,
    D3D12DDI_HQUERYHEAP QueryHeap)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

void APIENTRY CosUmd12Device_Ddi_DestroyQueryHeap(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HQUERYHEAP QueryHeap)
{
    STOP_IN_FUNCTION();
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivateCommandSignatureSize_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreateCommandSignature_0001(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001* pDesc,
    D3D12DDI_HCOMMANDSIGNATURE CommandSignature)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

void APIENTRY CosUmd12Device_Ddi_DestroyCommandSignature(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HCOMMANDSIGNATURE CommandSignature)
{
    STOP_IN_FUNCTION();
}


D3D12DDI_GPU_VIRTUAL_ADDRESS APIENTRY CosUmd12Device_Ddi_CheckResourceVirtualAddress(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HRESOURCE Resource)
{
    STOP_IN_FUNCTION();

    CosUmd12Resource * pResource = (CosUmd12Resource *)Resource.pDrvPrivate;

    return pResource->GetUniqueAddress();
}

void APIENTRY CosUmd12Device_Ddi_CheckResourceAllocationInfo_0022(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATERESOURCE_0003* pDesc,
    D3D12DDI_RESOURCE_OPTIMIZATION_FLAGS Flags,
    UINT32 AlignmentRestriction,
    UINT VisibleNodeMask,
    _Out_ D3D12DDI_RESOURCE_ALLOCATION_INFO_0022* pInfo)
{
    if (pDesc->ResourceType == D3D12DDI_RT_BUFFER)
    {
        memset(pInfo, 0, sizeof(D3D12DDI_RESOURCE_ALLOCATION_INFO_0022));

        pInfo->ResourceDataSize = pDesc->Width;
        pInfo->ResourceDataAlignment = AlignmentRestriction;
        pInfo->AdditionalDataHeaderAlignment = 1;
        pInfo->AdditionalDataAlignment = 1;
        pInfo->Layout = (pDesc->Layout != D3D12DDI_TL_UNDEFINED) ? pDesc->Layout : D3D12DDI_TL_ROW_MAJOR;
    } else {
        STOP_IN_FUNCTION();
    }
}

void APIENTRY CosUmd12Device_Ddi_CheckSubresourceInfo(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HRESOURCE Resource,
    UINT Subresource,
    _Out_ D3D12DDI_SUBRESOURCE_INFO* pInfo)
{
    STOP_IN_FUNCTION();

    CosUmd12Resource * pResource = (CosUmd12Resource *)Resource.pDrvPrivate;

    //
    // Assumption : Only BUFFER is supported
    //
    memset(pInfo, 0, sizeof(*pInfo));
}

void APIENTRY CosUmd12Device_Ddi_CheckExistingResourceAllocationInfo_0022(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HRESOURCE Resource,
    _Out_ D3D12DDI_RESOURCE_ALLOCATION_INFO_0022* pInfo)
{
    CosUmd12Device * pDevice = CosUmd12Device::CastFrom(Device);
    CosUmd12Resource * pResource = CosUmd12Resource::CastFrom(Resource);

    memset(pInfo, 0, sizeof(*pInfo));

    pInfo->Layout = pResource->GetTextureLayout();
    pInfo->ResourceDataSize = pResource->GetDataSize();
}

HRESULT APIENTRY CosUmd12Device_Ddi_OfferResources(
    D3D12DDI_HDEVICE Device,
    const D3D12DDIARG_OFFERRESOURCES* pDesc)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

HRESULT APIENTRY CosUmd12Device_Ddi_ReclaimResources_0001(
     D3D12DDI_HDEVICE Device, 
     D3D12DDIARG_RECLAIMRESOURCES_0001* pDesc)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}
UINT APIENTRY CosUmd12Device_Ddi_GetImplicitPhysicalAdapterMask(
    D3D12DDI_HDEVICE Device)
{
    STOP_IN_FUNCTION();

    return 0;
}

UINT APIENTRY CosUmd12Device_Ddi_GetPresentPrivateDriverDataSize(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_PRESENT_0001* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

void APIENTRY CosUmd12Device_Ddi_QueryNodeMap(
    D3D12DDI_HDEVICE Device,
    UINT NumPhysicalAdapters,
    _Out_writes_(NumPhysicalAdapters) UINT* pMap)
{
    for (UINT i = 0; i < NumPhysicalAdapters; ++i)
    {
        pMap[i] = i;
    }
}

HRESULT APIENTRY CosUmd12Device_Ddi_RetrieveShaderComment_0003(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HPIPELINESTATE PipelineState,
    _Out_writes_z_(*pCharacterCountIncludingNullTerminator) WCHAR* pBuffer,
    _Inout_ SIZE_T* pCharacterCountIncludingNullTerminator)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

D3DKMT_HANDLE APIENTRY CosUmd12Device_Ddi_CheckResourceAllocationHandle(
    D3D12DDI_HDEVICE Device,
    D3D10DDI_HRESOURCE Resource)
{
    STOP_IN_FUNCTION();

    return NULL;
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcPrivatePipelineLibrarySize_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_PIPELINE_LIBRARY_0010* pDesc)
{
    STOP_IN_FUNCTION();

    return 0;
}

HRESULT APIENTRY CosUmd12Device_Ddi_CreatePipelineLibrary_0010(
    D3D12DDI_HDEVICE Device,
    _In_ const D3D12DDIARG_CREATE_PIPELINE_LIBRARY_0010* pDesc,
    D3D12DDI_HPIPELINELIBRARY PipelineLibrary)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

void APIENTRY CosUmd12Device_Ddi_DestroyPipelineLibrary_0010(
    D3D12DDI_HDEVICE Device, 
    D3D12DDI_HPIPELINELIBRARY PipelineLibrary)
{
    STOP_IN_FUNCTION();
}

HRESULT APIENTRY CosUmd12Device_Ddi_AddPipelineStateToLibrary_0010(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HPIPELINELIBRARY Library,
    D3D12DDI_HPIPELINESTATE PipelineState,
    UINT PipelineIndex)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

SIZE_T APIENTRY CosUmd12Device_Ddi_CalcSerializedLibrarySize_0010(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HPIPELINELIBRARY hLibrary)
{
    STOP_IN_FUNCTION();

    return 0;
}

HRESULT APIENTRY CosUmd12Device_Ddi_SerializeLibrary_0010(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HPIPELINELIBRARY hLibrary,
    _Out_ void *pBlob)
{
    STOP_IN_FUNCTION();

    return E_NOTIMPL;
}

void APIENTRY CosUmd12Device_Ddi_GetDebugAllocationInfo_0014(
    D3D12DDI_HDEVICE Device,
    D3D12DDI_HANDLE_AND_TYPE Object,
    _Inout_ UINT* pNumVirtualAddressInfos,
    _Out_writes_to_opt_(*pNumVirtualAddressInfos, *pNumVirtualAddressInfos) D3D12DDI_DEBUG_VIRTUAL_ADDRESS_ALLOCATION_INFO_0012* pVirtualAddressInfos,
    _Inout_ UINT* pNumKMTInfos,
    _Out_writes_to_opt_(*pNumKMTInfos, *pNumKMTInfos) D3D12DDI_DEBUG_KMT_ALLOCATION_INFO_0014* pKMTInfos)
{
    STOP_IN_FUNCTION();
}

D3D12DDI_DEVICE_FUNCS_CORE_0033 g_CosUmd12Device_Ddi_0033 =
{
    CosUmd12Device_Ddi_CheckFormatSupport,                             // pfnCheckFormatSupport
    CosUmd12Device_Ddi_CheckMultisampleQualityLevels,                  // pfnCheckMultisampleQualityLevels
    CosUmd12Device_Ddi_GetMipPacking,                                  // pfnGetMipPacking
    CosUmd12Device_Ddi_CalcPrivateElementLayoutSize_0010,              // pfnCalcPrivateElementLayoutSize
    CosUmd12Device_Ddi_CreateElementLayout_0010,                       // pfnCreateElementLayout
    CosUmd12Device_Ddi_DestroyElementLayout,                           // pfnDestroyElementLayout
    CosUmd12Device_Ddi_CalcPrivateBlendStateSize_0010,                 // pfnCalcPrivateBlendStateSize
    CosUmd12Device_Ddi_CreateBlendState_0010,                          // pfnCreateBlendState
    CosUmd12Device_Ddi_DestroyBlendState,                              // pfnDestroyBlendState
    CosUmd12Device_Ddi_CalcPrivateDepthStencilStateSize_0025,          // pfnCalcPrivateDepthStencilStateSize
    CosUmd12Device_Ddi_CreateDepthStencilState_0025,                   // pfnCreateDepthStencilState
    CosUmd12Device_Ddi_DestroyDepthStencilState,                       // pfnDestroyDepthStencilState
    CosUmd12Device_Ddi_CalcPrivateRasterizerStateSize_0010,            // pfnCalcPrivateRasterizerStateSize
    CosUmd12Device_Ddi_CreateRasterizerState_0010,                     // pfnCreateRasterizerState
    CosUmd12Device_Ddi_DestroyRasterizerState,                         // pfnDestroyRasterizerState
    CosUmd12Device_Ddi_CalcPrivateShaderSize_0026,                     // pfnCalcPrivateShaderSize
    CosUmd12Device_Ddi_CreateVertexShader_0026,                        // pfnCreateVertexShader
    CosUmd12Device_Ddi_CreatePixelShader_0026,                         // pfnCreatePixelShader
    CosUmd12Device_Ddi_CreateGeometryShader_0026,                      // pfnCreateGeometryShader
    CosUmd12Device_Ddi_CreateComputeShader_0026,                       // pfnCreateComputeShader
    CosUmd12Device_Ddi_CalcPrivateGeometryShaderWithStreamOutput_0026, // pfnCalcPrivateGeometryShaderWithStreamOutput
    CosUmd12Device_Ddi_CreateGeometryShaderWithStreamOutput_0026,      // pfnCreateGeometryShaderWithStreamOutput
    CosUmd12Device_Ddi_CalcPrivateTessellationShaderSize_0026,         // pfnCalcPrivateTessellationShaderSize
    CosUmd12Device_Ddi_CreateHullShader_0026,                          // pfnCreateHullShader
    CosUmd12Device_Ddi_CreateDomainShader_0026,                        // pfnCreateDomainShader
    CosUmd12Device_Ddi_DestroyShader,                                  // pfnDestroyShader
    CosUmd12Device_Ddi_CalcPrivateCommandQueueSize_0023,               // pfnCalcPrivateCommandQueueSize
    CosUmd12Device_Ddi_CreateCommandQueue_0023,                        // pfnCreateCommandQueue
    CosUmd12Device_Ddi_DestroyCommandQueue,                            // pfnDestroyCommandQueue
    CosUmd12Device_Ddi_CalcPrivateCommandAllocatorSize,                // pfnCalcPrivateCommandAllocatorSize
    CosUmd12Device_Ddi_CreateCommandAllocator,                         // pfnCreateCommandAllocator
    CosUmd12Device_Ddi_DestroyCommandAllocator,                        // pfnDestroyCommandAllocator
    CosUmd12Device_Ddi_ResetCommandAllocator,                          // pfnResetCommandAllocator
    CosUmd12Device_Ddi_CalcPrivatePipelineStateSize_0033,              // pfnCalcPrivatePipelineStateSize
    CosUmd12Device_Ddi_CreatePipelineState_0033,                       // pfnCreatePipelineState
    CosUmd12Device_Ddi_DestroyPipelineState,                           // pfnDestroyPipelineState
    CosUmd12Device_Ddi_CalcPrivateCommandListSize_0001,                // pfnCalcPrivateCommandListSize
    CosUmd12Device_Ddi_CreateCommandList_0001,                         // pfnCreateCommandList
    CosUmd12Device_Ddi_DestroyCommandList,                             // pfnDestroyCommandList
    CosUmd12Device_Ddi_CalcPrivateFenceSize,                           // pfnCalcPrivateFenceSize
    CosUmd12Device_Ddi_CreateFence,                                    // pfnCreateFence
    CosUmd12Device_Ddi_DestroyFence,                                   // pfnDestroyFence
    CosUmd12Device_Ddi_CalcPrivateDescriptorHeapSize_0001,             // pfnCalcPrivateDescriptorHeapSize
    CosUmd12Device_Ddi_CreateDescriptorHeap_0001,                      // pfnCreateDescriptorHeap
    CosUmd12Device_Ddi_DestroyDescriptorHeap,                          // pfnDestroyDescriptorHeap
    CosUmd12Device_Ddi_GetDescriptorSizeInBytes,                       // pfnGetDescriptorSizeInBytes
    CosUmd12Device_Ddi_GetCpuDescriptorHandleForHeapStart,             // pfnGetCPUDescriptorHandleForHeapStart
    CosUmd12Device_Ddi_GetGpuDescriptorHandleForHeapStart,             // pfnGetGPUDescriptorHandleForHeapStart
    CosUmd12Device_Ddi_CreateShaderResourceView_0002,                  // pfnCreateShaderResourceView
    CosUmd12Device_Ddi_CreateConstantBufferView,                       // pfnCreateConstantBufferView
    CosUmd12Device_Ddi_CreateSampler,                                  // pfnCreateSampler
    CosUmd12Device_Ddi_CreateUnorderedAccessView_0002,                 // pfnCreateUnorderedAccessView
    CosUmd12Device_Ddi_CreateRenderTargetView_0002,                    // pfnCreateRenderTargetView
    CosUmd12Device_Ddi_CreateDepthStencilView,                         // pfnCreateDepthStencilView
    CosUmd12Device_Ddi_CalcPrivateRootSignatureSize_0013,              // pfnCalcPrivateRootSignatureSize
    CosUmd12Device_Ddi_CreateRootSignature_0013,                       // pfnCreateRootSignature
    CosUmd12Device_Ddi_DestroyRootSignature,                           // pfnDestroyRootSignature
    CosUmd12Device_Ddi_MapHeap,                                        // pfnMapHeap
    CosUmd12Device_Ddi_UnmapHeap,                                      // pfnUnmapHeap
    CosUmd12Device_Ddi_CalcPrivateHeapAndResourceSizes_0030,           // pfnCalcPrivateHeapAndResourceSizes
    CosUmd12Device_Ddi_CreateHeapAndResource_0030,                     // pfnCreateHeapAndResource
    CosUmd12Device_Ddi_DestroyHeapAndResource,                         // pfnDestroyHeapAndResource
    CosUmd12Device_Ddi_MakeResident_0001,                              // pfnMakeResident
    CosUmd12Device_Ddi_Evict2,                                         // pfnEvict
    CosUmd12Device_Ddi_CalcPrivateOpenedHeapAndResourceSizes_0003,     // pfnCalcPrivateOpenedHeapAndResourceSizes
    CosUmd12Device_Ddi_OpenHeapAndResource_0003,                       // pfnOpenHeapAndResource
    CosUmd12Device_Ddi_CopyDescriptors_0003,                           // pfnCopyDescriptors
    CosUmd12Device_Ddi_CopyDescriptorsSimple_0003,                     // pfnCopyDescriptorsSimple
    CosUmd12Device_Ddi_CalcPrivateQueryHeapSize_0001,                  // pfnCalcPrivateQueryHeapSize
    CosUmd12Device_Ddi_CreateQueryHeap_0001,                           // pfnCreateQueryHeap
    CosUmd12Device_Ddi_DestroyQueryHeap,                               // pfnDestroyQueryHeap
    CosUmd12Device_Ddi_CalcPrivateCommandSignatureSize_0001,           // pfnCalcPrivateCommandSignatureSize
    CosUmd12Device_Ddi_CreateCommandSignature_0001,                    // pfnCreateCommandSignature
    CosUmd12Device_Ddi_DestroyCommandSignature,                        // pfnDestroyCommandSignature
    CosUmd12Device_Ddi_CheckResourceVirtualAddress,                    // pfnCheckResourceVirtualAddress
    CosUmd12Device_Ddi_CheckResourceAllocationInfo_0022,               // pfnCheckResourceAllocationInfo
    CosUmd12Device_Ddi_CheckSubresourceInfo,                           // pfnCheckSubresourceInfo
    CosUmd12Device_Ddi_CheckExistingResourceAllocationInfo_0022,       // pfnCheckExistingResourceAllocationInfo
    CosUmd12Device_Ddi_OfferResources,                                 // pfnOfferResources
    CosUmd12Device_Ddi_ReclaimResources_0001,                          // pfnReclaimResources
    CosUmd12Device_Ddi_GetImplicitPhysicalAdapterMask,                 // pfnGetImplicitPhysicalAdapterMask
    CosUmd12Device_Ddi_GetPresentPrivateDriverDataSize,                // pfnGetPresentPrivateDriverDataSize
    CosUmd12Device_Ddi_QueryNodeMap,                                   // pfnQueryNodeMap
    CosUmd12Device_Ddi_RetrieveShaderComment_0003,                     // pfnRetrieveShaderComment
    CosUmd12Device_Ddi_CheckResourceAllocationHandle,                  // pfnCheckResourceAllocationHandle
    CosUmd12Device_Ddi_CalcPrivatePipelineLibrarySize_0010,            // pfnCalcPrivatePipelineLibrarySize
    CosUmd12Device_Ddi_CreatePipelineLibrary_0010,                     // pfnCreatePipelineLibrary
    CosUmd12Device_Ddi_DestroyPipelineLibrary_0010,                    // pfnDestroyPipelineLibrary
    CosUmd12Device_Ddi_AddPipelineStateToLibrary_0010,                 // pfnAddPipelineStateToLibrary
    CosUmd12Device_Ddi_CalcSerializedLibrarySize_0010,                 // pfnCalcSerializedLibrarySize
    CosUmd12Device_Ddi_SerializeLibrary_0010,                          // pfnSerializeLibrary
    CosUmd12Device_Ddi_GetDebugAllocationInfo_0014                     // pfnGetDebugAllocationInfo
};
