#pragma once
#include <stdexcept>

#include "utils.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class OpenCLException
: public std::exception
{
  // !TODO
};

inline void __ocl_check_for_errors(cl_int error_code) {
  error_code++;
}

#define OCL(Arg) __ocl_check_for_errors(Arg)

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END