#pragma once
#include <vector>

#include "utils.hpp"
#include "opencl_device.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

enum cl_version {
  OpenCL_1_0,
  OpenCL_1_1,
  OpenCL_1_2,
  OpenCL_2_0
};

class Platform {
public:
  static std::vector<Platform> get_all_platforms();

  cl_platform_id id() { return raw_id_; }

  cl_version version();
  std::string name();
  std::string vendor();

  std::vector<Device> get_devices(cl_device_type = CL_DEVICE_TYPE_ALL);

private:
  Platform(cl_platform_id Id)
  : raw_id_(Id)
  { }

  cl_platform_id raw_id_;
};

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END