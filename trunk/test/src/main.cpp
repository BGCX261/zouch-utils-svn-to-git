#include <iostream>
#include "csv_parser.hpp"
#include <exception>
#include <vector>
#include <limits>
#include "utils.hpp"
#include "pgm.hpp"

using namespace std;
using namespace ZouchUtils;

int main()
{
    CSVContent content;
    try
    {
        content = CSVParser::parse("F.csv", ',');
        double min = numeric_limits<double>::max();
        double max = numeric_limits<double>::min();
        vector<double> data;
        vector<int> image;
        for (int i = 0; i < content.Xres; ++i)
            for (int j = 0; j < content.Yres; ++j)
            {
                double c = content.content[i][j];
                max = c > max ? c : max;
                min = c < min ? c : min;
                data.push_back(c);
            }
        for (int i = 0; i < data.size(); ++i)
        {
            double val = data[i];
            bound(val, min, max, double(255));
            image.push_back(bound(val, min, max, double(255)));
        }
        string filename = "image.pgm";
        PGM::writePGM(filename, image, content.Xres, content.Yres, double(255));
    }
    catch (exception &e)
    {
        cerr << "Exception catched : " << e.what() << endl;
    }

    return 0;
}

