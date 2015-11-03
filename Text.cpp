#include "Text.h"
//Text::Text()
//	: Sprite()
//	, font(nullptr)
//	, size(12)
//	, style(0)
//	, isVisible(true)
//	, path(nullptr)
//	, message(nullptr)
//{
//}
//Text::~Text()
//{
//	TTF_CloseFont(font);
//	size = 0;
//	style = 0;
//	isVisible = false;
//	TTF_CloseFont(font);
//	path = nullptr;
//	message = nullptr;
//}
//Text::Text(const std::string& path, int style, const std::string& message)
//	: Sprite()
//	, font(0)
//	, size(12)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int x, int y)
//	: Sprite()
//	, font(0)
//	, size(12)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(x, y);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, Vector2D position)
//	: Sprite()
//	, font(0)
//	, size(12)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(position);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size)
//	: Sprite()
//	, font(0)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size, int x, int y)
//	: Sprite()
//	, font(0)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(x, y);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size, Vector2D position)
//	: Sprite()
//	, font(0)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(position);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size, SDL_Color color)
//	: Sprite()
//	, font(0)
//	, color(color)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetColor(WHITE);
//
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size, SDL_Color color, int x, int y)
//	: Sprite()
//	, font(0)
//	, color(color)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(x, y);
//	SetColor(WHITE);
//}
//Text::Text(const std::string& path, int style, const std::string& message, int size, SDL_Color color, Vector2D position)
//	: Sprite()
//	, font(0)
//	, color(color)
//	, size(size)
//	, style(style)
//	, isVisible(true)
//	, path(path)
//	, message(message)
//{
//	PrintTextTexture(message);
//	SetPosition(position);
//	SetColor(WHITE);
//}
//
//SDL_Texture* Text::CreateTexture(const std::string& message, SDL_Color color)
//{
//	SDL_Surface* surf = TTF_RenderText_Blended(font, message.c_str(), color);
//	if (surf == nullptr){
//		TTF_CloseFont(font);
//		std::cout << "Failed to create surface: " << surf << " -- " << TTF_GetError();
//		return nullptr;
//	}
//	SDL_Renderer* renderer = Engine::GetInstance()->GetRenderer();
//	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
//	if (texture == nullptr){
//		std::cout << "Failed to create text texture: " << texture << " -- " << TTF_GetError();
//	}
//	//Clean up the surface and font
//	SDL_FreeSurface(surf);
//	return texture;
//}
//void Text::PrintTextTexture(const std::string& message)
//{
//	if (font == nullptr)
//	{
//		font = Engine::GetInstance()->GetResources()->GetFont(path, size);
//	}
//	TTF_SetFontStyle(font, style);
//	SDL_Texture* textTexture = CreateTexture(message, color);
//	SetTexture(textTexture);
//}