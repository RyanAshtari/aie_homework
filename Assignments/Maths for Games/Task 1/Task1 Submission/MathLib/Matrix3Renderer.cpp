#include "MathLib/Matrix3Renderer.h"

#include <iomanip>
#include <ranges>
#include <sstream>
#include <utility>

#include "MathLib/MathFunctions.h"

using std::stringstream;

namespace MathLib
{
	Matrix3Renderer::ExtraInfoActions::ExtraInfoActions(string text, function<void()> onScroll)
		: text{ std::move(text) }, onScroll{ std::move(onScroll) }
	{
	}

	Matrix3Renderer::MatrixProps::MatrixProps(string name)
		: mouseOver{ false }, m_name{ std::move(name) }
	{
	}

	Matrix3Renderer::Matrix3Renderer(Vec2 screenSize, Vec2 unitSize)
		: m_screenSize{ std::move(screenSize) }, m_unitSize{ std::move(unitSize) }
	{
	}

	Matrix3Renderer::~Matrix3Renderer()
	{
		for (const auto& prop : m_properties | std::views::values)
		{
			delete prop;
		}

		m_properties.clear();
		m_matrices.clear();

		m_renderQueue.clear();
		m_uiRenderQueue.clear();
	}

	void Matrix3Renderer::BeginRender()
	{
		m_renderQueue.clear();
		m_uiRenderQueue.clear();
		m_matrices.clear();
	}

	void Matrix3Renderer::EndRender() const
	{
		DrawGrid();

		for (auto& action : m_renderQueue)
		{
			action();
		}

		for (auto& action : m_uiRenderQueue)
		{
			action();
		}
	}

	void Matrix3Renderer::DrawMatrix(const string& name, Mat3& mat, Color color, const Vec2& textAreaEditPos)
	{
		m_matrices[name] = mat;

		if (!m_properties.contains(name))
		{
			m_properties[name] = new MatrixProps(name);
		}

		m_renderQueue.emplace_back([mat, name, color, this]
			{
				const Vec2 origin = m_screenSize * .5f;

				const Vec2 xa = Vec2{ mat.m1, mat.m2 * -1.f } *m_unitSize.x;
				const Vec2 ya = Vec2{ mat.m4, mat.m5 * -1.f } *m_unitSize.y;
				const Vec2 za = Vec2{ mat.m7 * m_unitSize.x, mat.m8 * -1.f * m_unitSize.y };

				const float thickness = m_properties[name]->mouseOver ? 3.f : 2.f;

				DrawArrow(origin + za, origin + za + xa, thickness, color);
				DrawArrow(origin + za, origin + za + ya, thickness, color);
			});

		m_uiRenderQueue.emplace_back([&, name, this]
			{
				DrawMatrixEditAreaUI(name, textAreaEditPos, mat, color);
			});
	}

	void Matrix3Renderer::DrawPoint(const Vec2& point, Color color, float size)
	{
		m_renderQueue.emplace_back([point, size, color, this]
			{
				const Vec2 origin = m_screenSize * .5f;

				const Vec2 p =
				{
					origin.x + point.x * m_unitSize.x,
					origin.y + point.y * m_unitSize.y * -1.f
				};

				DrawCircleV(p, size, color);
			});
	}

	Mat3 Matrix3Renderer::GetMatrix(const string& name)
	{
		if (m_matrices.contains(name))
		{
			return m_matrices[name];
		}

		return {};
	}

	void Matrix3Renderer::DrawArrow(const Vec2& p1, const Vec2& p2, const float thickness, Color color)
	{
		const Vec2 dir = Vec2::Normalised(p2 - p1) * (5.f + (thickness - 1.f));
		const Vec2 pDir = { dir.y, -dir.x };

		DrawLineEx(p1, p2, thickness, color);
		DrawTriangle(p2, p2 - dir + pDir, p2 - dir - pDir, color);
	}

