#include "Application.hpp"

using namespace Leap;

Application::Application(std::shared_ptr<Configuration> configuration) : configuration(configuration) {};

void Application::start() {
	addGestureListenersToController();
	setControllerPolicyFlags();
}

void Application::addGestureListenersToController() {
	std::vector<std::shared_ptr<AbstractGestureListener>> listeners = configuration->getGestureListeners();
	std::for_each(listeners.begin(), listeners.end(), 
		[this](std::shared_ptr<AbstractGestureListener> listener) -> void {
			controller.addListener(*listener);
	});
}

void Application::setControllerPolicyFlags() {
	Controller::PolicyFlag flag = configuration->getPolicyFlag();
	controller.setPolicyFlags(flag);
}

void Application::end() {
	removeGestureListenersFromController();
}

void Application::removeGestureListenersFromController() {
	std::vector<std::shared_ptr<AbstractGestureListener>> listeners = configuration->getGestureListeners();
	std::for_each(listeners.begin(), listeners.end(), 
		[this](std::shared_ptr<AbstractGestureListener> listener) -> void {
			controller.removeListener(*listener);
	});
}