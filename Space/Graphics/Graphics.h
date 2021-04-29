#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <Geometry.h>
#include <ImageController.h>
// SFML
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <string>

#include <Color.h>


class Graphics {
private:

	unsigned int width = 0;
	unsigned int height = 0;

	sf::RenderWindow* win = nullptr;

public:
	static Graphics* instance(){
    	static Graphics inst;
    	return &inst;
	}	

	void createWindow(unsigned int width, unsigned int height);
	void render();
	Vector2D getWinSize();
	sf::RenderWindow* getWindow();


	class DrawObject {
	private:
		Point2D position;
		Vector2D scale;
		float angle;
		sf::RectangleShape shape;
		sf::Transform transform;
		sf::Color color;
		sf::Text text;
		std::string s;
		sf::Font font;
		ImageType img;
		float size = 1;
	public:
		static DrawObject* instance(){
    		static DrawObject inst;
    		return &inst;
		}

		Graphics::DrawObject* setPosition(
			const Point2D& pos
		);
		Graphics::DrawObject* setScale(
			const Vector2D& sc
		);
		Graphics::DrawObject* setAngle(
			const float angle
		);
		Graphics::DrawObject* setColor(
			const sf::Color& col
		);
		Graphics::DrawObject* setString(
			const std::string& col
		);
		Graphics::DrawObject* setImage(
			const ImageType& img
		);
		Graphics::DrawObject* setFont(
			const sf::Font& font
		);
		Graphics::DrawObject* setSize(
			const float& sz
		);

		void drawRectangle();
		void drawText();
		void drawImage();
	};

	class Image {
	private:
		sf::Image img;
	public:
		sf::Image getImage();
		bool loadFromFile(const std::string& path);
	};

	class Font {
	private:
		sf::Font font;
	public:
		sf::Font getFont();
		void loadFromFile(const std::string& path);

	};

	
};

#endif