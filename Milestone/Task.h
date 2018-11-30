// Task.h
// A Task object manages a single Item on the assembly line
// Task inherits from class Item and contains the following additional information:
// 
// m_orders – is a double ended queue with new CustomerOrders coming in one side and exiting out the other once filled.
// m_pNextTask – a pointer to the next task on the assembly line
// A Task object represents a single location on the assembly line for filling items into customer orders. 
// Therefore, a Task object cannot be copied or moved. 
// You must make sure this capability has been deleted from your Task definition.

#ifndef _TASK_H
#define _TASK_H

#include <deque>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "Item.h"

class Task : public Item
{
    // m_orders – is a double ended queue with new CustomerOrders coming in one side and exiting out the other once filled.
    std::deque<CustomerOrder> m_orders;
    Task *m_pNextTask;
public:
    Task(const std::string&);
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    Task(Task&&) = delete;
    Task& operator=(Task&&) = delete;

    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    
    Task& operator+=(CustomerOrder&&);
};
#endif // ! _TASK_H