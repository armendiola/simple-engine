#pragma once
#include "System.h"
#include "MessageBus.h"
class Console/* : public System*/
{
public:
	Console(MessageBus*);
	~Console();
	void postMessage(Msg);
	void handleMessage(Msg);

protected:
	MessageBus* msgBus;
	std::function<void(Msg)> getListener();
};

