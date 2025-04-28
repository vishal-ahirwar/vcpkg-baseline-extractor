#include <iostream>
#include <boost/config.hpp>
#include <boost/process.hpp>
#include <cpr/cpr.h>
#include <print>
#include <sstream>
#include <string>

void readUserInput(std::string &name, std::string &version);
bool fetchBaseLine(const std::string &name, const std::string &version, std::string &baseLine);
int main()
{
    std::string name{}, version{}, log{};
    readUserInput(name, version);
    if (!fetchBaseLine(name, version, log))
    {
        std::print("Failed to read baseline commit!\n");
        return -1;
    };
    std::print("Extraction Finished!\n");
    return 0;
}
void readUserInput(std::string &name, std::string &version)
{
    std::print("Enter Package Name with Version <Seprated by Space>");
    std::string input{};
    std::getline(std::cin, input);
    try
    {
        std::stringstream ss(input);
        ss >> name;
        ss >> version;
    }
    catch (std::exception &e)
    {
        std::print("Exception : {}\n", e.what());
        std::exit(0);
    };
}

bool fetchBaseLine(const std::string &name, const std::string &version, std::string &baseLine)
{
    std::string vcpkg{std::getenv("VCPKG_ROOT")};
    if (vcpkg.length() <= 0)
    {
        std::print("VCPKG_ROOT is not Set!\n");
        return false;
    }
    boost::process::ipstream out;
    boost::process::ipstream err;
    boost::process::child c(boost::process::search_path("git"), boost::process::args({"-C", vcpkg, "log", "--format=%H %cd %s", "--date=short", "--left-only", "--", std::string("versions/") + name[0] + "-/" + name + ".json"}), boost::process::std_err > err, boost::process::std_out > out);
    std::string line{}, first{};
    std::stringstream ss(name);
    std::getline(ss, first, '-');
    while (std::getline(out, line) || std::getline(err, line))
    {
        if (version.length() <= 0)
        {
            if (line.find(first) != std::string::npos)
            {
                auto index = line.find(" ");
                baseLine = line.substr(0, index);
                std::string version = line.substr(index, line.find(" ", index));
                std::print("Package : {}, Version : {}, Baseline Commit : {}\n[{}]\n", name, version, baseLine, line);
                break;
            }
        }
        else if (line.find(first) != std::string::npos && line.find(version) != std::string::npos)
        {
            baseLine = line.substr(0, line.find(" "));
            std::print("Package : {}, Version : {}, Baseline Commit : {}\n[{}]\n", name, version, baseLine, line);
        }
    }
    c.wait();
    return c.exit_code() == 0;
};
