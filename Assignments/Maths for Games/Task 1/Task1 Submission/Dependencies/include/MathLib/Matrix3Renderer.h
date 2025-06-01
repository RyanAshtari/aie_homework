#pragma once

#include "MathLib/Types/Vec2.h"
#include "MathLib/Types/Mat3.h"

#include <list>
#include <map>
#include <functional>
#include <string>

using std::list;
using std::map;
using std::function;
using std::string;

namespace MathLib
{
	class Matrix3Renderer
	{
	private:
		class ExtraInfoActions
		{
		public:
			string text;
			function<void()> onScroll;

		public:
			ExtraInfoActions(string text, function<void()> onScroll);

		};

		class MatrixProps
		{
		public:
			bool mouseOver;

		public:
			MatrixProps(string name);

		private:
			string m_name;

		};

	public:
		Matrix3Renderer() = delete;
		Matrix3Renderer(Vec2 screenSize, Vec2 unitSize);

		~Matrix3Renderer();

	public:
		void BeginRender();
		void EndRender() const;

		void DrawMatrix(const string& name, Mat3& mat, Color color, const Vec2& textAreaEditPos);
		void DrawPoint(const Vec2& point, Color color, float size);

		Mat3 GetMatrix(const string& name);

	private:
		Vec2 m_screenSize;
		Vec2 m_unitSize;

		list<function<void()>> m_uiRenderQueue;
		list<function<void()>> m_renderQueue;

		map<string, MatrixProps*> m_properties;
		map<string, Mat3> m_matrices;

	private:
		static void DrawArrow(const Vec2& p1, const Vec2& p2, float thickness, Color color);
		static string GetMatrixName(const Mat3& mat);

		static bool IsPointInRect(const Vec2& vec, Rectangle rect);

		static void RotateVector(float amount, float& x, float& y);
		static string FloatStringPrecise(float val, int precision);

	private:
		void DrawGrid() const;
		void DrawMatrixEditAreaUI(const string& name, const Vec2& pos, Mat3& mat, Color color);

		void ModifyMatrix(const string& name, const float* arr, Mat3& mat);

		list<ExtraInfoActions> GetExtraInfoActions(const string& name, float* arr, Mat3& mat);

	};
}