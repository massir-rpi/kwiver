/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
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
 * \brief Header for \link kwiver::vital::detected_object detected_object \endlink class
 */

#ifndef VITAL_DETECTED_OBJECT_H_
#define VITAL_DETECTED_OBJECT_H_

#include <vital/vital_export.h>
#include <vital/vital_config.h>

#include <memory>

#include <vital/types/object_type.h>
#include <vital/types/vector.h>

#include <vital/io/eigen_io.h> //This suppresses a warning in Eigen/Geometry.h
#include <Eigen/Geometry>

namespace kwiver {
namespace vital {

/// forward declaration of detected_object class
class detected_object;

/// typedef for a detected_object shared pointer
typedef std::shared_ptr< detected_object > detected_object_sptr;

// ----------------------------------------------------------------
/**
 * @brief Detected object class.
 *
 * This class represents a detected object in image space.
 *
 * There is one object of this type for each detected object. These
 * objects are defined by a bounding box in the image space. Each
 * object has an optional classification object attached.
 *
 */
class VITAL_EXPORT detected_object
{
public:
  class bounding_box
  {
  public:
    bounding_box()
    {}
    bounding_box(vital::vector_2d upper_left, vital::vector_2d lower_right)
    : m_bbox(upper_left,lower_right)
    {}
    vital::vector_2d center() const
    {
      return m_bbox.center();
    }
    vital::vector_2d upper_left() const
    {
      return m_bbox.min();
    }
    vital::vector_2d lower_right() const
    {
      return m_bbox.max();
    }
    double width() const
    {
      return m_bbox.sizes()[0];
    }
    double height() const
    {
      return m_bbox.sizes()[1];
    }
    double area() const
    {
      return m_bbox.volume();
    }

    bounding_box intersection(bounding_box const& other)
    {
      return bounding_box(m_bbox.intersection(other.m_bbox));
    }

  protected:
    Eigen::AlignedBox2d m_bbox;
    bounding_box(Eigen::AlignedBox2d b)
    :m_bbox(b)
    {}
  };

  detected_object();
  detected_object(bounding_box bbox, double confidence = 1.0,
               object_type_sptr classifications = NULL);
  virtual ~detected_object() VITAL_DEFAULT_DTOR

  bounding_box get_bounding_box() const;
  void set_bounding_box(bounding_box bbox);

  double get_confidence() const;
  void set_confidence(double d);

  /**
   * @brief Get pointer to optional classification object.
   *
   * This method returns the pointer to the classification object if
   * there is one. If there is no classification object the pointer is
   * NULL.
   *
   * @return Pointer to classification object or NULL.
   */
  object_type_sptr get_classifications();

  void set_classifications( object_type_sptr c );

private:
  bounding_box bounding_box_;
  double confidence_;
  object_type_sptr classifications_;
};

} }

#endif
