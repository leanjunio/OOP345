// Name: Len Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 12/1/2018
//
// I confirm that I am the only author of this file
// Name: Len Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 12/1/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& co_tobefilled) 
{
    std::ifstream file(fileName);
    
    Utilities localUtility;
    size_t next_pos = 0;
    bool more = true;

    std::string record;
    std::string task;
    std::string next;

    bool checkIfFirst = true;

    while(!file.eof()) 
    {
        std::getline(file, record);

        // Get the current task an the next task
        task = localUtility.extractToken(record, next_pos, more);
        if (more)
            next = localUtility.extractToken(record, next_pos, more);

        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            if (tasks[i]->getName() == task) 
            {
                if (checkIfFirst) 
                {
                    pos_first = i;
                    checkIfFirst = !checkIfFirst;
                }
                
                if (!next.empty()) 
                {
                    for (size_t j = 0; j < tasks.size(); ++j) 
                    {
                        if (tasks[j]->getName() == next) 
                        {
                            tasks[i]->setNextTask(*tasks[j]);
                            break;
                        }
                    }
                } 
                else
                    pos_last = i;
                break;
            }
        }
        
        next_pos = 0;
        more = true;
        task.clear();
        next.clear();
    }

    for (size_t i = 0; i < co_tobefilled.size(); ++i) 
        ToBeFilled.push_back(std::move(co_tobefilled[i]));
    co_tobefilled.erase(co_tobefilled.begin(),co_tobefilled.end());
    AssemblyLine = tasks;
}

bool LineManager::run(std::ostream& os) 
{
    bool done = true;
    
    if (!ToBeFilled.empty()) 
    {
        *AssemblyLine[pos_first] += std::move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    for (size_t i = 0; i < AssemblyLine.size(); ++i) 
    {
        try 
        {
            AssemblyLine[i]->runProcess(os);
        }
        catch (std::string err) 
        {
            std::cout << std::endl << err << std::endl;
            throw std::string("Not enough inventory available");
        }
    }

    CustomerOrder buffer;
    if (AssemblyLine[pos_last]->getCompleted(buffer))
        Completed.push_back(std::move(buffer));

    for (size_t i = 0; i < AssemblyLine.size(); ++i) 
    {
        if (AssemblyLine[i]->moveTask()) 
            done = false; 
    }

    return done;
}

void LineManager::displayCompleted(std::ostream& os) const 
{
    if (!Completed.empty())
        for (size_t i = 0; i < Completed.size(); ++i) 
            Completed[i].display(os);
}

void LineManager::validateTasks() const 
{
    if (!AssemblyLine.empty())
        for (size_t i = 0; i < AssemblyLine.size(); ++i)
            AssemblyLine[i]->validate(std::cout);
}