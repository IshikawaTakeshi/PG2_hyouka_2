#pragma once
#include "Vector2.h"
#define USE_MATH_DEFINES
#include <math.h>
#include <assert.h>

//3x3の行列
struct Matrix3x3 {
	float m[3][3];
};

//行列の積
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	Matrix3x3 result = { 0 };
	for (int r = 0; r < 3; r++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.m[r][i] += matrix1.m[r][j] * matrix2.m[j][i];
			}
		}
	}
	return result;
}

//回転行列の作成関数
Matrix3x3 MakeRotateMatrix(float theta) {
	Matrix3x3 result = {
	static_cast<float>(cos(theta)),
	static_cast<float>(sin(theta)),
	0,
	static_cast<float>(-sin(theta)),
	static_cast<float>(cos(theta)),
	0,

	0,0,1.0f,
	};
	return result;
}

//平行移動行列の作成関数
Matrix3x3 MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 result = {
		1.0f,0,0,
		0,1.0f,0,
		translate.x,translate.y,1.0f
	};

	return result;
}
//アフィン行列
Matrix3x3 MakeAffineMatrix(Vector2 scale, float theta, Vector2 translate) {
	Matrix3x3 result = {
		scale.x * static_cast<float>(cos(theta)),
		scale.x * static_cast<float>(sin(theta)),
		0,
		-scale.y * static_cast<float>(sin(theta)),
		scale.y * static_cast<float>(cos(theta)),
		0,
		translate.x,
		translate.y,
		1.0f,
	};
	return result;
}

//2次元ベクトルを同次座標系として変換する関数
Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}