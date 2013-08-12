#pragma once

#define OCL2_NAMESPACE_BEGIN  namespace cv { namespace ocl2 {
#define OCL2_NAMESPACE_END    } }

#define INTERNALS_NAMESPACE_BEGIN namespace internals {
#define INTERNALS_NAMESPACE_END   }

#include <memory>
#include <string>

#if defined __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif

#include "exceptions.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class Context;
class Program;
class Platform;
//...

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END