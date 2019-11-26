// https://github.com/jbeder/yaml-cpp/wiki/How-To-Parse-A-Document-(Old-API)

#include <fstream>
#include "yaml-cpp/yaml.h"

int main()
{
    std::ifstream fin("test.yaml");
    YAML::Parser parser(fin);

    YAML::Node doc;
    while(parser.GetNextDocument(doc)) {
       // ...
    }

    return 0;
}