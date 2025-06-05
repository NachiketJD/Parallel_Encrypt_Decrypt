#include<bits/stdc++.h>
#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../filehandling/ReadEnv.cpp"

int executeCryption( const std::string &TaskData ){
    Task task = Task::fromString(TaskData);
    ReadEnv env;

    std:: string envKey = env.getenv();
    int key = std::stoi(envKey);

    if(task.action == Action::ENCRYPT){
        char ch;
        while(task.f_stream.get(ch)){
            ch = (ch+key)%256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }else{
        char ch;
        while(task.f_stream.get(ch)){
            ch = (ch-key)%256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }

    return 0;

}