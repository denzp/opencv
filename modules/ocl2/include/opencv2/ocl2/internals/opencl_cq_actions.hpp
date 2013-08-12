#pragma once

#include "utils.hpp"
#include "opencl_range.hpp"
#include "opencl_kernel.hpp"
#include "opencl_command_queue.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

enum CommandQueueAction {
  CQ_WRITE_BUFFER = 1,
  CQ_READ_BUFFER  = 2,

  CQ_WRITE_IMAGE  = 3,
  CQ_READ_IMAGE   = 4,

  CQ_KERNEL_RANGE = 5,

  CQ_MAP_BUFFER   = 6,
  CQ_UNMAP_BUFFER = 7
};

template<int Action>
class CQAction {
private:
  CQAction(const CQAction&);
  CQAction();
};

template<>
class CQAction<CQ_KERNEL_RANGE> {
public:
  CQAction(Kernel Kern, const CLRange& Range)
  : range_(Range),
    kernel_(Kern)
  { }

  void operator()(CommandQueue& Queue);

private:
  CLRange range_;
  Kernel  kernel_;
};

OCL2_NAMESPACE_END
INTERNALS_NAMESPACE_END