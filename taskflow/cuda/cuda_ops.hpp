#pragma once

#include "cuda_graph.hpp"

namespace tf {

// ----------------------------------------------------------------------------
// for_each
// ----------------------------------------------------------------------------

// Kernel: for_each
template <typename T, typename F>
__global__ void cuda_for_each(T* data, size_t N, F functor) {
  size_t i = blockIdx.x*blockDim.x + threadIdx.x;
  if (i < N) {
    functor(data[i]);
  }
}

// ----------------------------------------------------------------------------
// transform
// ----------------------------------------------------------------------------

// Kernel: for_each
template <typename T, typename F, typename... S>
__global__ void cuda_transform(T* data, size_t N, F functor, S*... src) {
  size_t i = blockIdx.x*blockDim.x + threadIdx.x;
  if (i < N) {
    data[i] = functor(src[i]...);
  }
}


}  // end of namespace tf -----------------------------------------------------







