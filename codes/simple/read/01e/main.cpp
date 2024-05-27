#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

int main()
{
    //std::filesystem::path currentPath = std::filesystem::current_path();
    //std::cout << "Current Path: " << currentPath << std::endl;

    //std::filesystem::path targetPath("d:/work/opengl_work_2024/ModernOpenGL/codes/simple/read/01/myshader.vs");
    //std::filesystem::path relativePath = std::filesystem::relative(targetPath, currentPath);
    //std::cout << relativePath << std::endl;

    std::string filename = "../myshader.vs";

    std::string vertexCode;
    std::ifstream vShaderFile;

    try
    {
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

        vShaderFile.open( filename.c_str() );
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


    return 0;
}