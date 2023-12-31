//
// Created by caoqi on 2018/8/27.
//

#ifndef IMAGEBASEDMODELLINGEDU_FUNCTIONS_H
#define IMAGEBASEDMODELLINGEDU_FUNCTIONS_H


#include <util/timer.h>
#include "util/file_system.h"
#include "core/scene.h"
#include "core/image_tools.h"
#include "core/view.h"
#include "core/image.h"

core::ByteImage::Ptr
load_8bit_image (std::string const& fname, std::string* exif);

core::RawImage::Ptr
load_16bit_image (std::string const& fname);

core::FloatImage::Ptr
load_float_image (std::string const& fname);

core::ImageBase::Ptr
load_any_image (std::string const& fname, std::string* exif);

std::string
remove_file_extension (std::string const& filename);


/**
 * 模板类
 * @tparam T
 * @param img
 * @param max_pixels
 * @return
 */
template <class T>
typename core::Image<T>::Ptr
limit_image_size (typename core::Image<T>::Ptr img, int max_pixels)
{
    while (img->get_pixel_amount() > max_pixels)
        img = core::image::rescale_half_size<T>(img);
    return img;
}

/**
 *
 * @param image
 * @param max_pixels
 * @return
 */
core::ImageBase::Ptr
limit_image_size (core::ImageBase::Ptr image, int max_pixels);

bool has_jpeg_extension (std::string const& filename);

std::string make_image_name (int id);

void  add_exif_to_view (core::View::Ptr view, std::string const& exif);



#endif //IMAGEBASEDMODELLINGEDU_FUNCTIONS_H
