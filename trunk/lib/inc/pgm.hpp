#ifndef PGM_INCLUDE
#define PGM_INCLUDE

#include <string>
#include <vector>
#include <boost/multi_array.hpp>
#include "utils.hpp"

namespace ZouchUtils
{

class PGM
{
public:
    static void writePGM(const std::string& filename,
                         const std::vector<int>& data,
                         int width, int height, int maxval);
    static void writePGM(const std::string& filename,
                         const boost::multi_array<int,2>& data,
                         int width, int height, int maxval);
    static void readPGM(const std::string& filename,
                        std::vector<int>& data,
                        int& width, int& height, int& maxval);
};
} // namespace

#endif // PGM_INCLUDE
