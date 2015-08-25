#ifndef CSV_PARSER_INCLUDE
#define CSV_PARSER_INCLUDE

#include <string>
#include <boost/multi_array.hpp>
#include <boost/lexical_cast.hpp>

namespace ZouchUtils
{

typedef boost::multi_array<double, 2> Matrix;

struct CSVContent
{
    CSVContent() {}
    CSVContent(const CSVContent &other) :
        Xres(other.Xres), Yres(other.Yres),
        Xbegin(other.Xbegin), Xend(other.Xend),
        Ybegin(other.Ybegin), Yend(other.Yend)
    {
        std::vector<size_t> ex;
        const size_t* shape = other.content.shape();
        ex.assign(shape, shape+other.content.num_dimensions());
        content.resize(ex);
        content = other.content;
    }
    CSVContent operator=(const CSVContent &other)
    {
        Xres = other.Xres; Yres = other.Yres;
        Xbegin = other.Xbegin; Xend = other.Xend;
        Ybegin = other.Ybegin; Yend = other.Yend;

        std::vector<size_t> ex;
        const size_t* shape = other.content.shape();
        ex.assign(shape, shape+other.content.num_dimensions());
        content.resize(ex);
        content = other.content;
        return *this;
    }

    int Xres, Yres;
    double Xbegin, Xend;
    double Ybegin, Yend;

    Matrix content;
};

/**
 * @brief The CSVParser class offers parsing facilities for csv files.
 * CSV Header must be Xres, Yres, Xbegin, Xend, Ybegin, Yend
 */
class CSVParser
{
public:
    /**
     * @fn static std::vector< std::vector<T> > parse(const std::string& filename, const char token)
     *
     * @brief Parses csv file defined as input given a separator
     *
     * @param filename The name of the file to parse
     * @param token The separator used in the csv file
     * @return A CSVContent struct, encapsulating everything in the csv file
     */
    static CSVContent parse(const std::string& filename, const char token);

private:
//    explicit CSVParser(const std::string& filename);
//    ~CSVParser();

private:
    int width, height;
};

} // namespace

#endif // CSV_PARSER_INCLUDE
