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

	CreateMusicOptionsButtons();

	counter = 0;
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
	s->Update(event, counter, 101, 1);
	std::cout << counter << "\n";
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
	data->window.draw(menu);
	data->window.draw(menuText);
	s->Draw();

	data->window.display();
}

void MusicState::CreateMusicOptionsButtons()
{
	menu.setSize({ WIDTH / 2, 50 });
	menu.setFillColor(sf::Color(0x9e9e9eff));
	menu.setOutlineThickness(4);
	menu.setOutlineColor(sf::Color::Black);
	menu.setPosition(WIDTH / 4, 175);

	menuText.setFont(data->assets.GetFont("standardFont"));
	menuText.setCharacterSize(40);
	menuText.setFillColor(sf::Color::Black);
	menuText.setString("menu:");
	menuText.setPosition({ WIDTH / 4 + 10, 175 });

	s = new ScrollBar({ WIDTH / 2, 250 }, WIDTH / 4, 101, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window);
}
