#include "MessageBus.h"
#include "Console.h"
#include <string>
#include <regex>

int main(){
	MessageBus* msgBus = new MessageBus();
	Console* console = new Console(msgBus);
	while (true){
		bool exit = false;
		switch (msgBus->getMostRecent()){
		case EXIT:
			exit = true;
			break;
		default:
			std::string input = "";
			std::cin >> input;
			if (std::regex_match(input.c_str(), (std::regex("exit")))) msgBus->postMessage(Msg(EXIT));
			else if (std::regex_match(input.c_str(), (std::regex("[a-zA-Z]*")))) msgBus->postMessage(Msg(DEFAULT));
			else msgBus->postMessage(Msg(ERROR));
		}
		msgBus->notify();
		if (exit) break;
	}
	return 0;
}