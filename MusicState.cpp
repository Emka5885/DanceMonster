#include "MusicState.h"
#include "MainMenuState.h"

MusicState::MusicState(GameDataReference data) : data(data)
{
}

void MusicState::Init()
{
	buttonSize = { 150, 85 };
	data->buttons->NewButton(buttonSize, { 50, 50 }, sf::Color::White, "Back", 50, sf::Color::Black, "back_button");
	backButton = data->buttons->GetButton("back_button").first;
	backText = data->buttons->GetButton("back_button").second;

	musicText.setString("MUSIC");
	musicText.setFont(data->assets.GetFont("standardFont"));
	musicText.setCharacterSize(80);
	musicText.setOutlineColor(sf::Color::Black);
	musicText.setOutlineThickness(4);
	musicText.setPosition({ WIDTH / 2 - musicText.getGlobalBounds().width / 2, 50});
}

void MusicState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data->window.close();
			delete data->buttons;
			delete data->widgets;
		}

		if (data->input.isButtonClicked(backButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
	}
}

void MusicState::Update(float dt)
{
}

void MusicState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(backButton);
	data->window.draw(backText);
	data->window.draw(musicText);

	data->window.display();
}
