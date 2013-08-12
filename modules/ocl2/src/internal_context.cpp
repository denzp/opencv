#include <opencv2/ocl2/internals/opencl_context.hpp>

using namespace cv::ocl2::internals;

Context::Context(Platform P, const std::vector<Device>& Devices)
: devices_(Devices.begin(), Devices.end())
{
  cl_context_properties context_props[] = {
    CL_CONTEXT_PLATFORM, reinterpret_cast<cl_context_properties>(P.id()),
    0
  };

  cl_int err;
  raw_id_ = clCreateContext(context_props, devices_.size(), &devices_.front(), NULL, NULL, &err);
  OCL(err);
}

Context::Context(const Context& Rhs) {
  raw_id_ = Rhs.raw_id_;
  OCL(clRetainContext(id()));
}

Context::~Context() {
  OCL(clReleaseContext(id()));
}