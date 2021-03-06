/*ckwg +29
 * Copyright 2018 by Kitware, SAS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief uv_unwrap_mesh algorithm definition
 */

#ifndef VITAL_ALGO_UV_UNWRAP_MESH_H
#define VITAL_ALGO_UV_UNWRAP_MESH_H


#include <vital/vital_config.h>
#include <vital/algo/algorithm.h>

#include <vital/types/mesh.h>

namespace kwiver {
namespace vital {
namespace algo {

/// \brief Abstract base class for mesh uv unwrapping.
class VITAL_ALGO_EXPORT uv_unwrap_mesh
    : public kwiver::vital::algorithm_def<uv_unwrap_mesh>
{
public:
  /// Return the name of this algorithm
  static std::string static_type_name() { return "uv_unwrap_mesh"; }

  /// Unwrap a mesh and generate texture coordinates
  /**
   * \param mesh [in/out] mesh to unwrap
   */
  virtual void unwrap(kwiver::vital::mesh_sptr mesh) const = 0;

protected:
  uv_unwrap_mesh();

};

typedef std::shared_ptr<uv_unwrap_mesh> uv_unwrap_mesh_sptr;

} } }
#endif // VITAL_ALGO_UV_UNWRAP_MESH_H
