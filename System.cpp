#include "System.h"

System::System(){
	msgBus = nullptr;
}

System::System(MessageBus* bus){
	msgBus = bus;
	bus->newListener(this->getListener());
}

System::~System(){
	msgBus = nullptr;
}

std::function<void(Msg)> System::getListener(){
	auto messageListener = [=](Msg msg) -> void {
		this->handleMessage(msg);
	};
	return messageListener;
}