#include "MathLib/Scene/SpriteObject.h"

namespace MathLib
{
	SpriteObject::SpriteObject(Texture2D* texture)
		: tint{ 0xffffffff }, origin{ .5f, .5f }, m_texture{ texture }
	{
		ApplyTransform(Mat3::MakeScale(1.f, 1.f));
	}

	SpriteObject::~SpriteObject()
	{
		m_texture = nullptr;
	}

	Texture2D* SpriteObject::GetTexture() const
	{
		return m_texture;
	}

	void SpriteObject::OnRender()
	{
		if (m_texture != nullptr)
		{
			Mat3 gt = Global();
			Vec2 location = gt.GetTranslation();
			Vec2 scale = gt.GetScale();
			float rot = gt.GetRotationX() * RAD2DEG;

			// src = the rectangle on the actual texture that we want to render
			Rectangle src =
			{
				0,
				0,
				static_cast<float>(m_texture->width),
				static_cast<float>(m_texture->height)
			};

			// dst = the rectangle that will be used to draw the texture on the screen
			Rectangle dst =
			{
				location.x,
				location.y,
				scale.x,
				scale.y
			};

			DrawTexturePro(*m_texture, src, dst, origin * scale, rot, tint);
		}
	}
}
