#ifndef SHADER_H
#define SHADER_H

#include "../common.h"
#include "material.h"

class Shader : protected QOpenGLExtraFunctions {
public:
    QFileInfo vertexPath{};
    QFileInfo fragmentPath{};

    Shader() {
        initializeOpenGLFunctions();
    }

    Shader(const Shader& s) {
        vertexPath = s.vertexPath;
        fragmentPath = s.fragmentPath;
        load();
    }

    Shader(const char* vPath, const char* fPath) {
        vertexPath = QFileInfo(vPath);
        fragmentPath = QFileInfo(fPath);
        load();
    }

    Shader& operator=(Shader const& m) {
        vertexPath = m.vertexPath;
        fragmentPath = m.fragmentPath;
        id = m.id;

        return *this;
    };

    void load() {
        initializeOpenGLFunctions();

        qDebug() << "SHADER::LOADING_VERTEX_PATH:: " << vertexPath.absoluteFilePath().toStdString().c_str();
        qDebug() << "SHADER::LOADING_FRAGMENT_PATH:: " << fragmentPath.absoluteFilePath().toStdString().c_str();

        std::string vertexCode;
        std::string fragmentCode;

        try {

            QFile vShaderFile(vertexPath.absoluteFilePath());
            if (!vShaderFile.open(QFile::ReadOnly | QFile::Text)) throw std::ifstream::failure{ "" };
            QTextStream vStream(&vShaderFile);

            vertexCode = vStream.readAll().toStdString();


            QFile fShaderFile(fragmentPath.absoluteFilePath());
            if (!fShaderFile.open(QFile::ReadOnly | QFile::Text)) throw std::ifstream::failure{ "" };
            QTextStream fStream(&fShaderFile);

            fragmentCode = fStream.readAll().toStdString();

            vShaderFile.close();
            fShaderFile.close();

        }
        catch (std::ifstream::failure e)
        {
            qDebug() << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ";

        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

        unsigned int vertex, fragment;
        int success;
        char infoLog[512];

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);

        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
        }

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
        }

        id = glCreateProgram();
        glAttachShader(id, vertex);
        glAttachShader(id, fragment);
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void use() {
        glUseProgram(id);
    };

    void setBool(const std::string& name, bool value) {
        glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
    };
    void setInt(const std::string& name, int value) {
        glUniform1i(glGetUniformLocation(id, name.c_str()), value);
    };
    void setFloat(const std::string& name, float value) {
        glUniform1f(glGetUniformLocation(id, name.c_str()), value);
    };
    void setVec3(const std::string& name, QVector3D value) {
        glUniform3f(glGetUniformLocation(id, name.c_str()), value.x(), value.y(), value.z());
    };
    void setColor(const std::string& name, QColor value) {
        glUniform3f(glGetUniformLocation(id, name.c_str()), value.red() / 255.0f, value.green() / 255.0f, value.blue() / 255.0f);
    };
    void setMat4(const std::string& name, QMatrix4x4 value) {
        glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, value.constData());
    };
    void setMaterial(Material material) {
        setColor("material.color", material.color);
        setFloat("material.roughness", material.roughness);
    }

private:
    unsigned int id{};
};

#endif // !SHADER_H