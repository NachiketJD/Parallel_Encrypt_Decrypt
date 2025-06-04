#ifndef TASK_HPP
#define TASK_HPP

#include<bits/stdc++.h>
#include"../filehandling/IO.hpp"

enum class Action{
    ENCRYPT,
    DECRYPT,
};

struct Task{
    std::string filePath;
    std:: fstream f_stream;
    Action action;

    Task(std::fstream &&stream, Action act, std::string filepath){
        f_stream = std::move(stream);
        action = act;;
        filePath = filepath;
    } //&& no alag se copy banegi// TASK CONSRTUCTOR

    std::string toString(){
        std::ostringstream oss;
        oss<<filePath<<","<<(action==Action::ENCRYPT? "ENCRYPT": " DECRYPT");
        return oss.str();
    }
    //agar mera koi test.txt file ko encry karna hai,
    //  uska ek task bana hua hoga by task struct jisme
    //  file path, action, file stream hoga
    //   IO se us file ko khol ke launga uski yaha pe filestream store hogi
    // Sabse pehle vo ek stream banayega, usme filePath ko push karega, folleowed by a comma
    //  and then action (ency/decry)

    static Task fromString(const std::string &taskData){
        std::istringstream iss(taskData);
        std::string filePath , actionStr;

        if(std::getline(iss, filePath, ',') && std:: getline(iss, actionStr)){
            Action action = (actionStr == "ENCRYPT")? Action::ENCRYPT : Action::DECRYPT;
            IO io(filePath);
            std::fstream f_stream = std:: move(io.getFileStream());
            if(f_stream.is_open()){
                return Task (std::move(f_stream), action, filePath);
            }else{
                throw std ::runtime_error("File not found " + filePath);
            }
        }
        else{
            throw std:: runtime_error("Invalid task data format");
        }
    }


};

#endif