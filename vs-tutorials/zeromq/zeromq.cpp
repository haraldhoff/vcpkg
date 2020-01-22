// https://learning-0mq-with-pyzmq.readthedocs.io/en/latest/pyzmq/patterns/pubsub.html

#include <zmq.h>
//#include "zhelpers.h"

#include <string>

using namespace std;

void publisher()
{
	int rc = 0;

	void *context = zmq_ctx_new();
	printf("publisher : setup context ok\n");

	void *publisher = zmq_socket(context, ZMQ_PUB);
	printf("publisher : setup publisher ok\n");

	string address = "tcp://127.0.0.1:52001";
	zmq_bind(publisher, address.c_str());
	printf("publisher : bind address ok -- %s\n", address.c_str());

	for (int i = 0; i < 1000; i++)
	{
		char* topic = (char*)"NEWSFLASH";
		char content[256];

		sprintf_s(content, "Hello World %d", i);

		rc = zmq_send(publisher, topic, strlen(topic), ZMQ_SNDMORE);
		rc = zmq_send(publisher, content, strlen(content), 0);

		printf("publisher : publishing message on topic=%s, content=%s\n", topic, content);
		zmq_sleep(1);
	}

	printf("");
}

void subscriber()
{
}

int main()
{
	publisher();
	return 0;
}
