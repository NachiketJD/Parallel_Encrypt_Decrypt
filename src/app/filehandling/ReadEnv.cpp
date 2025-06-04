#include<bits/stdc++.h>
#include"IO.hpp"

class ReadEnv
{

public:
    std::string getenv(){
        std:: string env_path=".env";
        IO io(env_path);
        std::fstream f_stream =  io.getFileStream(); // Filestream jo open ki hai vo return karega
        std:: stringstream buffer;
        buffer << f_stream.rdbuf();
        std::string content = buffer.str();
        return content;
    }
};

