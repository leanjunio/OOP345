#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager
{
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
public:
    LineManager(const std::string&, std::vector<Task*>, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;
};

#endif // !_LINEMANAGER_H