#include <iostream>
#include <vector>

// Task structure to store task details
struct Task {
    std::string description;
    bool completed;
};

// Function to display the to-do list
void displayToDoList(const std::vector<Task>& toDoList) {
    if (toDoList.empty()) {
        std::cout << "No tasks in the to-do list.\n";
    } else {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < toDoList.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (toDoList[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << toDoList[i].description << '\n';
        }
    }
}

// Function to add a task to the to-do list
void addTask(std::vector<Task>& toDoList, const std::string& description) {
    Task newTask = {description, false};
    toDoList.push_back(newTask);
    std::cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void completeTask(std::vector<Task>& toDoList, size_t index) {
    if (index >= 0 && index < toDoList.size()) {
        toDoList[index].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

// Function to delete a task from the to-do list
void deleteTask(std::vector<Task>& toDoList, size_t index) {
    if (index >= 0 && index < toDoList.size()) {
        toDoList.erase(toDoList.begin() + index);
        std::cout << "Task deleted successfully.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main() {
    std::vector<Task> toDoList;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. View To-Do List\n";
        std::cout << "2. Add Task\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayToDoList(toDoList);
                break;
            case 2:
                {
                    std::string taskDescription;
                    std::cout << "Enter task description: ";
                    std::cin.ignore(); // Ignore newline character left in the buffer
                    std::getline(std::cin, taskDescription);
                    addTask(toDoList, taskDescription);
                }
                break;
            case 3:
                {
                    size_t taskIndex;
                    std::cout << "Enter task index to mark as completed: ";
                    std::cin >> taskIndex;
                    completeTask(toDoList, taskIndex - 1); // Subtract 1 to convert to zero-based index
                }
                break;
            case 4:
                {
                    size_t taskIndex;
                    std::cout << "Enter task index to delete: ";
                    std::cin >> taskIndex;
                    deleteTask(toDoList, taskIndex - 1); // Subtract 1 to convert to zero-based index
                }
                break;
            case 5:
                std::cout << "Exiting the to-do list manager.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
