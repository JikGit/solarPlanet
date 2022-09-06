#include <iostream>
#include <SFML/Graphics.hpp>

struct Planet
{
	float mass; // misurata in ME (eaarh mass)
	float distanceX; // misurata in AU
	float radius; //misurato in raggi terrestri
	float velY; // misurata in km/s
	sf::Color color;

	Planet(float mass1, float distanceX1, float radius1, float velY1, sf::Color color1){
		mass = mass1;
		distanceX = distanceX1;
		radius = radius1;
		velY = velY1;
		color = color1;
	}

};


const int WIDTH = 900, HEIGHT = 900;
const int N_PLANET = 5;

void displayPlanet(sf::RenderWindow &, Planet [N_PLANET]);

int main()
{

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "titolo", sf::Style::Close | sf::Style::Resize); //creo variabile window, con titolo, grandezza, style
	Planet list[N_PLANET] = {
		/* {332.950, 0, 109, 0, sf::Color::Red}, //sun */
		{332.950, 0, 10, 0, sf::Color::Red}, //sun
		{0.055, 0.4, 0.3829, 47.87, sf::Color{220, 220, 220, 255}}, //mercury
		{0.815, 0.723, 0.9499, 35.02, sf::Color::Yellow}, //Venus
		{1, 0.4, 1, 29.78, sf::Color::Blue}, //earth
		{0.107, 0.4, 1.5, 5.027, sf::Color{255, 165, 0, 255}}, //mars
	};

	
	while (window.isOpen())
	{
		sf::Event evnt; //creo una variabile contente gli eventi
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				case sf::Event::Closed: //evento chiuso app
					window.close();
					break;
				default:
					break;
			}
		}
		//ridipingo lo schermo
		window.clear(sf::Color::Black);

		displayPlanet(window, list);

		//aggiorno lo schermo
		window.display();

	}

}

void displayPlanet(sf::RenderWindow &window, Planet list[N_PLANET]){
	for (int index = 0; index < N_PLANET; index++){
		sf::CircleShape circle(list[index].radius * 10);
		circle.setFillColor(list[index].color);
		circle.setPosition(sf::Vector2f(list[index].distanceX*100 + WIDTH/2 - list[index].radius * 10, HEIGHT/2 - list[index].radius * 5));
		window.draw(circle);
	}

}
