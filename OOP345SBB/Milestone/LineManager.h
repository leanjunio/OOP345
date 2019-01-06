// Name: Len Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 12/1/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

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
    size_t pos_first;
    size_t pos_last;
public:
    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;
};

#endif // !_LINEMANAGER_H