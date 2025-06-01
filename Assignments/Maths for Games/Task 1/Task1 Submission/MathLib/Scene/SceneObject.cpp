#include "MathLib/Scene/SceneObject.h"

// The Inferior SceneObject
namespace MathLib
{
	SceneObject::SceneObject()
		: m_transform{ Mat3::MakeIdentity() }, m_parent{ nullptr }
	{
	}

	SceneObject::~SceneObject()
	{
		for (SceneObject* child : m_children)
		{
			delete child;
		}

		m_children.clear();

		if (m_parent != nullptr)
		{
			m_parent->RemoveChild(this);
			m_parent->ApplyListChanges();
		}

	}

	void SceneObject::Tick(float dt)
	{
		// Run the object's tick logic.
		OnTick(dt);

		// Apply any changes to the transform hierarchy.
		ApplyListChanges();

		// Tick each child.
		for (SceneObject* child : m_children)
		{
			child->Tick(dt);
		}
	}

	void SceneObject::Render()
	{
		// Run this object's render logic.
		OnRender();

		// Render each child.
		for (SceneObject* child : m_children)
		{
			child->Render();
		}
	}

	SceneObject* SceneObject::Parent() const
	{
		return m_parent;
	}

	void SceneObject::SetParent(SceneObject* newParent)
	{
		// Are we un-parented this object?
		if (newParent == nullptr)
		{
			// Do we actually have a parent?
			if (m_parent != nullptr)
			{
				m_parent->RemoveChild(this);
			}
		}

		else
		{
			newParent->AddChild(this);
		}
	}

	Mat3 SceneObject::Global()
	{
		return m_parent != nullptr ? Local() * m_parent->Global() : Local();
	}

	Mat3 SceneObject::Local()
	{
		return m_transform;
	}

	void SceneObject::ApplyTransform(const Mat3& transform)
	{
		m_transform = transform * m_transform;
	}

	void SceneObject::OnTick(float dt) { }

	void SceneObject::OnRender() { }

	void SceneObject::ApplyListChanges()
	{
		for (auto& change : m_childListChanges)
		{
			change();
		}

		m_childListChanges.clear();
	}

	void SceneObject::AddChild(SceneObject* child)
	{
		m_childListChanges.emplace_back([child, this]
			{
				if (child->m_parent != nullptr)
				{
					child->m_parent->RemoveChild(child);
					child->m_parent->ApplyListChanges();
				}

				child->m_parent = this;
				m_children.emplace_back(child);
			}
		);
	}

	void SceneObject::RemoveChild(SceneObject* child)
	{
		m_childListChanges.emplace_back([child, this]
			{
				if (child->m_parent == this)
				{
					child->m_parent = nullptr;
					m_children.erase(std::ranges::find(m_children, child));
				}
			}
		);
	}
}
