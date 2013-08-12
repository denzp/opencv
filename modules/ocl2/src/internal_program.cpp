#include <fstream>

#include <opencv2/ocl2/internals/opencl_program.hpp>

using namespace cv::ocl2::internals;

ProgramBuilder& ProgramBuilder::operator<<(const std::string& FileName) {
  sources_.push_back(get_file_content_(FileName));
  return *this;
}

std::string ProgramBuilder::get_file_content_(const std::string& FileName) {
  std::ifstream file_stream(FileName.c_str());

  return std::string(
    std::istreambuf_iterator<char>(file_stream),
    std::istreambuf_iterator<char>());
}

Program ProgramBuilder::build(const std::string& flags) {
  std::vector<const char*>  sources_ptr(sources_.size());
  std::vector<size_t>       sources_len(sources_.size());
  for(unsigned i = 0; i < sources_ptr.size(); ++i) {
    sources_ptr[i] = sources_[i].c_str();
    sources_len[i] = sources_[i].size() + 1;
  }

  cl_int err;
  cl_program program =
    clCreateProgramWithSource(ctx_.id(), sources_ptr.size(), &sources_ptr.front(), &sources_len.front(), &err);

  OCL(err);

  OCL(clBuildProgram(program, ctx_.devices().size(), &ctx_.devices().front(), flags.c_str(), NULL, NULL));

  return Program(program);
}

std::string ProgramBuilder::build_log(Program P) {
  size_t log_size;
  OCL(clGetProgramBuildInfo(P.id(), ctx_.devices()[0], CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size));

  std::string log_string(log_size, '\0');
  OCL(clGetProgramBuildInfo(P.id(), ctx_.devices()[0], CL_PROGRAM_BUILD_LOG, log_size, &log_string[0], NULL));

  return log_string;
}


Program::Program(const Program& Rhs) {
  raw_id_ = Rhs.raw_id_;
  OCL(clRetainProgram(id()));
}
Program::~Program() {
  OCL(clReleaseProgram(id()));
}

Kernel Program::get_kernel(const std::string& KernelName) {
  cl_int err;

  cl_kernel kernel = clCreateKernel(id(), KernelName.c_str(), &err);
  OCL(err);

  return Kernel(kernel);
}