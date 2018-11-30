#include <fstream>
#include "LineManager.h"

// str - contains the filename specified by the user to be used for linking the assembly line objects (ex. AssemblyLine.dat)
// al_addresses - A reference containing the addresses of all the Task objects created for the assembly line
// co_tobefilled - A reference containing all the CustomerOrders to be filled
// 
// This constructor must read the records from the file
// Setup all the m_pNextTask references in the Task objects, Linking each Task object together to form the assembly line
// Move all the CustomerOrder objects onto the front of the ToBeFilled queue
// Copy all the Task objects into the AssemblyLine container
// 
LineManager::LineManager(const std::string& str, std::vector<Task*> al_addresses, std::vector<CustomerOrder>& co_tobefilled)
{
    std::ifstream file(str, std::ifstream::in);

    if (file.is_open())
    {
        m_cntCustomerOrder = co_tobefilled.size();  // get the CustomerOrder count
        for (size_t i = 0; i < m_cntCustomerOrder; ++i)
            
    }
}

// Performs one cycle of operations on the assembly line
// If there are any CustomerOrder objects in the ToBeFilled queue, move the last CustomerOrder object onto the starting point of the assembly line
// Loop through all tasks on the asembly line and run one cycle of the task's process
// Loop through all the tasks on the assembly line and move the CustomerOrder object down the line
// Completed orders should be move to the Completed queue
// Return true if all customer orders have been filled, otherwise return false
// 
bool LineManager::run(std::ostream& os)
{

}

// Displays all the orders that were completed
// 
void LineManager::displayCompleted(std::ostream&) const
{

}

// Validates each task on the assembly line
// 
void LineManager::validateTasks() const
{

}