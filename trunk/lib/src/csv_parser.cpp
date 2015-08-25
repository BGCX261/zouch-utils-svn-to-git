#include "csv_parser.hpp"
#include <fstream>
#include <exception>
#include <limits>
#include <iomanip>
#include "utils.hpp"

using namespace std;

namespace ZouchUtils
{

CSVContent CSVParser::parse(const std::string &filename, const char token)
{
    ifstream file(filename.c_str(), ios::in);

    if (file.fail()) {
        // Throw an ios_base::failure exception
        string err;
        err = "Unable to open file " + filename;
        throw ios_base::failure(err);
    }

#ifdef DEBUG
    cerr << endl
         << "Parsing of file " << filename << " has begun."
         << endl;
#endif

    string line;
    CSVContent res;
    try {
        getline(file, line); res.Xres   = cast_int(line);
        getline(file, line); res.Yres   = cast_int(line);
        getline(file, line); res.Xbegin = cast_double(line);
        getline(file, line); res.Xend   = cast_double(line);
        getline(file, line); res.Ybegin = cast_double(line);
        getline(file, line); res.Yend   = cast_double(line);
    } catch (std::exception &e) {
        cerr << line << endl;
        file.close();
        throw std::runtime_error(e.what());
    }

    Matrix mat(boost::extents[res.Xres][res.Yres]);
    int i = 0, j = 0;
    while (i < res.Xres) {
        line.clear();
        getline(file, line);
        std::istringstream ss(line);
        while (!ss.eof()) {
            string number;
            getline(ss, number, token);
            try {
                mat[i][j] = cast_double(number);
            } catch (std::exception &e) {
                file.close();
                throw std::runtime_error(e.what());
            }
            ++j;
        }
#ifdef DEBUG
        cerr << "Line " << i << " has been read, "
             << j << " numbers read." << endl;
#endif
        ++i;
        j = 0;
    }

    std::vector<size_t> ex;
    const size_t* shape = mat.shape();
    ex.assign(shape, shape+mat.num_dimensions());
    res.content.resize(ex);
    res.content = mat;

#ifdef DEBUG
    cerr << endl
         << "File parsing is now finished."
         << endl;
#endif

    return res;

}

}