	string Matrix3Renderer::GetMatrixName(const Mat3& mat)
	{
		// Identity check - all values must match
		if (MathFunctions::Compare(mat.m1, 1) && MathFunctions::Compare(mat.m2, 0) && MathFunctions::Compare(mat.m3, 0) &&
			MathFunctions::Compare(mat.m4, 0) && MathFunctions::Compare(mat.m5, 1) && MathFunctions::Compare(mat.m6, 0) &&
			MathFunctions::Compare(mat.m7, 0) && MathFunctions::Compare(mat.m8, 0) && MathFunctions::Compare(mat.m9, 1))
		{
			return "Identity";
		}

		// Scale Matrix
		// m1 and m5 can be anything, the rest have to be same
		// as identity
		if (MathFunctions::Compare(mat.m2, 0) && MathFunctions::Compare(mat.m3, 0) &&
			MathFunctions::Compare(mat.m4, 0) && MathFunctions::Compare(mat.m6, 0) &&
			MathFunctions::Compare(mat.m7, 0) && MathFunctions::Compare(mat.m8, 0) && MathFunctions::Compare(mat.m9, 1))
		{
			return "Scale";
		}

		// Translation Matrix
		// m7 and m8 can be anything, the rest have to be same
		// as identity
		if (MathFunctions::Compare(mat.m1, 1) && MathFunctions::Compare(mat.m2, 0) && MathFunctions::Compare(mat.m3, 0) &&
			MathFunctions::Compare(mat.m4, 0) && MathFunctions::Compare(mat.m5, 1) && MathFunctions::Compare(mat.m6, 0) &&
			MathFunctions::Compare(mat.m9, 1))
		{
			return "Translation";
		}

		// Rotation Matrix
		// length of x and y-axis must be 1
		// x and y-axis must be perpendicular (calculated via dot product);
		const float xaLen = sqrtf(mat.m1 * mat.m1 + mat.m2 * mat.m2);
		const float yaLen = sqrtf(mat.m4 * mat.m4 + mat.m5 * mat.m5);
		const float dot = mat.m1 * mat.m4 + mat.m2 * mat.m5;
		if (MathFunctions::Compare(dot, 0) && MathFunctions::Compare(xaLen, 1) && MathFunctions::Compare(yaLen, 1) &&
			MathFunctions::Compare(mat.m3, 0) && MathFunctions::Compare(mat.m6, 0) &&
			MathFunctions::Compare(mat.m7, 0) && MathFunctions::Compare(mat.m8, 0) && MathFunctions::Compare(mat.m9, 1))
		{
			const string deg = FloatStringPrecise(atan2f(mat.m2, mat.m1) * 180.0f / PI, 2);

			return "Rotation (" + deg + ")";
		}

		// any other configuration...
		// than it's just a "transform" matrix
		return "Transform";
	}

	bool Matrix3Renderer::IsPointInRect(const Vec2& vec, const Rectangle rect)
	{
		return vec.x >= rect.x && vec.x < rect.x + rect.width && vec.y >= rect.y && vec.y < rect.y + rect.height;
	}

	void Matrix3Renderer::RotateVector(const float amount, float& x, float& y)
	{
		const float xRotated = x * cosf(amount) - y * sinf(amount);
		const float yRotated = x * sinf(amount) + y * cosf(amount);

		x = xRotated;
		y = yRotated;
	}

	string Matrix3Renderer::FloatStringPrecise(const float val, const int precision)
	{
		stringstream stream;

		stream << std::fixed << std::setprecision(precision) << val;

		return stream.str();
	}

