#pragma once

#include "GLEW/glew.h"

#include <string>

namespace Faxime::Engine
{
    class GLSLProgram
    {
    public:
        GLSLProgram();
        ~GLSLProgram();

#pragma region Public Instance Methods

        void CompileShaders(const std::string& vertexFile, const std::string& fragmentFile);
        
        void LinkShaders();
        
        void AddAttribute(const std::string& attributeName);
        
        void Use();
        
        void Unuse();
        
        GLint GetUniformLocation(const std::string& uniformName) const;

#pragma endregion 

    private:
        //vars
        int _numAttributes;
        GLuint programID, _vsID, _fsID;

        void compileShader(const std::string& shaderFilePath, GLuint id);
    };
}