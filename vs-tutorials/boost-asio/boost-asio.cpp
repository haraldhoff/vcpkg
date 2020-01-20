// https://www.boost.org/doc/libs/1_71_0/doc/html/boost_asio/tutorial/tuttimer1.html

#include <iostream>
#include <chrono>
#include <boost/asio.hpp>

using namespace std;

int main()
{
	cout << "Waiting 3 seconds -- calling boost::asio::chrono::seconds(3)" << endl;
	auto t1 = chrono::high_resolution_clock::now();
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(3));
	t.wait();
	auto t2 = chrono::high_resolution_clock::now();
	auto ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Finished! --  std::chrono high precision timers says duration is " << ms << " [ms]" << endl;
	return 0;
}
