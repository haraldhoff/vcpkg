// https://github.com/jbeder/yaml-cpp/wiki/Tutorial

#include "yaml-cpp/yaml.h"
#include <iostream>

int main()
{
	YAML::Node primes = YAML::Load("[2, 3, 5, 7, 11]");
	for (std::size_t i = 0; i < primes.size(); i++)
	{
		std::cout << primes[i].as<int>() << "\n";
	}
}