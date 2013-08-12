if(NOT HAVE_OPENCL)
  ocv_module_disable(ocl2)
endif()

set(the_description "OpenCL-accelerated Computer Vision [revised]")
ocv_module_include_directories(${OPENCL_INCLUDE_DIR})
ocv_define_module(ocl2)