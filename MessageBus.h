#pragma once
#include <vector>
#include <functional>
#include <queue>
class System;

enum Msg
{
	ERROR,
	DEFAULT,
	EXIT
};

class MessageBus
{
public:
	MessageBus();
	~MessageBus();
	void postMessage(Msg);
	void notify();
	void newListener(std::function<void(Msg)>);
	Msg getMostRecent();

private:
	std::vector<std::function<void(Msg)>> sysList;
	std::queue<Msg> messages;
	Msg mostRecent;
};

