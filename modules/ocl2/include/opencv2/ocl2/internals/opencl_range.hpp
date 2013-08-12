#pragma once

#include "utils.hpp"

OCL2_NAMESPACE_BEGIN
INTERNALS_NAMESPACE_BEGIN

class CLRange {
public:
  static const unsigned max_dimensions = 3;

  CLRange(signed d0)
  : dimension_(1)
  {
    ranges_[0] = d0; 
  }

  CLRange(signed d0, signed d1)
  : dimension_(2)
  {
    ranges_[0] = d0;
    ranges_[1] = d1;
  }

  CLRange(signed d0, signed d1, signed d2)
  : dimension_(3)
  {
    ranges_[0] = d0;
    ranges_[1] = d1;
    ranges_[2] = d2;
  }

  const size_t* ranges()    { return ranges_; }
  size_t        dimension() { return dimension_; }

private:
  size_t dimension_;
  size_t ranges_[max_dimensions]; 
};

OCL2_NAMESPACE_END
INTERNALS_NAMESPACE_END