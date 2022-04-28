#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <time.h>
#include "map.h"
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;
using namespace sf;

const int HEIGHT = 22; // ВЫСОТА ПОЛЯ
const int WIDTH = 10; // ШИРИНА ПОЛЯ

//ИГРОВОЕ ПОЛЕ
int pole[HEIGHT + 1][WIDTH] = { 0 }; 

int score = 0;
int level = 0;

// ВИДЫ ФИГУР
int tetramino[7][4] =
{
	1,3,5,7, 
	2,4,5,7, 
	3,5,4,6, 
	3,5,4,7, 
	2,3,5,7, 
	3,5,7,6, 
	2,3,4,5, 
};

struct Point
{
	int x, y;
} coordinate[4], coordinatePrev[4];

// ПРОВЕРКА НА ГРАНИЦЫ
bool check()
{
	for (int i = 0; i < 4; i++)
		if (coordinate[i].x < 1 || coordinate[i].x >= WIDTH || coordinate[i].y >= HEIGHT+1) return 0;
		else if (pole[coordinate[i].y][coordinate[i].x]) return 0;

	return 1;

};


int main()
{	
	bool game = true;
	bool timercontinue = true;

	string strh,strh2;
	string str = "";
	string str2 = "";
	ifstream fin("bestScore.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, strh);
			str += strh;
			str += ' ';
			if (!fin.eof())
				str += "\n";
		}
		fin.close();
	}
	int bestScore = stoi(str);

	ifstream fin2("bestTime.txt");
	if (fin2.is_open()) {
		while (!fin2.eof()) {
			getline(fin2, strh2);
			str2 += strh2;
			str2 += ' ';
			if (!fin.eof())
				str += "\n";
		}
		fin2.close();
	}
	int bestTime = stoi(str2);

	//ТЕКСТ
	Font font;
	font.loadFromFile("etna.otf");
	Text text("", font, 20);
	text.setColor(Color::Black);
	Text text1("", font, 70);
	text1.setColor(Color::Red);
	

	srand(time(0));

	RenderWindow window(VideoMode(500, 720), "GAME");

	// ТЕКСТУРЫ
	Texture texture,texture_button;
	texture.loadFromFile("tiles.png");
	texture_button.loadFromFile("button.png");

	Sprite cub(texture),sprite_button(texture_button);

	// СПРАЙТЫ
	cub.setTextureRect(IntRect(0, 0, 18, 18));
	sprite_button.setTextureRect(IntRect(33, 19, 82, 30));

	// ГОРИЗОНТАЛЬНОЕ ПЕРЕМЕЩЕНИЕ
	int dx = 0; bool rotate = 0; int color = 1; bool startGame = true; int n = rand() % 7;

	float timer = 0, timeForMove = 0.3;
	int timee2 = 0;
	int gameTimer = 0;
	
	Clock clock,gameClock;


	// ПОКА ОТКРЫТО ОКНО
	while (window.isOpen())
	{
		
			// ПОЛУЧАЕМ ПРОШЕДШЕЕ ВРЕМЯ
			float timee = clock.getElapsedTime().asSeconds();
			if (timercontinue) {
				timee2 = gameClock.getElapsedTime().asSeconds();
			}
			clock.restart();
			timer += timee;
			
			Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора

			Event event;
			while (window.pollEvent(event))
			{
				
				if (event.type == Event::Closed)
					

					window.close();

				// Была нажата кнопка на клавиатуре?
				if (event.type == Event::KeyPressed) {
					
					if (event.key.code == Keyboard::Up) rotate = true;
					
					else if (event.key.code == Keyboard::Left) dx = -1;
					
					else if (event.key.code == Keyboard::Right) dx = 1;
				}
				if (event.type == Event::MouseButtonPressed) {
					if (event.key.code == Mouse::Left)
						if (sprite_button.getGlobalBounds().contains(pixelPos.x, pixelPos.y)) {
							std::cout << "Restart\n";
							window.close();
							system("C:\\Users\\artem\\source\\repos\\kursach_2.0\\x64\\Debug\\kursach_2.0.exe");

								
						}
				}
			}

			// УСКОРЕНИЕ ПО КНОПКЕ ВНИЗ
			if (Keyboard::isKeyPressed(Keyboard::Down)) 
				timeForMove = 0.05;

			//// ГОРИЗОНТАЛЬНОЕ ПЕРЕМЕЩЕНИЕ
			for (int i = 0; i < 4; i++)
			{
				coordinatePrev[i] = coordinate[i]; coordinate[i].x += dx; 
			}

			// ПРОВЕРКА НА ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ
			if (!check()) for (int i = 0; i < 4; i++) {
				coordinate[i] = coordinatePrev[i];
			}

			if (rotate)
			{
				Point p = coordinate[1]; // центр вращения
				for (int i = 0; i < 4; i++)
				{
					int x = coordinate[i].y - p.y;
					int y = coordinate[i].x - p.x; 
					coordinate[i].x = p.x - x;
					coordinate[i].y = p.y + y;
				}
				// ПРОВЕРКА НА ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ
				if (!check()) 
				{ 
					for (int i = 0; i < 4; i++) {
						coordinate[i] = coordinatePrev[i];
					}
				}

			}

			//// ДВИЖЕНИЕ ФИГУРОК ВНИЗ ПО ВРЕМЕНИ
			if (timer > timeForMove)
			{
				for (int i = 0; i < 4; i++) { coordinatePrev[i] = coordinate[i]; coordinate[i].y += 1; }
				if (!check())
				{
					for (int i = 0; i < 4; i++) pole[coordinatePrev[i].y][coordinatePrev[i].x] = color;
					color = 1 + rand() % 7;
					n = rand() % 7;
					for (int i = 0; i < 4; i++)
					{
						coordinate[i].x = tetramino[n][i] % 2 + 4;
						coordinate[i].y = tetramino[n][i] / 2 + 1;
					}

				}
				timer = 0;

			}

			//СЪЕДАНИЕ РЯДОВ
			int k = HEIGHT;

			for (int i = HEIGHT; i > 0; i--)
			{

				int count = 0;
				for (int j = 0; j < WIDTH; j++)
				{
					if (pole[i][j]) {
						count++;
					}
					pole[k][j] = pole[i][j];

					if (count == 9) {
						score++;
						level++;
					}
				}
				if (count < WIDTH - 1) {
					k--;
				}
			}

			// НАЧАЛО ИГРЫ
			if (startGame)
			{
				startGame = false;
				n = rand() % 7;

				for (int i = 0; i < 4; i++)
				{
					coordinate[i].x = tetramino[n][i] % 2 + 4;
					coordinate[i].y = tetramino[n][i] / 2 + 1;
				}
			}
			dx = 0; rotate = 0;


			
			window.clear(Color::White);

			//ОТРСИСОВЫВАЕМ ПОЛЕ
			for (int i = 0; i < HEIGHT + 2; i++)
				for (int j = 0; j < WIDTH + 1; j++)
				{
					if (TileMap[i][j] == ' ')  cub.setTextureRect(IntRect(162, 0, 18, 18));

					if ((TileMap[i][j] == '0')) cub.setTextureRect(IntRect(144, 0, 18, 18));


					cub.setPosition(j * 18, i * 18);

					window.draw(cub);
				}

			//РИСУЕМ НИЖНИЕ СТОЯЧИЕ ФИГУРКИ			
				for (int i = 0; i < HEIGHT + 1; i++) {
					for (int j = 0; j < WIDTH; j++)
					{
						if (pole[i][j] == 0) continue;
						cub.setTextureRect(IntRect(pole[i][j] * 18, 0, 18, 18));
						cub.setPosition(j * 18, i * 18);
						if (i == 5) {
							game = false;
							timercontinue = false;
							
							if (Keyboard::isKeyPressed(Keyboard::Enter))
							{		
								cout << "new game\n";
								window.close();
								system("C:\\Users\\artem\\source\\repos\\kursach_2.0\\x64\\Debug\\kursach_2.0.exe");
												
							}
						}
						if (game) {
							window.draw(cub);
						}
					}			
			}
			//РИСУЕМ ФИГРУКИ И КРАСИМ ИХ
			if (game) {
				for (int i = 0; i < 4; i++)
				{
					cub.setTextureRect(IntRect(color * 18, 0, 18, 18));
					cub.setPosition(coordinate[i].x * 18, coordinate[i].y * 18);
					window.draw(cub);
				}
			}

			std::ostringstream scoreString, levelString, bestScoreString, gameTime, bestGameTime;   

			//ОТРИСОВКА УРОВНЯ И СКОРОСТЬ ИГРЫ
			if (level <= 7) {
				levelString << level;
			}
			else if (level > 7) {
				levelString << "MAX LEVEL";
			}
			text.setString("LEVEL : " + levelString.str());
			text.setPosition(280, 0);
			window.draw(text);
			if (level <= 7) {
				timeForMove = 0.3 - level * (0.025 / 2);
			}
			if (level > 7) {
				timeForMove = 0.25;

			}

			//ОТРИСОВКА СЧЕТА
			scoreString << (score);		
			text.setString("SCORE : " + scoreString.str());
			text.setPosition(280, 50);
			window.draw(text);

			//ЛУЧШИЙ СЧЕТ
			if (score > bestScore) {
				bestScore = score;
				ofstream new_bestScore;
				new_bestScore.open("bestScore.txt");
				new_bestScore << bestScore;
				new_bestScore.close();
			}
			bestScoreString << (str);		
			text.setString("BEST SCORE : " + bestScoreString.str());
			text.setPosition(280, 100);
			window.draw(text);

			//ВРЕМЯ В ИГРЕ
			gameTime << (timee2);		
			text.setString("GAME TIME : " + gameTime.str());
			text.setPosition(280, 150);
			window.draw(text);

			//ЛУЧШЕЕ ВРЕМЯ
			if (timee2 > bestTime) {
				bestTime = timee2;
				ofstream new_bestTime;
				new_bestTime.open("bestTime.txt");
				new_bestTime << bestTime;
				new_bestTime.close();
			}
			bestGameTime << (str2);		
			text.setString("BEST TIME : " + bestGameTime.str());
			text.setPosition(280, 200);
			window.draw(text);
			
			//КНОПКА
			sprite_button.setPosition(280, 250);
			window.draw(sprite_button);
			if (!game) {
				window.clear();
				text1.setString("GAME OVER");
				text1.setPosition(50, 150);
				game = false;
				window.draw(text1);
				text1.setString("press ENTER");
				text1.setPosition(50, 340);
				window.draw(text1);
				text1.setString("to play again");
				text1.setPosition(50, 410);
				window.draw(text1);
				
				Text text2("", font, 40);
				text2.setColor(Color::Red);

				text2.setString("GAME TIME : " + gameTime.str());
				text2.setPosition(50, 550);
				window.draw(text2);
				text2.setString("SCORE : " + scoreString.str());
				text2.setPosition(50, 590);
				window.draw(text2);
			}
			// ОКНО
			window.display();
		
	}

	return 0;
}
