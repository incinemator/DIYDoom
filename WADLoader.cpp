#include "WADLoader.h"
#include <iostream>
#include "WADReader.h"

using namespace std;


class WADLoader
{
public:
    WADLoader(std::string sWADFilePath); // We always want to make sure a WAD file is passed
    bool LoadWAD(); // Will call other helper functions to open and load the WAD file

    ~WADLoader();   // Clean up!

protected:
    bool OpenAndLoad();     // Open the file and load it to memory
    bool ReadDirectories(); // A function what will iterate though the directory section 

    std::string m_sWADFilePath; // Store the file name passed to the constructor 
    std::ifstream m_WADFile;    // The file stream that will pint to the WAD file.
    uint8_t *m_WADData;         // let's load the file and keep it in memory! It is just a few MBs!
    std::vector<Directory> m_WADDirectories; //let's store all the directories in this vector.
};

WADLoader::WADLoader(string sWADFilePath) : m_WADData(NULL), m_sWADFilePath(sWADFilePath)
{
}

bool WADLoader::OpenAndLoad()
{
    m_WADFile.open(m_sWADFilePath, ifstream::binary);
    if (!m_WADFile.is_open())
    {
        cout << "Error: Failed to open WAD file" << m_sWADFilePath << endl;
        return false;
    }

    m_WADFile.seekg(0, m_WADFile.end);
    size_t length = m_WADFile.tellg();

    m_WADData = new uint8_t[length];

    // remember to know the file size we had to move the file pointer all the way to the end! We need to move it back to the beginning.
    m_WADFile.seekg(ifstream::beg);
    m_WADFile.read((char *)m_WADData, length); // read the file and place it in m_WADData

    m_WADFile.close();
}




bool WADLoader::LoadWAD()
{
    if (!OpenAndLoad())
    {
        return false;
    }

    return true;
}

int main()
{
    WADLoader wadloader("..\\..\\..\\external\\assets\\DOOM.WAD");
    wadloader.LoadWAD();
    return 0;
}