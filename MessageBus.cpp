#include "MessageBus.h"
#include "System.h"

MessageBus::MessageBus(){
	sysList = std::vector<std::function<void(Msg)>>();
	messages = std::queue<Msg>();
	mostRecent = DEFAULT;
}

MessageBus::~MessageBus(){
}

void MessageBus::postMessage(Msg msg){
	messages.push(msg);
	mostRecent = msg;
}

void MessageBus::notify(){
	while (!messages.empty()){
		for (auto iter = sysList.begin(); iter != sysList.end(); iter++) (*iter)(messages.front());
		messages.pop();
	}
}

void MessageBus::newListener(std::function<void(Msg)> sys){
	sysList.push_back(sys);
}

Msg MessageBus::getMostRecent(){
	return mostRecent;
}