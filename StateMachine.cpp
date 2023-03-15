#include "StateMachine.h"

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::AddState(stateReference newState, bool isReplacing)
{
	if (!this->states.empty())
	{
		if (isReplacing)
		{
			this->states.pop();
		}
		else
		{
			this->states.top()->Pause();
		}
	}

	this->states.push(std::move(newState));
	this->states.top()->Init();
}

void StateMachine::RemoveState()
{
	if (!this->states.empty())
	{
		this->states.pop();

		if (!this->states.empty())
		{
			this->states.top()->Resume();
		}
	}
}

stateReference& StateMachine::GetActiveState()
{
	return this->states.top();
}
