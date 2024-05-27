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

    std::ifstream file;
    std::string filename = "../myshader.vs";
    file.open( filename.c_str() );
    if ( ! file )
    {
        std::cout << "could not open " << filename << std::endl;
    }

    std::string line; // Declare a string variable to store each 
    // line of the file 

    // Read each line of the file and print it to the 
    // standard output stream 
    std::cout << "File Content: " << std::endl; 
    while ( std::getline(file, line) ) { 
        std::cout << line << std::endl; // Print the current line 
    } 

    // Close the file 
    file.close(); 
    file.clear();

    std::string vertexCode;
    std::ifstream vShaderFile;

    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    vShaderFile.open( filename.c_str() );
    std::stringstream vShaderStream;
    // read file's buffer contents into streams
    vShaderStream << vShaderFile.rdbuf();
    // close file handlers
    vShaderFile.close();
    // convert stream into string
    vertexCode   = vShaderStream.str();

    int kkk = 1;


    return 0;
}