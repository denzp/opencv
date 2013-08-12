#pragma once
#include <vector>

#include "utils.hpp"
#include "opencl_context.hpp"
#include "opencl_device.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class CommandQueue {
public:
  CommandQueue(Context, Device);
  CommandQueue(const CommandQueue&);
  ~CommandQueue();

  template<typename Act>
  CommandQueue& operator<<(const Act& Action) {
    Action(*this);
    return *this;
  }

  cl_command_queue handle() { return raw_handle_; }

private:
  cl_command_queue raw_handle_;
};

OCL2_NAMESPACE_END
INTERNALS_NAMESPACE_END