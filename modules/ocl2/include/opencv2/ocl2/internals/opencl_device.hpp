#pragma once
#include <vector>

#include "utils.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class Device {
public:
  cl_device_id id() const       { return raw_id_; }
  operator cl_device_id() const { return id(); }

  std::string name();
  std::string vendor();
  unsigned    mem_size();
  bool        available();

private:
  friend class Platform;

  Device(cl_device_id Id)
  : raw_id_(Id)
  { }

  cl_device_id raw_id_;
};

INTERNALS_NAMESPACE_END
OCL2_NAMESPACE_END