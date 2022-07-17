#include "../common.h"
#include "model.h"

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

class Cube : public Model {
public:
	Cube(std::string n) : Model(n) {
		std::vector<Vertex> vertices = {
            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(0.0f, 0.0f)}, 
            {QVector3D(0.5f, -0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(1.0f, 0.0f)}, 
            {QVector3D(0.5f, 0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(1.0f, 1.0f)}, 

            {QVector3D(0.5f, 0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(1.0f, 1.0f)}, 
            {QVector3D(-0.5f, 0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(0.0f, 1.0f)}, 
            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(0.0f, 0.0f, -1.0f), QVector2D(0.0f, 0.0f)}, 

            {QVector3D(-0.5f, -0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(0.5f, -0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)}, 
            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)},

            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(-0.5f, 0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 1.0f)},
            {QVector3D(-0.5f, -0.5f, 0.5f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},

            {QVector3D(-0.5f, 0.5f, 0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)},
            {QVector3D(-0.5f, 0.5f, -0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.0f, 1.0f)},

            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.0f, 1.0f)},
            {QVector3D(-0.5f, -0.5f, 0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(-0.5f, 0.5f, 0.5f), QVector3D(-1.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)},

            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)},
            {QVector3D(0.5f, 0.5f, -0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(0.5f, -0.5f, -0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(0.0f, 1.0f)},

            {QVector3D(0.5f, -0.5f, -0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(0.0f, 1.0f)},
            {QVector3D(0.5f, -0.5f, 0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(1.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)},

            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(0.0f, 1.0f)},
            {QVector3D(0.5f, -0.5f, -0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(0.5f, -0.5f, 0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(1.0f, 0.0f)},

            {QVector3D(0.5f, -0.5f, 0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(1.0f, 0.0f)},
            {QVector3D(-0.5f, -0.5f, 0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(-0.5f, -0.5f, -0.5f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(0.0f, 1.0f)},

            {QVector3D(-0.5f, 0.5f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f, 1.0f)},
            {QVector3D(0.5f, 0.5f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 1.0f)},
            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 0.0f)},

            {QVector3D(0.5f, 0.5f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 0.0f)},
            {QVector3D(-0.5f, 0.5f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f, 0.0f)},
            {QVector3D(-0.5f, 0.5f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f, 1.0f)},

		};

		Mesh cubeMesh = Mesh(vertices);
		mesh = cubeMesh;
	}
};

class Plane : public Model {
public:
	Plane(std::string n) : Model(n) {
		std::vector<Vertex> vertices = {
			{QVector3D(0.5f, 0.0f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 1.0f)},
			{QVector3D(0.5f, 0.0f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-0.5f, 0.0f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0, 1.0f)},

			{QVector3D(0.5f, 0.0f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-0.5f, 0.0f, -0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(-0.5f, 0.0f, 0.5f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.0f, 1.0f)},
		};

		Mesh planeMesh = Mesh(vertices);
		
		mesh = planeMesh;
	}
};

class Triangle : public Model {
public:
	Triangle(std::string n) : Model(n) {
		std::vector<Vertex> vertices = {
			{QVector3D(-0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(0.0f, 0.5f, 0.0f), QVector3D(0.0f, 10.0f, 1.0f), QVector2D(0.5, 1.0f)},
		};

		Mesh triangleMesh = Mesh(vertices);

		mesh = triangleMesh;
	}
};

class Circle : public Model {
public:
	Circle(std::string n) : Model(n) {
		std::vector<Vertex> vertices;

		int o = 32;

		for (int s = 0; s < o; s += 1) {

			float t = qDegreesToRadians(s * (360.0f / o));

			float x = cos(t) * 0.5f;
			float z = sin(t) * 0.5f;

			vertices.push_back({QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.5f, 0.5f)});
			vertices.push_back({QVector3D(x, 0.0f, z), QVector3D(0.0f, 1.0f, 0.0), QVector2D(0.5f + x, 0.5f + z) });

			t = qDegreesToRadians((s + 1) * (360.0f / o));

			x = cos(t) * 0.5f;
			z = sin(t) * 0.5f;

			vertices.push_back({ QVector3D(x, 0.0f, z), QVector3D(0.0f, 1.0f, 0.0), QVector2D(0.5f + x, 0.5f + z) });			
		}

		Mesh circleMesh = Mesh(vertices);

		mesh = circleMesh;
	}
};

class Cylinder : public Model {
public:
	Cylinder(std::string n) : Model(n) {
		std::vector<Vertex> vertices;

		int h = 1.0;
		float y = h / 2.0f;

		int o = 32;


		for (int s = 0; s < o; s += 1) {

			float t0 = qDegreesToRadians(s * (360.0f / o));

			float x0 = cos(t0) * 0.5f;
			float z0 = sin(t0) * 0.5f;

			float t1 = qDegreesToRadians((s + 1) * (360.0f / o));

			float x1 = cos(t1) * 0.5f;
			float z1 = sin(t1) * 0.5f;

			// circle

			vertices.push_back({ QVector3D(0.0f, y, 0.0f), QVector3D(0.0f, 1.0f, 0.0f), QVector2D(0.5f, 0.5f) });
			vertices.push_back({ QVector3D(x0, y, z0), QVector3D(0.0f, 1.0f, 0.0), QVector2D(0.5f + x0, 0.5f + z0) });
			vertices.push_back({ QVector3D(x1, y, z1), QVector3D(0.0f, 1.0f, 0.0), QVector2D(0.5f + x1, 0.5f + z1) });

			vertices.push_back({ QVector3D(0.0f, -y, 0.0f), QVector3D(0.0f, -1.0f, 0.0f), QVector2D(0.5f, 0.5f) });
			vertices.push_back({ QVector3D(x0, -y, z0), QVector3D(0.0f, -1.0f, 0.0), QVector2D(0.5f + x0, 0.5f + z0) });
			vertices.push_back({ QVector3D(x1, -y, z1), QVector3D(0.0f, -1.0f, 0.0), QVector2D(0.5f + x1, 0.5f + z1) });

			float xn = (x0 + x1) / 2.0f;
			float zn = (z0 + z1) / 2.0f;

			vertices.push_back({ QVector3D(x0, y, z0), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + (s / o), 1.0f) });
			vertices.push_back({ QVector3D(x1, y, z1), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + ((s + 1) / o), 1.0f) });
			vertices.push_back({ QVector3D(x0, -y, z0), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + (s / o), 0.0f)});

			vertices.push_back({ QVector3D(x0, -y, z0), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + (s / o), 0.0f)});
			vertices.push_back({ QVector3D(x1, -y, z1), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + ((s + 1) / o), 0.0f)});
			vertices.push_back({ QVector3D(x1, y, z1), QVector3D(xn, 0.0f, zn), QVector2D(0.0f + ((s + 1) / o), 1.0f) });
		}

		Mesh cylinderMesh = Mesh(vertices);

		mesh = cylinderMesh;
	}
};

