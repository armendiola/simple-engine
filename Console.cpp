#include "Console.h"

Console::Console(MessageBus* bus){
	msgBus = bus;
	msgBus->newListener(this->getListener());
}

Console::~Console(){
	msgBus = nullptr;
}

void Console::postMessage(Msg msg){
	msgBus->postMessage(msg);
}

void Console::handleMessage(Msg msg){
	switch (msg){
	case ERROR:
		std::cerr << "ERROR: Error message received!" << std::endl;
		break;
	case DEFAULT:
		std::cout << "Default message received" << std::endl;
		break;
	case EXIT:
		std::cout << "Exit command received" << std::endl;
		break;
	default:
		break;
	}
}

std::function<void(Msg)> Console::getListener(){
	auto messageListener = [=](Msg msg) -> void {
		this->handleMessage(msg);
	};
	return messageListener;
}