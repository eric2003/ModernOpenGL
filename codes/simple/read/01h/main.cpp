#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

void ReadShader( const char * vertexPath )
{
    std::string vertexCode;
    std::ifstream vShaderFile;

    try
    {
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

        //vShaderFile.open( filename.c_str() );
        vShaderFile.open( vertexPath );
        std::stringstream vShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();

        std::cout << "vertexCode=\n" << vertexCode << "\n";

        int kkk = 1;
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }
}

void ReadMyShader( const char * vertexPath, const char* fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try 
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();

        std::cout << "------------------------------------\n";
        std::cout << "\n";
        std::cout << "vertexCode=\n" << vertexCode << "\n";
        std::cout << "\n";
        std::cout << "------------------------------------\n";
        std::cout << "\n";
        std::cout << "fragmentCode=\n" << fragmentCode << "\n";
        std::cout << "\n";
        std::cout << "------------------------------------\n";
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }
}

int main()
{
    std::string filename_vs = "../myshader.vs";
    std::string filename_fs = "../myshader.fs";

    ReadShader( filename_vs.c_str() );
    ReadShader( filename_fs.c_str() );

    ReadMyShader( filename_vs.c_str(), filename_fs.c_str() );

    return 0;
}