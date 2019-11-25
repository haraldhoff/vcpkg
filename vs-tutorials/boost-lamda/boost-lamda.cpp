// https://www.boost.org/doc/libs/1_64_0/more/getting_started/windows.html

// Usage: Enter some number in the console and press enter

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " ");
}