	void Matrix3Renderer::DrawGrid() const
	{
		const Vec2 centerPos = m_screenSize * .5f;
		constexpr Color col = LIGHTGRAY;

		// Horizontal Lines
		const int numRows = static_cast<int>(m_screenSize.y / m_unitSize.y);
		const int hNumRows = numRows / 2 + 1;
		for (int i = -hNumRows; i < hNumRows; ++i)
		{
			const float thickness = static_cast<float>(i == 0 ? 2 : 1);
			const float yOffset = centerPos.y + static_cast<float>(i) * m_unitSize.y;

			DrawLineEx({ 0, yOffset }, { m_screenSize.x, yOffset }, thickness, col);
		}

		// Vertical Lines
		const int numCols = static_cast<int>(m_screenSize.x / m_unitSize.x);
		const int hNumCols = numCols / 2 + 1;
		for (int i = -hNumCols; i < hNumCols; ++i)
		{
			const float thickness = static_cast<float>(i == 0 ? 2 : 1);
			const float xOffset = centerPos.x + static_cast<float>(i) * m_unitSize.x;

			DrawLineEx({ xOffset, 0 }, { xOffset, m_screenSize.y }, thickness, col);
		}
	}

	void Matrix3Renderer::DrawMatrixEditAreaUI(const string& name, const Vec2& pos, Mat3& mat, Color color)
	{
		MatrixProps* props = m_properties[name];

		const Vec2 mousePos = { GetMousePosition().x, GetMousePosition().y };

		constexpr int TW = 40;
		constexpr int TH = 20;

		// List of Extra stuff to displaying in the UI
		const list<ExtraInfoActions> extraInfo = GetExtraInfoActions(name, mat.data, mat);

		// Draw Title bg rectangle
		// Draw MatrixComponents rectangle
		// Draw Extra Info Rectangle
		//===============================================================
		const Rectangle titleRect = { pos.x, pos.y, TW * 3, 15 };
		const Rectangle matRect = { pos.x, pos.y + 15, TW * 3, TH * 3 };
		const Rectangle extraRect = { matRect.x, matRect.y + matRect.height, matRect.width, static_cast<float>(extraInfo.size()) * 15 + 5 };
		const Rectangle fullRect = { titleRect.x, titleRect.y, titleRect.width, titleRect.height + matRect.height + extraRect.height };

		// draw box for title
		DrawRectangleRec(titleRect, DARKGRAY);
		DrawText(name.c_str(), static_cast<int>(titleRect.x) + 5, static_cast<int>(titleRect.y) + 2, 10, RAYWHITE);

		// draw the box where our matrix values go
		Color matBgColor = color;
		matBgColor.a = 16;
		DrawRectangleRec(matRect, WHITE);
		DrawRectangleRec(matRect, matBgColor);

		// draw box for the extra info
		DrawRectangleRec(extraRect, GRAY);
		DrawRectangleLinesEx(fullRect, 1, DARKGRAY);
		//===============================================================

		props->mouseOver = IsPointInRect(mousePos, fullRect);

		// draw the text for each matrix value
		// ==============================================================
		for (int i = 0; i < MAT_3_SIZE; ++i)
		{
			const int yId = i % 3;
			const int xId = i / 3;
			const int xPos = xId * TW + static_cast<int>(matRect.x) + 6;
			const int yPos = yId * TH + static_cast<int>(matRect.y) + 6;
			DrawText(FloatStringPrecise(mat.data[i], 3).c_str(), xPos, yPos, 10, GRAY);
		}
		// ==============================================================

		// draw the highlight box over the element the mouse is sitting over
		if (IsPointInRect(mousePos, matRect))
		{
			// convert mouse pos to Row/Col index
			// should give value between 0 and 3 because were only working with 3x3 matrix.
			const int mpxId = static_cast<int>((mousePos.x - matRect.x)) / TW;
			const int mpyId = static_cast<int>((mousePos.y - matRect.y)) / TH;
			const int mpIndex = mpxId * 3 + mpyId;

			// draw colored box over the value that the mouse is over.
			DrawRectangle(
				mpxId * TW + static_cast<int>(matRect.x),
				mpyId * TH + static_cast<int>(matRect.y),
				TW,
				TH,
				{
					color.r,
					color.g,
					color.b,
					64
				}
			);

			// Draw the variable name, col and row in the title
			// might be useful for debugging
			const string indexText = "M{" + std::to_string(mpIndex + 1) + "}:[{" + std::to_string(mpxId) + "},{" + std::to_string(mpyId) + "}]";
			const int indexTextWidth = MeasureText(indexText.c_str(), 10);
			DrawText(
				indexText.c_str(),
				static_cast<int>(titleRect.x + titleRect.width) - indexTextWidth - 10,
				static_cast<int>(titleRect.y + 3),
				10,
				RAYWHITE
			);

			// if the mouse wheel has scrolled update the matrix
			if (GetMouseWheelMove() != 0.0f)
			{
				mat.data[mpxId * 3 + mpyId] -= GetMouseWheelMove() * 0.1f;
				ModifyMatrix(name, mat.data, mat);
			}
		}

		// loop through the extra info list, draw and handle input
		constexpr int ITEM_HEIGHT = 15;
		for (int i = 0; i < static_cast<int>(extraInfo.size()); i++)
		{
			const Rectangle itemRect = 
			{
				extraRect.x,
				extraRect.y + static_cast<float>(i * ITEM_HEIGHT),
				extraRect.width,
				ITEM_HEIGHT
			};
			
			auto iter = extraInfo.begin();
			std::advance(iter, i);

			// is the mouse within the rect bounds
			if (IsPointInRect(mousePos, itemRect))
			{
				// draw box to show mouse hover
				DrawRectangleRec(itemRect, DARKGRAY);

				// call the items onScroll method when mouse wheel moves.
				if (GetMouseWheelMove() != 0.0f)
					iter->onScroll();
			}

			DrawText(
				iter->text.c_str(), 
				static_cast<int>(extraRect.x) + 10, 
				static_cast<int>(itemRect.y) + 3, 
				10, 
				RAYWHITE
			);
		}
	}

