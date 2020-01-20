// https://github.com/jbeder/yaml-cpp/wiki/Tutorial

#include "yaml-cpp/yaml.h"
#include <iostream>

using namespace std;

int main()
{
	auto document = "[2, 3, 5, 7, 11]";
	auto primes = YAML::Load(document);

	for (std::size_t i = 0; i < primes.size(); i++)
		std::cout << primes[i].as<int>() << "\n";
}
