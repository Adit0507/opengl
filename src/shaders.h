#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;

    Shader(const char *vertexPath, const char *fragmentPath)
    {
        // retrievin vertex & fragment source code from filepath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std ::stringstream vShaderStream, fshaderStream;
            // readin files buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fshaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();

            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fshaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std:: cout << "Error: Shader File not successfully read" << std:: endl;
        }

        const char *vshaderCode = vertexCode.c_str();
        const char *fshaderCode = fragmentCode.c_str();
    };

    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif