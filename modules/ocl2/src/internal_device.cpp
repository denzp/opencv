#include <opencv2/ocl2/internals/opencl_device.hpp>

using namespace cv::ocl2::internals;

std::string Device::name() {
  char name_string[40];
  OCL(clGetDeviceInfo(id(), CL_DEVICE_NAME, 40 * sizeof(char), &name_string, NULL));

  return name_string;
}
std::string Device::vendor() {
  char vendor_string[40];
  OCL(clGetDeviceInfo(id(), CL_DEVICE_VENDOR, 40 * sizeof(char), &vendor_string, NULL));

  return vendor_string;
}
unsigned Device::mem_size() {
  cl_uint size_value;
  OCL(clGetDeviceInfo(id(), CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_uint), &size_value, NULL));

  return size_value;
}
bool Device::available() {
  cl_bool state_value;
  OCL(clGetDeviceInfo(id(), CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_bool), &state_value, NULL));

  return state_value;
}