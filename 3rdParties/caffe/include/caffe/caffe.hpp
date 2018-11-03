// caffe.hpp is the header file that you need to include in your code. It wraps
// all the internal caffe header files into one for simpler inclusion.

#ifndef CAFFE_CAFFE_HPP_
#define CAFFE_CAFFE_HPP_

#include "blob.hpp"
#include "common.hpp"
#include "filler.hpp"
#include "layer.hpp"
#include "layer_factory.hpp"
#include "net.hpp"
#include "parallel.hpp"
#include "proto/caffe.pb.h"
#include "solver.hpp"
#include "solver_factory.hpp"
#include "util/benchmark.hpp"
#include "util/io.hpp"
#include "util/upgrade_proto.hpp"

#endif  // CAFFE_CAFFE_HPP_
