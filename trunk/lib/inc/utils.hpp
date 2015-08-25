#ifndef UTILS_INCLUDE
#define UTILS_INCLUDE

#include <boost/lexical_cast.hpp>

/**
 * @brief This file is a sort of "cover-all" file, containing everything
 * which has not found his place somewhere else.
 */

namespace ZouchUtils
{

#define cast_double(str) boost::lexical_cast<double>(str)
#define cast_int(str)    boost::lexical_cast<int>(str)

template <typename T>
T bound(const T& val, const T& min, const T& max, const T& newmax)
{ return T(((val - min)/max)*newmax); }

} // namespace

#endif // UTILS_INCLUDE
