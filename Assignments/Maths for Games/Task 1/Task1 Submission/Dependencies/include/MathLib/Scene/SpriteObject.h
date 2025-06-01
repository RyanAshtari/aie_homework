#pragma once

#include "SceneObject.h"

#include "MathLib/Types/Color.h"

#include <raylib/raylib.h>

namespace MathLib
{
	class SpriteObject : public SceneObject
	{
	public:
		Color tint;
		Vec2 origin;

	public:
		SpriteObject(Texture2D* texture);
		~SpriteObject();

	public:
		Texture2D* GetTexture() const;

	protected:
		void OnRender() override;

	private:
		Texture2D* m_texture;

	};
}