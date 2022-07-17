#ifndef VERTEX_H
#define VERTEX_H

#include "../common.h"

#pragma pack(1)
struct Vertex {
	QVector3D position;
	QVector3D normal;
	QVector2D uv;
};

#endif // !VERTEX_H