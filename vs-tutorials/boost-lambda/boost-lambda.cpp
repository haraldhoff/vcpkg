// https://www.boost.org/doc/libs/1_71_0/more/getting_started/windows.html

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace boost::lambda;

int main()
{
	typedef istream_iterator<int> in;

	cout << "Usage: Enter some numbers in the console with space between and press enter" << endl;

	for_each(
		in(cin), in(), cout << (_1 * 3) << " ");
}
