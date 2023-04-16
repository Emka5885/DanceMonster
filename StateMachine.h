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

	void AddState(stateReference newState, bool isReplacing = true, bool isGameState = false);
	void RemoveState();

	void ProcessStateChanges();

	stateReference& GetActiveState();

	bool hasMenuBackgroundMusic();

private:
	std::stack<stateReference> states;
	stateReference newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

	bool menuBackgroundMusic = true;
};