class Sphere : public Model {
public:
	Sphere(std::string n) : Model(n) {
		std::vector<Vertex> vertices;

		float stacks = 32;
		float slices = 32;

		float radius = 0.5f;

		for (int t = 0; t < stacks; t++) // stacks are ELEVATION so they count theta
		{
			float theta1 = (t / stacks) * M_PI;
			float theta2 = ((t + 1) / stacks) * M_PI;

			for (int p = 0; p < slices; p++) // slices are ORANGE SLICES so the count azimuth
			{
				float phi1 = ((p) / slices) * 2 * M_PI; // azimuth goes around 0 .. 2*PI
				float phi2 = ((p + 1) / slices) * 2 * M_PI;

				//phi2   phi1
				// |      |
				// 2------1 -- theta1
				// |\ _   |
				// |    \ |
				// 3------4 -- theta2
				//

				float x0 = radius * sin(theta1) * cos(phi1);
				float y0 = radius * sin(theta1) * sin(phi1);
				float z0 = radius * cos(theta1);

				float x1 = radius * sin(theta1) * cos(phi2);
				float y1 = radius * sin(theta1) * sin(phi2);
				float z1 = radius * cos(theta1);

				float x2 = radius * sin(theta2) * cos(phi2);
				float y2 = radius * sin(theta2) * sin(phi2);
				float z2 = radius * cos(theta2);

				float x3 = radius * sin(theta2) * cos(phi1);
				float y3 = radius * sin(theta2) * sin(phi1);
				float z3 = radius * cos(theta2);
				
				Vertex v0 = { QVector3D(x0, y0, z0), QVector3D(x0, y0, z0), QVector2D(0.0, 0.0) };
				Vertex v1 = { QVector3D(x1, y1, z1), QVector3D(x1, y1, z1), QVector2D(0.0, 0.0) };
				Vertex v2 = { QVector3D(x2, y2, z2), QVector3D(x2, y2, z2), QVector2D(0.0, 0.0) };
				Vertex v3 = { QVector3D(x3, y3, z3), QVector3D(x3, y3, z3), QVector2D(0.0, 0.0) };
				
				//vertex1 = vertex on a sphere of radius r at spherical coords theta1, phi1
				//vertex2 = vertex on a sphere of radius r at spherical coords theta1, phi2
				//vertex3 = vertex on a sphere of radius r at spherical coords theta2, phi2
				//vertex4 = vertex on a sphere of radius r at spherical coords theta2, phi1

				// facing out
				if (t == 0) {
					vertices.push_back(v0);
					vertices.push_back(v2);
					vertices.push_back(v3);
				} // top cap

				else if (t + 1 == stacks) {
					vertices.push_back(v2);
					vertices.push_back(v0);
					vertices.push_back(v1);
				} //end cap

				else
				{
					vertices.push_back(v0);
					vertices.push_back(v1);
					vertices.push_back(v3);

					vertices.push_back(v1);
					vertices.push_back(v2);
					vertices.push_back(v3);
				}
			}
		}

		Mesh sphereMesh = Mesh(vertices);

		mesh = sphereMesh;
	}
};

