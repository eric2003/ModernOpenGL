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

    std::fstream file;
    file.open( "../myshader.vs", std::ios_base::in );
    if ( ! file )
    {
        std::cout << "could not open " << "../myshader.vs" << std::endl;
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

    return 0;
}