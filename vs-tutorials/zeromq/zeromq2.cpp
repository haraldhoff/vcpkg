//// https://learning-0mq-with-pyzmq.readthedocs.io/en/latest/pyzmq/patterns/pubsub.html
//
//#include <iostream>
//#include <sstream>
//#include <string.h>
//#include <string>
//#include <thread>
//#include <zmq.hpp>
//
//using namespace std;
//
//void publisher()
//{
//	// https://en.cppreference.com/w/cpp/language/try_catch
//	try
//	{
//		string address("tcp://127.0.0.1:52001");
//		cout << "Publisher : Starting on address : " + address << endl;
//		zmq::context_t context(1);
//		zmq::socket_t publisher(context, ZMQ_PUB);
//		publisher.bind(address);
//		cout << "Publisher : Started OK" << endl;
//		
//		// let's publish a few "Hello" messages
//		for (size_t i = 0; i < 1000; ++i) {
//			// create a message
//			std::stringstream s;
//			s << "Hello " << i;
//			auto msg = s.str();
//			zmq::message_t message(msg.length());
//			memcpy(message.data(), msg.c_str(), msg.length());
//			publisher.send(message, ZMQ_NOBLOCK);
//			zmq_sleep(1);
//		}
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//		exit(1);
//	}
//	printf("");
//}
//
//void subscriber()
//{
//}
//
//int main(int argc, char *argv[])
//{
//	publisher();
//	return 0;
//}
