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

m_WADFile.open(m_sWADFilePath, ifstream::binary);
if (!m_WADFile.is_open())
{
    cout << "Error: Failed to open WAD file" << m_sWADFilePath << endl;
    return false;
}