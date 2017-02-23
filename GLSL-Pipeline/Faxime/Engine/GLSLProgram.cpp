#include "GLSLProgram.hpp"
#include <fstream>
#include <vector>

namespace Faxime::Engine
{
    GLSLProgram::GLSLProgram()
    {
        programID = 0;
        _vsID = 0;
        _fsID = 0;
        _numAttributes = 0;
    }

    GLSLProgram::~GLSLProgram()
    {
    }

    void GLSLProgram::compileShader(const std::string& shaderFilePath, GLuint id)
    {
        std::ifstream shaderFile(shaderFilePath);
        if (shaderFile.fail())
        {
            printf("Failed to open %s\n", shaderFilePath);
        }
        std::string fileContents = "";
        std::string line;

        while (std::getline(shaderFile, line))
        {
            fileContents += line + "\n";
        }

        shaderFile.close();
        //convert string para algo que funcione com a função em opengl
        const char* contentsPtr = fileContents.c_str();
        glShaderSource(id, 1, &contentsPtr, nullptr);
        //compile shader
        glCompileShader(id);
        //verify errors
        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, (int*)&success);
        if (success == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
            //the maxLength includes the null character
            std::vector<char> errorLog(maxLength);
            glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

            //exit the failure
            glDeleteShader(id);
            printf("%s\n", &(errorLog[0]));
            printf("shader failed to compile\n");
        }
    }

    void GLSLProgram::CompileShaders(const std::string& vertexFile, const std::string& fragmentFile)
    {
        programID = glCreateProgram();

        _vsID = glCreateShader(GL_VERTEX_SHADER);
        if (_vsID == 0)
        {
            printf("Vertex shader fail\n");
        }
        _fsID = glCreateShader(GL_FRAGMENT_SHADER);
        if (_fsID == 0)
        {
            printf("Frag shader fail\n");
        }
        //compile shaders
        compileShader(vertexFile, _vsID);
        compileShader(fragmentFile, _fsID);
    }

    void GLSLProgram::LinkShaders()
    {
        //attach shaders to program
        glAttachShader(programID, _vsID);
        glAttachShader(programID, _fsID);

        //link program
        glLinkProgram(programID);
        //verify errors
        GLint isLinked = 0;
        glGetProgramiv(programID, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(programID, maxLength, &maxLength, &infoLog[0]);

            printf("%s\n", &(infoLog[0]));
            printf("program failed to compile\n");

            //delete program
            glDeleteProgram(programID);
            //delete shaders
            glDeleteShader(_vsID);
            glDeleteShader(_fsID);
        }
        //ddetach e delete shaders
        glDetachShader(programID, _vsID);
        glDetachShader(programID, _fsID);
        glDeleteShader(_vsID);
        glDeleteShader(_fsID);
    }

    void GLSLProgram::AddAttribute(const std::string& attributeName)
    {
        glBindAttribLocation(programID, _numAttributes++, attributeName.c_str());
    }

    void GLSLProgram::Use()
    {
        glUseProgram(programID);

        for (int i = 0; i<_numAttributes; i++)
        {
            glEnableVertexAttribArray(i);
        }
    }

    void GLSLProgram::Unuse()
    {
        for (int i = 0; i<_numAttributes; i++)
        {
            glDisableVertexAttribArray(i);
        }
        glUseProgram(0);
    }

    GLint GLSLProgram::GetUniformLocation(const std::string&uniformName) const
    {
        GLint location = glGetUniformLocation(programID, uniformName.c_str());

        if (location == GL_INVALID_INDEX) {
            printf("uniform %s dies bit exist", uniformName.c_str());
        }

        return location;
    }
}
