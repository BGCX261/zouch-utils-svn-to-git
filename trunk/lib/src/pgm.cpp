#include "pgm.hpp"

#include <exception>
#include <fstream>
#include "utils.hpp"

using namespace std;

namespace ZouchUtils
{

void PGM::writePGM(const string& filename,
                   const vector<int>& data,
                   int width, int height, int maxval)
{
    ofstream file(filename.c_str(), ios::out);

    if (file.fail())
    {
        string err;
        err = "Unable to open file " + filename + " for writing.";
        throw ios_base::failure(err);
    }

    // Write headers
    file << "P2" << endl
         << width << " " << height << endl
         << maxval << endl;

    for (int i = 0; i < width * height; ++i)
        file << data.at(i) << endl;
}

void PGM::writePGM(const string &filename,
                   const boost::multi_array<int,2>& data,
                   int width, int height, int maxval)
{
    ofstream file(filename.c_str(), ios::out);

    if (file.fail())
    {
        string err;
        err = "Unable to open file " + filename + " for writing.";
        throw ios_base::failure(err);
    }

    // Write headers
    file << "P2" << endl
         << width << " " << height << endl
         << maxval << endl;

    for (int j = 0; j < width; ++j)
        for (int i = 0; i < height; ++i)
            file << data[i][j] << endl;
}

void PGM::readPGM(const string& filename,
                  vector<int>& data,
                  int& width, int& height, int& maxval)
{
    ifstream file(filename.c_str(), ios::in);

    if (file.fail())
    {
        string err;
        err = "Unable to open file " + filename + " for writing.";
        throw ios_base::failure(err);
    }

    string head;
    file >> head;
    if (head != "P2")
    {
        file.close();
        string err;
        err = "Error in the header of the file " + filename;
        throw runtime_error(err);
    }
    data.clear();
    file >> width >> height >> maxval;
    file >> ws;

    while (!file.eof())
    {
        string line;
        getline(file, line);
        std::istringstream ss(line);
        while (!ss.eof()) {
            string number;
            getline(ss, number, ' ');
            try {
                data.push_back(cast_int(number));
            } catch (std::exception &e) {
                file.close();
                throw std::runtime_error(e.what());
            }
        }
    }
}

} // namespace
