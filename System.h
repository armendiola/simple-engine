#pragma once
#include <iostream>
#include <functional>
#include "MessageBus.h"
class System
{
public:
	System();
	System(MessageBus*);
	~System();
	virtual void handleMessage(Msg) { std::cerr << "Message to Virtual System" << std::endl; };

protected:
	MessageBus* msgBus;
	std::function<void(Msg)> getListener();
};

