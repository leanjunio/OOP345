// Name: Len Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 12/1/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Task.h"

// Receive a single record (one line) from the input file for Item instantiation
// Set m_pNextTask to empty state
// 
Task::Task(const std::string& record)
    : Item(record),
      m_pNextTask(nullptr)
{
}

// Runs a single cycle of the assembly line for the current task
// If there are CustomerOrders in the queue, it will verify the status of the last CustomerOrder and fill it
// if the order contains the Item specified by the current Task
// 
void Task::runProcess(std::ostream& os)
{
    if (!m_orders.empty())
    {
        if (!m_orders.front().getOrderFillState())
        {
            while (!m_orders.front().getItemFillState(getName()))
            {
                if (!this->getQuantity())
                    throw std::string("ERROR: [") + getName() + " of stock UNAVAILABLE]";
                m_orders.front().fillItem(*this, os);
            }
        }
    }
}

// Moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill state for the current Item is true
// 
bool Task::moveTask()
{
    if (!m_orders.empty())
    {
        if (m_pNextTask)
        {
            if (m_orders.front().getItemFillState(getName()))
            {
                *m_pNextTask += std::move(m_orders.front());
                m_orders.pop_front();
            }
        }

        return true;
    }
    else
        return false;
}   

// Store the provided task's reference into the m_pNextTask pointer
// 
void Task::setNextTask(Task& task)
{
    m_pNextTask = &task;
}

// Removes the last CustomerOrder from the queue, places it in the parameter and returns true
// If the queue is empty, return false
// 
bool Task::getCompleted(CustomerOrder& co)
{
    if (!m_orders.empty() && m_orders.front().getOrderFillState()) 
    {
        co = std::move(m_orders.front());
        m_orders.pop_front();
        return true;
    } 
    else 
        return false;
}

// Writes the name of the Item the current Task is responsible for into the parameter
// 
void Task::validate(std::ostream& os)
{
    os << getName() << " --> ";
    os << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE");
    os << std::endl;
}

// Moves the parameter onto the front of the CustomerOrder queue
// 
Task& Task::operator+=(CustomerOrder&& co)
{
    m_orders.push_back(std::move(co));
    return *this;
}