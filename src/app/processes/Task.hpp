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
};

#endif