#pragma once
#include <vector>

#include "utils.hpp"
#include "opencl_platform.hpp"
#include "opencl_device.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class Context {
public:
  template<typename Iter>
  Context(Platform P, Iter DevicesBegin, Iter DevicesEnd)
  {
    new(this) Context(P, std::vector<Device>(DevicesBegin, DevicesEnd));
  }

  Context(Platform P, const std::vector<Device>& Devices);
  Context(const Context&);

  ~Context();

  cl_context id() { return raw_id_; }
  const std::vector<cl_device_id>& devices() { return devices_; }

private:
  cl_context                raw_id_;
  std::vector<cl_device_id> devices_;
};

OCL2_NAMESPACE_END
INTERNALS_NAMESPACE_END