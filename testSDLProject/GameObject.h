#pragma once
#include "IObject.h"
#include "Transform.h"
#include <string>
#include <SDL.h>
struct Properties
{
public: 
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
	{
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}

	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};
class GameObject : public IObject
{
public : 
	GameObject(Properties* props) : m_TextureID(props->TextureID), m_Width(props->Width) , m_Height(props->Height) , m_Flip(props->Flip)  {
		m_Transform = new Transform(props->X, props->Y);
	}
	
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual void Clean() = 0;

protected :
	int m_Width, m_Height;
	Transform* m_Transform;
    std::string m_TextureID;
	SDL_RendererFlip m_Flip;


};