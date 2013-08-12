#pragma once
#include <vector>

#include "utils.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class Kernel {
public:
  Kernel(const Kernel&);
  ~Kernel();

  cl_kernel handle() { return raw_handle_; }
  // !TODO -- kernel info accessors

private:
  friend class Program;
  
  Kernel(cl_kernel Handle)
  : raw_handle_(Handle)
  { }

  cl_kernel raw_handle_;
};

/*class KernelArgs {
public:
  template<typename Arg>
  KernelArgs& operator<<(const Arg& argument) {
    arguments_.push_back(std::make_pair(sizeof(Arg), &argument));
    return *this;
  }

  argument_t* data() {
    return &arguments_.front();
  }
  unsigned size() {
    return arguments_.size();
  }

private:
  typedef std::pair<unsigned, void*> argument_t;

private:
  std::vector<argument_t> arguments_;
};*/

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END