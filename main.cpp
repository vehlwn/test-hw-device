#include <iostream>

extern "C" {
#include <libavutil/hwcontext.h>
}

int main() {
  for (const auto type :
       {AV_HWDEVICE_TYPE_VDPAU, AV_HWDEVICE_TYPE_CUDA, AV_HWDEVICE_TYPE_VAAPI,
        AV_HWDEVICE_TYPE_DXVA2, AV_HWDEVICE_TYPE_QSV,
        AV_HWDEVICE_TYPE_VIDEOTOOLBOX, AV_HWDEVICE_TYPE_D3D11VA,
        AV_HWDEVICE_TYPE_DRM, AV_HWDEVICE_TYPE_OPENCL,
        AV_HWDEVICE_TYPE_MEDIACODEC}) {
    AVBufferRef *hw_device_ctx = nullptr;
    const int err =
        av_hwdevice_ctx_create(&hw_device_ctx, type, nullptr, nullptr, 0);
    std::cout << av_hwdevice_get_type_name(type);
    if (err == 0) {
      std::cout << " device found" << std::endl;
      av_buffer_unref(&hw_device_ctx);
    } else {
      std::cout << " NOT found" << std::endl;
    }
  }
}
