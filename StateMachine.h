#pragma once
#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> stateReference;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void AddState(stateReference newState, bool isReplacing = true);
	void RemoveState();

	stateReference& GetActiveState();

private:
	std::stack<stateReference> states;
};