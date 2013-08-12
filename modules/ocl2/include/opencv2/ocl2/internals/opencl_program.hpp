#pragma once
#include <vector>

#include "utils.hpp"
#include "opencl_kernel.hpp"
#include "opencl_context.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class Program {
public:
  Program(const Program&);
  ~Program();

  cl_program id() { return raw_id_; }

  // !TODO -- program info accessors
  Kernel get_kernel(const std::string& KernelName);

private:
  friend class ProgramBuilder;
  Program(cl_program Id)
  : raw_id_(Id)
  { }

  cl_program raw_id_;
};

// !TODO -- add precompiled binary programs loading
class ProgramBuilder {
public:
  ProgramBuilder(Context Ctx)
  : ctx_(Ctx)
  { }

  ProgramBuilder& operator<<(const std::string& FileName);
  Program build(const std::string& flags = "");

  std::string build_log(Program P);

private:
  Context ctx_;
  std::vector<std::string> sources_;

  std::string get_file_content_(const std::string& FileName);
};

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END