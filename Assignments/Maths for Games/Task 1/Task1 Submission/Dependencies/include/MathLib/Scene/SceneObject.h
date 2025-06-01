#pragma once

#include <functional>
#include <vector>

#include "MathLib/Types/Mat3.h"

using std::function;
using std::vector;

// The Inferior SceneObject
namespace MathLib
{
	class SceneObject
	{
	public:
		SceneObject();
		virtual ~SceneObject();

	public:
		void Tick(float dt);
		void Render();

		SceneObject* Parent() const;
		void SetParent(SceneObject* newParent);

		/*
		 * Returns the global transform in the scene graph.
		 */
		Mat3 Global();
		/*
		 * Returns the current object's local transform.
		 */
		Mat3 Local();
		void ApplyTransform(const Mat3& transform);

	protected:
		Mat3 m_transform;

	protected:
		virtual void OnTick(float dt);
		virtual void OnRender();

		void ApplyListChanges();

	private:
		vector<function<void()>> m_childListChanges;

		vector<SceneObject*> m_children;
		SceneObject* m_parent;

	private:
		void AddChild(SceneObject* child);
		void RemoveChild(SceneObject* child);

	};
}