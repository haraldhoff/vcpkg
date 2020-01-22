// https://learning-0mq-with-pyzmq.readthedocs.io/en/latest/pyzmq/patterns/pubsub.html

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <thread>
#include <zmq.hpp>

using namespace std;

void publisher()
{
	// https://en.cppreference.com/w/cpp/language/try_catch
	try
	{
		zmq::context_t context(1);
		zmq::socket_t publisher(context, ZMQ_PUB);
		std::string address("tcp://127.0.0.1:52001");
		publisher.bind(address);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	printf("");
}

void subscriber()
{
}

int main(int argc, char *argv[])
{
	publisher();
	return 0;
}