class OBJModel : public Model {
public:
	OBJModel(std::string path, std::string n) : Model(n) {
		std::vector<Vertex> vertices;
		
		std::string line;

		std::ifstream input_file(path);
		if (!input_file.is_open()) {
			std::cerr << "Could not open the file - '"
				<< path << "'" << std::endl;
			return;
		}

		std::vector<QVector3D> positions;

		std::vector<QVector3D> normals;

		std::vector<QVector2D> uvs;
		
		while (std::getline(input_file, line)) {
			char delim = ' ';
			std::vector<std::string> splits;

			std::string tmp;

			std::stringstream stream(line);
			while (std::getline(stream, tmp, delim)) {
				splits.push_back(tmp);
			}

			if (splits.at(0) == "v") {
				float vx = std::stof(splits.at(1));
				float vy = std::stof(splits.at(2));
				float vz = std::stof(splits.at(3));
				positions.push_back(QVector3D(vx, vy, vz));
			}

			else if (splits.at(0) == "vn") {
				float vnx = std::stof(splits.at(1));
				float vny = std::stof(splits.at(2));
				float vnz = std::stof(splits.at(3));
				normals.push_back(QVector3D(vnx, vny, vnz));
			}

			if (splits.at(0) == "vt") {
				float ux = std::stof(splits.at(1));
				float uy = std::stof(splits.at(2));
				uvs.push_back(QVector2D(ux, uy));
			}

			else if (splits.at(0) == "f") {
				for (int idx = 1; idx < 4; idx++) {
					std::vector<std::string> vertexSplits;
					delim = '/';
					std::string vertex_str = splits.at(idx);
					stream = std::stringstream(vertex_str);

					while (std::getline(stream, tmp, delim)) {
						vertexSplits.push_back(tmp);
					}

					int pi = std::stoi(vertexSplits.at(0)) - 1;
					int ui = std::stoi(vertexSplits.at(1)) - 1;
					int ni = std::stoi(vertexSplits.at(2)) - 1;

					QVector3D p = positions.at(pi );
					QVector3D n = normals.at(ni);
					QVector2D u = uvs.at(ui);

					Vertex v = { p, n, u };
					vertices.push_back(v);
				}
			}
		}

		input_file.close();

		Mesh objMesh = Mesh(vertices);

		mesh = objMesh;
	}
};


#endif