	void Matrix3Renderer::ModifyMatrix(const string& name, const float* arr, Mat3& mat)
	{
		mat.m1 = arr[0];
		mat.m2 = arr[1];
		mat.m3 = arr[2];
		mat.m4 = arr[3];
		mat.m5 = arr[4];
		mat.m6 = arr[5];
		mat.m7 = arr[6];
		mat.m8 = arr[7];
		mat.m9 = arr[8];

		m_matrices[name] = mat;
	}

	list<Matrix3Renderer::ExtraInfoActions> Matrix3Renderer::GetExtraInfoActions(const string& name, float* arr, Mat3& mat)
	{
		list<ExtraInfoActions> extraInfo;

		extraInfo.emplace_back(
			GetMatrixName(mat),
			[&, this]
			{
				const string text = GetMatrixName(mat);
				if (!text.starts_with("Rotation"))
					return;

				const float scrollVal = GetMouseWheelMove();
				RotateVector(scrollVal * .01f, arr[0], arr[1]);
				RotateVector(scrollVal * .01f, arr[3], arr[4]);
				ModifyMatrix(name, arr, mat);
			}
		);

		extraInfo.emplace_back(
			"x scale: " + FloatStringPrecise(Vec2{ mat.m4, mat.m5 }.Magnitude(), 3),
			[&, this]
			{
				const float len = sqrtf(arr[0] * arr[0] + arr[1] * arr[1]);
				if (!(len > 0))
					return;

				const float scrollVal = GetMouseWheelMove();
				arr[0] += arr[0] / len * scrollVal * 0.1f;
				arr[1] += arr[1] / len * scrollVal * 0.1f;
				ModifyMatrix(name, arr, mat);
			}
		);

		extraInfo.emplace_back(
			"x scale: " + FloatStringPrecise(Vec2{ mat.m4, mat.m5 }.Magnitude(), 3),
			[&, this]
			{
				const float len = sqrtf(arr[3] * arr[3] + arr[4] * arr[4]);
				if (!(len > 0))
					return;

				const float scrollVal = GetMouseWheelMove();
				arr[3] += arr[3] / len * scrollVal * 0.1f;
				arr[4] += arr[4] / len * scrollVal * 0.1f;
				ModifyMatrix(name, arr, mat);
			}
		);

		return extraInfo;
	}
}
