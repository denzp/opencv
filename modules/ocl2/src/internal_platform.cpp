#include <opencv2/ocl2/internals/opencl_platform.hpp>

using namespace cv::ocl2::internals;

std::vector<Platform> Platform::get_all_platforms() {
  cl_uint platforms_count = 0;
  OCL(clGetPlatformIDs(1, NULL, &platforms_count));

  // !TODO -- check for 'platforms_count == 0' and throw exception

  std::vector<cl_platform_id> raw_platforms_vec(platforms_count);
  OCL(clGetPlatformIDs(platforms_count, &raw_platforms_vec.front(), NULL));

  std::vector<Platform> result;
  result.reserve(raw_platforms_vec.size());

  for(unsigned i = 0; i < platforms_count; i++)
    result.push_back(raw_platforms_vec[i]);

  return result;
}

std::string Platform::name() {
  char name_string[40];
  OCL(clGetPlatformInfo(id(), CL_PLATFORM_NAME, 40 * sizeof(char), &name_string, NULL));

  return name_string;
}
std::string Platform::vendor() {
  char vendor_string[40];
  OCL(clGetPlatformInfo(id(), CL_PLATFORM_VENDOR, 40 * sizeof(char), &vendor_string, NULL));

  return vendor_string;
}
cl_version Platform::version() {
  char version_string[40];
  OCL(clGetPlatformInfo(id(), CL_PLATFORM_VERSION, 40 * sizeof(char), &version_string, NULL));

  // !TODO -- parse 'version_string'
  return OpenCL_1_0;
}

std::vector<Device> Platform::get_devices(cl_device_type Type) {
  cl_uint devices_count = 0;
  OCL(clGetDeviceIDs(id(), Type, 1, NULL, &devices_count));

  // !TODO -- check for 'devices_count == 0' and throw exception

  std::vector<cl_device_id> raw_devices_vec(devices_count);
  OCL(clGetDeviceIDs(id(), Type, devices_count, &raw_devices_vec.front(), NULL));

  std::vector<Device> result;
  result.reserve(raw_devices_vec.size());

  for(unsigned i = 0; i < devices_count; i++)
    result.push_back(raw_devices_vec[i]);

  return result;
}