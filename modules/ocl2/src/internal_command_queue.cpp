#include <opencv2/ocl2/internals/opencl_command_queue.hpp>
#include <opencv2/ocl2/internals/opencl_cq_actions.hpp>

using namespace cv::ocl2::internals;

CommandQueue::CommandQueue(Context Ctx, Device Dev) {
  cl_int err;

  cl_command_queue cq = clCreateCommandQueue(Ctx.id(), Dev.id(), NULL, &err);
  OCL(err);
}
CommandQueue::CommandQueue(const CommandQueue& Rhs) {
  raw_handle_ = Rhs.raw_handle_;
  OCL(clRetainCommandQueue(handle()));
}
CommandQueue::~CommandQueue() {
  OCL(clReleaseCommandQueue(handle()));
}

void CQAction<CQ_KERNEL_RANGE>::operator()(CommandQueue& Queue) {
  OCL(clEnqueueNDRangeKernel(
    Queue.handle(), kernel_.handle(), 
    range_.dimension(), NULL, range_.ranges(), NULL, 
    0, NULL, NULL));
}