// https://www.boost.org/doc/libs/1_71_0/doc/html/boost_asio/tutorial/tuttimer1.html

#include <iostream>
#include <boost/asio.hpp>

int main()
{
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	t.wait();
	std::cout << "Hello, world!" << std::endl;

	return 0;
}
