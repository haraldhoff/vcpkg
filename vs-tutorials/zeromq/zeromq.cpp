// https://learning-0mq-with-pyzmq.readthedocs.io/en/latest/pyzmq/patterns/pubsub.html

#include <zmq.h>
//#include "zhelpers.h"

#include <string>

using namespace std;

string address = "tcp://127.0.0.1:52001";
char* topic = (char*)"NEWSFLASH";


void publisher()
{
	int rc = 0;

	void *context = zmq_ctx_new();
	printf("publisher : setup context ok\n");

	void *publisher = zmq_socket(context, ZMQ_PUB);
	printf("publisher : setup ok\n");

	zmq_bind(publisher, address.c_str());
	printf("publisher : bind address ok -- %s\n", address.c_str());

	for (int i = 0; i < 1000; i++)
	{
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
	int rc = 0;

	void *context = zmq_ctx_new();
	printf("subscriber : setup context ok\n");

	void *subscriber = zmq_socket(context, ZMQ_SUB);
	printf("subscriber : setup ok\n");

	zmq_connect(subscriber, address.c_str());
	printf("subscriber : connect address ok -- %s\n", address.c_str());

	rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, topic, strlen(topic));
	printf("subscriber : subscribe to topic %s\n", topic);

	char buffer[65536];

	while (1)
	{
		rc = zmq_recv(subscriber, buffer, sizeof(buffer), 0);
		buffer[rc] = 0;
		printf("%s\n", buffer);
		printf("");
	}

}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("Usage : specify either pub or sub as arguments\n");
	} else
	{
		if (strcmp(argv[1], "pub") == 0)
		{
			publisher();
		}
		else
		if (strcmp(argv[1], "sub") == 0)
		{
			subscriber();
		}
		else
		{
			printf("Usage : specify either pub or sub as arguments\n");
		}
	}
	return 0;
}
