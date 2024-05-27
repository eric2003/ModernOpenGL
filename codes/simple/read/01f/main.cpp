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

int main()
{
    std::string filename = "../myshader.vs";

    ReadShader( filename.c_str() );

    return 0;
}