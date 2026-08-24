#pragma once

#include <limits>

#include "Usings.h"

struct Constants {

    // An invalid price constant for Market Order
    static const Price InvalidPrice = std::numeric_limits<Price>::quiet_NaN();
};
